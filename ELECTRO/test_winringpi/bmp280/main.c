#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int addresse = 0x77;
int fd;
float data[3];
float pres;
int temp;


void setUp(int fd){

	wiringPiI2CWriteReg8(fd,0xF4,0x25);
}


int main(){
	wiringPiSetup();	
	fd=wiringPiI2CSetup(addresse);
	for(;;){	
		setUp(fd);
		data[0] = wiringPiI2CReadReg8(fd,0xf7);
		data[1] = wiringPiI2CReadReg8(fd,0xf8);
		data[2] = wiringPiI2CReadReg8(fd,0xf9);
		pres = ((data[0]*65536)+(data[1]*256)+(data[2])*2.62);
		printf("pression : %f Pa\n",pres);
		printf("data : %f %f %f\n",data[0],data[1],data[2]);
		delay(3000);
	}	

	return 0;
}
