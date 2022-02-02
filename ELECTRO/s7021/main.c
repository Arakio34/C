#include <stdio.h>
#include <stdlib.h>
#include <pigpiod_if2.h>
#include <time.h>
/* Test de la librairie pigpiod avec le capteur s7021 capteur d'humiditer
 * et de température.
 * On utilise une connexion I2C (SDA(GPIO3) SCL(GPIO5)*/
int main(){
	//time_t debut;
	//time_t fin;
	//debut = time(NULL);

	int pi;
	if((pi = pigpio_start(0,0))<0){	
		//int i2cLink = i2c_open(pi,0,0,0);
		while(1==1){
			time_t time1; 
			time1= time(NULL);
			if (time(NULL)==(time1+5)){
				//printf(i2c_read());
				printf("test\n");
			}
		}
	}
	//i2c_close(pi,i2cLink);
	pigpio_stop(pi);
	return 0;
}
