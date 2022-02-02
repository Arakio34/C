#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include <stdint.h>
#include <mosquitto.h>
#include <string.h>
#include <signal.h>
// gcc -Wall -lwiringPi -lmosquitto


uint16_t dig_T1 = 0; 
int16_t dig_T2 = 0;
int16_t dig_T3 = 0;
uint16_t dig_P1 = 0; 
int16_t dig_P2,dig_P3,dig_P4,dig_P5,dig_P6,dig_P7,dig_P8,dig_P9 = 0; 
unsigned char dig_H1 = 0; 
int16_t dig_H2 = 0; 
unsigned char dig_H3 = 0; 
int16_t dig_H4 = 0; 
int16_t dig_H5 = 0; 
char dig_H6 = 0; 
int addresse = 0x77;
double var1 = 0;
double var2 = 0;
double var_H =0;
double t_fine= 0;
uint32_t adc_T=0;
uint32_t adc_P=0;
uint16_t adc_H=0;
double T = 0;
double P = 0;
double H = 0;
int fd;
uint16_t data[3];
float pres;
float temp;
float humi;
int state;
char messageP[10];
char messageT[10];
char messageH[10];
struct mosquitto *mosqa;
int rep = 0;
int pinServ = 21;
int red = 0;
int green =2;
int blue = 3;
int r,g,b = 0;
int i = 5;
int test = 0;


// Calcule la température et retourne sa valeur
double calcTemp(){
	var1 =(((double)adc_T/16384.0)-((double)dig_T1/1024))*dig_T2;
	var2 =((((double)adc_T/131072.0)-((double)dig_T1/8192.0))*(((double)adc_T)/131072-((double)dig_T1)/8192.0))*((double)dig_T3);	
	t_fine=var1+var2;
	T = (var1 + var2)/5120.0;
	return T;
}

double calcHumi(){

	var_H = ((double)t_fine -76800.0);
	var_H = (adc_H - (((double)dig_H4)*64.0 + ((double)dig_H5) /16384.0 *var_H))*(((double)dig_H2)/65536.0 *  (1.0+ ((double)dig_H6)/67108864.0 * var_H *(1.0 + ((double)dig_H3)/ 67108864.0 * var_H)));
	var_H = var_H*(1.0-((double)dig_H1)*var_H /524288.0);
	
	if (var_H > 100.0){
		var_H = 100.0;
	}
	else if (var_H < 0.0){
		var_H = 0.0;
	} 
	//printf("var_H : %f \n",var_H);	
	return var_H;
}


// Calcule la pression et retourne sa valeur
double calcPression(){
	var1 = ((double)t_fine/2.0)-64000.0;
	var2 = var1*var1*((double)dig_P6)/32768.0;
	var2 = var2+var1*((double)dig_P5)*2.0;
	var2 =(var2/4.0)+(((double)dig_P4)*65536.0);
	var1 =(((double)dig_P3)*var1*var1/524288.0+((double)dig_P2)*var1)/524288.0;
	var1 =(1.0+var1/32768.0)*((double)dig_P1);
	P = 1048576.0 -(double)adc_P;
	P = (P-(var2/4096.0))*6250.0/var1;
	var1 =((double)dig_P9)*P*P/2147483648.0;
	var2 =P*((double)dig_P8)/32768.0;
	P = P+(var1+var2+((double)dig_P7))/16.0;
	return P;	
}

// Récupére les valeur d'ajustement de la température / pression / humiditer

