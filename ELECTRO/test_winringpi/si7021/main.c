#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int addresse = 0x40;
int fd;
int data;
int hum;
int temp;
int main(){
	wiringPiSetup();	
	fd=wiringPiI2CSetup(addresse);
	for(;;){
		delay(3000);	
		data = wiringPiI2CReadReg16(fd,0xe5);
		hum = ((125*data)/65536)-6;
		data = wiringPiI2CReadReg16(fd,0xe3);
		temp = ((176*data)/65536)-49;
		printf("humidité : %d% / temperature: %d °C \n",hum,temp);
	}
		


	return 0;
}
