#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HAUTEUR  20
#define LARGEUR  20

// DECLARATION DES FONCTION 

int ** initMemDam();
void freeMemDam(int ** damierFonc);
void initCells();
void afficheDam(int ** damierFonc);
void evolutionCells(int ** damierFonc);
int lookAround(int ** damierFonc, int pos[2]);

// FONCTION PRINCIPAL

int main(){
	srand(time(NULL));
	
	int ** damier;
	
	damier=initMemDam();
	initCells(damier);
	afficheDam(damier);
	evolutionCells(damier);
	afficheDam(damier);
	freeMemDam(damier);
	return 0;
}


// ALOUE LA MEMOIRE AU TABLEAU

int ** initMemDam(){
	int ** damierFonc;
	int i;

	damierFonc= malloc(HAUTEUR * sizeof(int*));
	
	for(i = 0; i < HAUTEUR ; i++){
		damierFonc[i]=malloc(LARGEUR * sizeof(int));
	}
	return damierFonc;
}

// LIBERE LA MEMOIRE DONNER AU TABLEAU

void freeMemDam(int ** damierFonc){
	int i;
	for(i = 0; i < HAUTEUR; i++){
		free(damierFonc[i]);
	}
	free(damierFonc);
	printf("FIN TOUTES LES VARIABLES ON ÉTÉ LIBERÉ.\n");
	
}

// REMPLIE LE TABLEAU DE MANIERE ALEATOIRE AFIN DE SIMULER LES CELLUES

void initCells(int ** damierFonc){
	int i,y;
	for(i = 0; i < HAUTEUR; i++){
		for(y = 0; y < LARGEUR; y++){
			damierFonc[i][y]= rand()%2;
		}
	}

}

// AFFICHE LA TABLEAU DANS LE TERMINAL

void afficheDam(int ** damierFonc){
	int i,y;
	printf("\n");
	for(i = 0; i < HAUTEUR; i++){
		for(y = 0; y < LARGEUR; y++){
			printf("%d",damierFonc[i][y]);			
		}
		printf("\n");
	}
}

//FAIT EVOLUER LES CELULES

void evolutionCells(int ** damierFonc){
	int nbAround,rep,i,y;
	int pos[2];
	for(rep = 0; rep < 1000 ; rep++){
		for(i = 0; i < HAUTEUR; i++){
			for(y = 0; y < LARGEUR; y++){
				
				pos[0]= i;
				pos[1]= y;
				nbAround = lookAround(damierFonc, pos);	
				
				if(nbAround > 3 && damierFonc[i][y]==1){
					// Meurt de surpopulation
					damierFonc[i][y]=0;
					
				}
				if(nbAround <= 1 && damierFonc[i][y]==1){
					damierFonc[i][y]=0;
					// Meurt de solitude
				}			
				if(nbAround <= 3 && nbAround > 1 && damierFonc[i][y]==0){
					damierFonc[i][y]=0;
					// It's alive !!!
				}
			/*	else{
				continue;
				}	
			*/
		//	afficheDam(damierFonc);
			}
		}
	}
				
}

//REGARDE COMBIEN DE CELLULES VIVANTES SONT AUTOUR DE LA CELLULES ACTUEL

int lookAround(int ** damierFonc, int pos[2]){
	int hauteurT=pos[0];
	int largeurT=pos[1];
	int nbCells=0;

	// GAUCHE
	if(largeurT != 0){
		if(damierFonc[hauteurT][largeurT-1]==1 ){
			nbCells++;
		}
	}
	// DROITE
	if(largeurT != (LARGEUR-1) ){
		if(damierFonc[hauteurT][largeurT+1]==1){
			nbCells++;
		}
	}
	// HAUT
	if(hauteurT != 0){
		if(damierFonc[hauteurT-1][largeurT]==1){
			nbCells++;
		}
	}
	// BAS
	if(hauteurT != (HAUTEUR-1) ){
		if(damierFonc[hauteurT+1][largeurT]==1 ){
			nbCells++;
		}
	}
	// HAUT GAUCHE
	if(largeurT != 0 && hauteurT != 0 ){
		if(damierFonc[hauteurT-1][largeurT-1]==1 ){
			nbCells++;
		}
	}
	// HAUT DROITE
	if(largeurT != (LARGEUR-1) && hauteurT != 0 ){
		if(damierFonc[hauteurT-1][largeurT+1]==1){
			nbCells++;
		}
	}
	// BAS GAUCHE
	if(largeurT != 0 && hauteurT != (HAUTEUR-1)){
		if(damierFonc[hauteurT+1][largeurT-1]==1){
			nbCells++;
		}
	}
	// BAS DROITE
	if(largeurT != (LARGEUR-1) && hauteurT != (HAUTEUR-1)){
		if(damierFonc[hauteurT+1][largeurT+1]==1){
			nbCells++;
		}
	}
	return nbCells;
}

