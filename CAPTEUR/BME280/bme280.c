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
int8_t dig_H1 = 0; 
int16_t dig_H2 = 0; 
int8_t dig_H3 = 0; 
int16_t dig_H4 = 0; 
int16_t dig_H5 = 0; 
int8_t dig_H6 = 0; 
int addresse = 0x77;
double var1 = 0;
double var2 = 0;
double var_H =0;
double t_fine= 0;
uint32_t adc_T=0;
uint32_t adc_P=0;
uint32_t adc_H=0;
double T = 0;
double P = 0;
double H = 0;
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

double calcHumi(){

	var_H = (double)t_fine -76800;
	var_H = (adc_H

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
	dig_H1 = wiringPiI2CReadReg8(fd,0xa1) 
	dig_H2 = wiringPiI2CReadReg16(fd,0xe1) 
	dig_H3 = wiringPiI2CReadReg8(fd,0xe3) 
	dig_H4 = wiringPiI2CReadReg16(fd,0xe4) 
	dig_H5 = wiringPiI2CReadReg16(fd,0xe5) 
	dig_H6 = wiringPiI2CReadReg16(fd,0xe7) 

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
	
	adc_H = wiringPiI2CReadReg16(fd,0xfd);
}
	

int main(){
	wiringPiSetup();	
	fd=wiringPiI2CSetup(addresse);	

	for(;;){
		initRegister(fd);	
		getValue(fd);		
		pres = calcPression()/100;
		temp = calcTemp();
		printf("Température : %f °C Pression : %f hPa \n",temp,pres);
		delay(5000);
	}	
	
	return 0;
}
