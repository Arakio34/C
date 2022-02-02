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
	for(int i ; i<27; i++){
	pinMode(i, OUTPUT);
	}
	for(int i ; i<27; i++){
	digitalWrite(i, LOW);
	}
	
	return 0;
	
}