void initRegister(int fd){
	dig_T1 = wiringPiI2CReadReg16(fd,0x88);
	dig_T2 = wiringPiI2CReadReg16(fd,0x8a);
	dig_T3 =wiringPiI2CReadReg16(fd,0x8c);
	dig_P1 = wiringPiI2CReadReg16(fd,0x8e);
	dig_P2 = wiringPiI2CReadReg16(fd,0x90);
	dig_P3 = wiringPiI2CReadReg16(fd,0x92);
	dig_P4 = wiringPiI2CReadReg16(fd,0x94);
	dig_P5 = wiringPiI2CReadReg16(fd,0x96);
	dig_P6 = wiringPiI2CReadReg16(fd,0x98);
	dig_P7 = wiringPiI2CReadReg16(fd,0x9a);
	dig_P8 = wiringPiI2CReadReg16(fd,0x9c);
	dig_P9 = wiringPiI2CReadReg16(fd,0x9e);
	dig_H1 = wiringPiI2CReadReg8(fd,0xa1); 
	dig_H2 = wiringPiI2CReadReg16(fd,0xe1);
	dig_H3 = wiringPiI2CReadReg8(fd,0xe3); 
	int8_t dig_H4_lsb = wiringPiI2CReadReg8(fd,0xe5)-((wiringPiI2CReadReg8(fd,0xe5)>>4)<<4); 
	int16_t dig_H4_msb = wiringPiI2CReadReg8(fd,0xe4)<<4;
	//printf("H4 msb : %d H4 lsb : %d \n",dig_H4_msb,dig_H4_lsb );	
	dig_H4 = dig_H4_lsb + dig_H4_msb;
	int8_t dig_H5_lsb = wiringPiI2CReadReg8(fd,0xe5)>>4; 
	int16_t dig_H5_msb = wiringPiI2CReadReg8(fd,0xe6)<<4;
	//printf("H5 msb : %d H5 lsb : %d \n",dig_H5_msb,dig_H5_lsb );	
	dig_H5 = dig_H5_msb + dig_H5_lsb; 
	dig_H6 = wiringPiI2CReadReg16(fd,0xe7); 
	//printf("H1 %d H2 %d H3 %d H4 %d H5 %d H6 %d \n", dig_H1,dig_H2,dig_H3,dig_H4,dig_H5,dig_H6);

}

//Récupére les valeurs brutes du capteur
void getValue(int fd){

	wiringPiI2CWriteReg8(fd,0xf4,0x25);
	wiringPiI2CWriteReg8(fd,0xf2,0x02);
	data[0] = wiringPiI2CReadReg8(fd,0xf7);
	data[1] = wiringPiI2CReadReg8(fd,0xf8);
	data[2] = wiringPiI2CReadReg8(fd,0xf9);
	adc_P =((data[0]<<12)+(data[1]<<4)+(data[2]));
	//printf("pression : %d\n",adc_P);
	//printf("data : MSB %d  LSB %d XLSB %d\n",data[0],data[1],data[2]);
	data[0] = wiringPiI2CReadReg8(fd,0xfa);
	data[1] = wiringPiI2CReadReg8(fd,0xfb);
	data[2] = wiringPiI2CReadReg8(fd,0xfc);
	adc_T =((data[0]*4096)+(data[1]*16)+(data[2]));
	//printf("Temperature : %d\n",adc_T);
	//printf("data : MSB %f  LSB %f XLSB %f\n",data[0],data[1],data[2]);
	uint8_t adc_H_lsb = wiringPiI2CReadReg8(fd,0xfe);
	uint16_t adc_H_msb = wiringPiI2CReadReg8(fd,0xfd)<<8;
	//printf("adc H msb: %d adc H lsb: %d\n",adc_H_msb, adc_H_lsb);
	adc_H = adc_H_msb +adc_H_lsb;
	//printf(" adc_H : %d\n", adc_H);

}
// Envoie des données au BROKER
void sendData(){
	int vali=0;
	float valf=0;
	float test=0;
	//Envoie et mise en forme de la pression
	gcvt(pres,8,messageP); // Convertis la vvaleur en une chaine de caractère
	vali = atoi(messageP); // Retransforme la chaine de caractère en un entier
	valf = atof(messageP); // De même mais en valeur avec virgule
	test = vali-valf; // Ce test permet de savoir si on a une valeur ronde comme "29°C" par exemple.Nous effectuons ce test car lors de l'envoie des donnéesnous avons remarquer que les valeur ronde était génante par exemple 29 seras percus comme 29000. 
	if(test== 0){
		strcat(messageP,".0");
	//	printf("%s\n",messageP);
	}
	strcat(messageP,"\0"); // On ajoute un \0 Afin de spécifier à la fin de notre chaine de caractère
	//printf("%s\n",messageP); 
	mosquitto_publish(mosqa, NULL, "mesure/iut/pres", 7, messageP, 0, false); // On publie sur le sujet mesure/iut/pres
	
	//Envoie  et mise en forme de la temperature 
	gcvt(temp,6,messageT);
	vali = atoi(messageT);
	valf = atof(messageT);
	test = vali-valf;
	if(test== 0){
		strcat(messageT,".0");
	//	printf("%s\n",messageT);
	}
	strcat(messageT,"\0");
	//printf("%s\n",messageT);
	mosquitto_publish(mosqa, NULL, "mesure/iut/temp",6, messageT, 0, false);
	
	// Envoie et mise en forme de l'humiditer
	gcvt(humi,4,messageH);
	vali = atoi(messageH);
	valf = atof(messageH);
	test = vali-valf;
	if(test== 0){
		strcat(messageH,".0");
	//	printf("%s\n",messageH);
	}
	strcat(messageH,"\0");
	//printf("%s\n",messageH);
	mosquitto_publish(mosqa, NULL, "mesure/iut/humi",4, messageH, 0, false);
}

