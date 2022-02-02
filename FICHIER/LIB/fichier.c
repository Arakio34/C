#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#define TAILLE_MAX 100

void afficheFichier(FILE* fichier){
	rewind(fichier);
	int compteurLigne = 0;
	char * ligne = malloc(sizeof(char)*TAILLE_MAX);
	
	while(fgets(ligne, TAILLE_MAX,fichier)!=NULL){
		printf("%s\n",ligne);
	}
	free(ligne);
}

int nbMots(FILE* fichier){
	char a;
	int compteurMots;
	compteurMots = 0;

	rewind(fichier);

	printf("nombre\tcaractere\n");
	while(a != EOF){
		a = fgetc(fichier);
		printf("%d\t%c\n",a,a);
		
		if(a==32)
			compteurMots++;	
		
		if(a==10)
			compteurMots++;	
		
	}
	return compteurMots;	
}

//Exclue les retour a la ligne "\n" 
int nbChar(FILE* fichier){
	char a;
	int compteurChar;
	compteurChar = 0;

	rewind(fichier);

	printf("nombre\tcaractere\n");
	
	do{
		a = fgetc(fichier);
		printf("%d\t%c\n",a,a);
		// 10 == "\n"
		if(a==10)
			continue;
		
		compteurChar++;		
	}
	while(a!=EOF);

	return compteurChar;	
}

int nbLigne(FILE* fichier){
	rewind(fichier);
	int compteurLigne = 0;
	char * ligne = malloc(sizeof(char)*TAILLE_MAX);
	
	while(fgets(ligne, TAILLE_MAX,fichier)!=NULL){
		compteurLigne++;
	}
	free(ligne);
	return compteurLigne;
}


	
void viderFichier(FILE* fichier){
	/*int ligne;
	rewind(fichier);
	ligne = nbLigne(fichier);
	
	fflush(fichier);
	fprintf(fichier,"\n");
	*/

}
