#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#define NB_CASE 81 

// Le pointeur valeur, dirige vers la liste d'entier avec la quel
// on doit remplire le sudoku

void creeSudoku(Tcase ** sudoku, int * valeur){
	if(verifyTableau(valeur)==-1){
		printf("Erreur sur la liste des valeurs.\n");
		printf("Verifier qu'aucune n'est aux dessus de 10.\n");
		return;
	}
	sudoku=malloc(sizeof(Tcase)*81);
	for(int i = 0 ; i < NB_CASE ; i++){
		sudoku[i]->chiffre=valeur[i];		
		if(valeur[i]!=0){
			for(int y = 0 ; y<8;y++)
				sudoku[i]->possibiliter=0;		
		}
		else{
			for(int y = 0 ; y<8;y++)
				sudoku[i]->possibiliter[y]=y+1;		
		}
	}
}

int verifyTableau(int * valeur){
	for(int i; i < NB_CASE; i++){
		if(valeur[i]>9){
			return -1;
		}
	}
	return 0;
}