void Last_Will(int singal){
	printf("\nFin de la connexion \n");
	mosquitto_publish(mosqa, NULL, "state/log",20, "Fin de connexion", 0, false);
	mosquitto_will_clear(mosqa);
	mosquitto_disconnect(mosqa);
	mosquitto_destroy(mosqa);
	mosquitto_lib_cleanup();
	exit(0);
}

int main(){
	signal(SIGINT,&Last_Will);
	// On crée la initialise la liaisons MQTT	
	mosquitto_lib_init();
	
	mosqa = mosquitto_new("test",true,NULL);
	mosquitto_username_pw_set(mosqa, "tom", "22011648");
	mosquitto_tls_set(mosqa,"/etc/mosquitto/certs/ca_certificats/ca.crt",NULL,"/etc/mosquitto/certs/client/clientPi.crt","/etc/mosquitto/certs/client/clientPi.key",NULL);
	mosquitto_tls_opts_set(mosqa,1,NULL,NULL);
	mosquitto_tls_insecure_set(mosqa,true);
	state = mosquitto_connect(mosqa,"194.199.227.235",1139,60); // Cette version est utiliser lorsque l'on ce trouve a l'exterieur de l'IUT
	//state = mosquitto_connect(mosqa,"172.42.50.139",1883,60); // Cette version est utiliser lorsque l'on ce trouve dans l'IUT
	mosquitto_publish(mosqa, NULL, "state/log",20, "Début de connexion", 0, false);
	mosquitto_will_set(mosqa,"state/LW",12,"Adieu",0,false);
	
	if(state == -1){
		printf("Conexion refuser !\n");	
	}
	
	wiringPiSetup();	
	
	//wiringPiI2CWriteReg8(fd,0xe0,0xb6);
	fd=wiringPiI2CSetup(addresse);	
	
	for(;;){
		if(rep !=0){
			initRegister(fd);	
			getValue(fd);		
			pres = calcPression()/100;
			temp = calcTemp();
			humi = calcHumi();
			sendData();
			printf("Température : %f °C Pression : %f hPa  Humidité : %f %s \n",temp,pres,humi,"%");
			delay(1000);
		}
		else{ 
			delay(1000);
			initRegister(fd);	
			getValue(fd);		
			pres = calcPression()/100;
			temp = calcTemp();
			humi = calcHumi();
			rep++;
			continue;
		}
	}
	return 0;
}
