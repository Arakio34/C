#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

/*int attente(int nbSeconde){
	int time = 1000*nbSeconde;
	clock_t start_time = clock();
	while(clock() < start_time + time);
	return 0;
}*/

	
int main (){
	
		// Initialise les fonction de la librairie wiringPi
	wiringPiSetupGpio();
	
		// On set le pin de la led
	int const led = 11;
	pinMode(led, OUTPUT);

	while(1==1){
		delay(1000);
		digitalWrite(led,LOW);
		delay(1000);
		digitalWrite(led,HIGH);
		}
	
	return 0;
	
}
