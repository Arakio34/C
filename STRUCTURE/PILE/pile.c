#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


	pile initialisation(){
		pile PileFc;
		PileFc.actuel = NULL;
		return PileFc; 
	
	}
	void empile(pile *PileFc, int value){
		element *nouveau = malloc(sizeof(element));
		nouveau->valeur = value;
		nouveau->suivant = PileFc->actuel;
		PileFc->actuel = nouveau;
	}	

	void depile(pile *PileFc){
		if(PileFc == NULL){
			exit(EXIT_FAILURE);
		}
		element *elementTampon = PileFc->actuel;

		if(PileFc != NULL && PileFc->actuel != NULL){
			PileFc->actuel = elementTampon->suivant;
			free(elementTampon);
		}
	}

	void depileTout(pile *PileFc){
		if(PileFc == NULL){
			exit(EXIT_FAILURE);
		}
		
		if(PileFc->actuel == NULL){
			return;
		}

		element *elementTampon = PileFc->actuel;

		if(PileFc != NULL && PileFc->actuel != NULL){
			PileFc->actuel = elementTampon->suivant;
			free(elementTampon);
		}
		depileTout(PileFc);
	}

	void affichePile(pile *PileFc){
		element *elementPile = PileFc->actuel;
	
		if(elementPile==NULL || PileFc==NULL){
			return;
		}
		while(elementPile != NULL){
			printf("%d ", elementPile->valeur);
			elementPile = elementPile->suivant;
		}
		printf("\n");
	}

