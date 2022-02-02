#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdint.h>
#include <mosquitto.h>
#include <string.h>
// gcc -Wall -lwiringPi 


uint16_t dig_T1 = 0; 
int16_t dig_T2 = 0;
int16_t dig_T3 = 0;
uint16_t dig_P1 = 0; 
int16_t dig_P2 = 0; 
int16_t dig_P3 = 0; 
int16_t dig_P4 = 0; 
int16_t dig_P5 = 0; 
int16_t dig_P6 = 0; 
int16_t dig_P7 = 0; 
int16_t dig_P8 = 0; 
int16_t dig_P9 = 0; 
int addresse = 0x77;
double var1 = 0;
double var2 = 0;
double t_fine= 0;
uint32_t adc_T=0;
uint32_t adc_P=0;
double T = 0;
double P = 0;
int fd;
float data[3];
float pres;
float temp;
int state;
char messageP[10];
char messageT[10];
struct mosquitto *mosqa;


// Calcule la température et retourne sa valeur
double calcTemp(){
	var1 =(((double)adc_T/16384.0)-((double)dig_T1/1024))*dig_T2;
	var2 =((((double)adc_T/131072.0)-((double)dig_T1/8192.0))*(((double)adc_T)/131072-((double)dig_T1)/8192.0))*((double)dig_T3);	
	t_fine=var1+var2;
	T = (var1 + var2)/5120.0;
	return T;
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

// Récupére les valeur d'ajustement de la température
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
}

//Récupére les valeurs brutes du capteur
void getValue(int fd){

	wiringPiI2CWriteReg8(fd,0xf4,0x25);
	data[0] = wiringPiI2CReadReg8(fd,0xf7);
	data[1] = wiringPiI2CReadReg8(fd,0xf8);
	data[2] = wiringPiI2CReadReg8(fd,0xf9);
	adc_P =((data[0]*4096)+(data[1]*16)+(data[2]));
//	printf("pression : %d\n",adc_P);
//	printf("data : MSB %f  LSB %f XLSB %f\n",data[0],data[1],data[2]);
	data[0] = wiringPiI2CReadReg8(fd,0xfa);
	data[1] = wiringPiI2CReadReg8(fd,0xfb);
	data[2] = wiringPiI2CReadReg8(fd,0xfc);
	adc_T =((data[0]*4096)+(data[1]*16)+(data[2]));
//	printf("Temperature : %d\n",adc_T);
//	printf("data : MSB %f  LSB %f XLSB %f\n",data[0],data[1],data[2]);
}

// Envoie des données au BROKER
void sendData(){
		int vali=0;
		float valf=0;
		float test=0;
		gcvt(pres,8,messageP);
		vali = atoi(messageP);
		valf = atof(messageP);
		test = vali-valf;
		if(test== 0){
			strcat(messageP,".0");
			printf("%s\n",messageP);
		}
		strcat(messageP,"\0");
		printf("%s\n",messageP);
		mosquitto_publish(mosqa, NULL, "mesure/iut/pres", 8, messageP, 0, false);
		gcvt(temp,6,messageT);
		vali = atoi(messageT);
		valf = atof(messageT);
		test = vali-valf;
		if(test== 0){
			strcat(messageT,".0");
			printf("%s\n",messageT);
		}
		strcat(messageT,"\0");
		printf("%s\n",messageT);
		mosquitto_publish(mosqa, NULL, "mesure/iut/temp",6, messageT, 0, false);

}	

int main(){
	wiringPiSetup();	
	fd=wiringPiI2CSetup(addresse);
	
	mosquitto_lib_init();
	
	mosqa = mosquitto_new("test",true,NULL);
	mosquitto_username_pw_set(mosqa, "tom", "22011648");
	//state = mosquitto_connect(mosqa,"194.199.227.235",1139,60);
	state = mosquitto_connect(mosqa,"172.42.50.139",1883,60);
	
	if(state!=0){
		printf("Une erreur est survenue !!! \n");
		mosquitto_destroy(mosqa);	
	}

	for(;;){
		initRegister(fd);	
		getValue(fd);		
		pres = calcPression()/100;
		temp = calcTemp();
		printf("Température : %f °C Pression : %f hPa \n",temp,pres);
		sendData();	
		delay(10000);
	}	
	
	mosquitto_disconnect(mosqa);
	mosquitto_destroy(mosqa);

	return 0;
}
