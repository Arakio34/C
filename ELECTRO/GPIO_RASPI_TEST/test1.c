#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

int attente(int nbSeconde){
	int time = 1000*nbSeconde;
	clock_t start_time = clock();
	while(clock() < start_time + time);
	return 0;
}
	

int main (){
	
		// Initialise les fonction de la librairie wiringPi 
	wiringPiSetupGpio();
	
		// On set les valeur du potentiométre
	int const pot = 11;
	pinMode(pot, INPUT);
	
	int valPot = 0;
	while(1==1){
		attente(2);
		
		valPot=digitalRead(pot);
		printf("%d",valPot);
	}
	
	return 0;
	
}
