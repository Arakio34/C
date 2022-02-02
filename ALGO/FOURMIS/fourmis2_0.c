#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
struct damier{

	int longueur;
	int largeur;
	int *casses;
};
typedef struct damier damier;
*/


// CASE 0 == BLANC ET 1 == NOIR

struct fourmis{

	int angle;
	int caseCouleur;
	int caseActuelle[2];
};


typedef struct fourmis fourmis;


void creerDam(int ** tabDamier,int longueur,int largeur){
	for(int i=0;i<longueur;i++){
		int a = 1;
		for(int y=0;y<largeur;y++){
			//printf("tab[%d][%d]\n",i,y);
			if(a%4==0){
				if(y%2==0){
					tabDamier[i][y]=1;		
				}
				else{
					tabDamier[i][y]=0;			
				}
			}
			else{
				if(y%2==0){
					tabDamier[i][y]=0;		
				}
				else{
					tabDamier[i][y]=1;			
				}
			}
			a++;
		}
	}
}


int ** allocationMemDam(int longueur,int largeur){
	int ** tabDamier = malloc(longueur*sizeof(*tabDamier));
	for(int i=0;i<longueur;i++){
		tabDamier[i]=malloc(largeur*sizeof(**tabDamier));
	}
	return tabDamier;
}

void libererMemDam(int ** tabDamier,int longueur){
	
	for(int i=0;i<longueur;i++){
		free(tabDamier[i]);
	//	printf("ZBEUB %d \n",i);
	}
	free(tabDamier);
//	printf("FINAL ZBEUB\n");
	
}

void afficheDam(int ** tabDamier,int longueur,int largeur){
	printf("\n\n---------DEBUT-------- \n");	
	//int a = 0;
	
	for(int i=0;i<longueur;i++){
		printf("\n");
		for(int y=0;y<largeur;y++){
			printf("%d",tabDamier[i][y]);
			//a=y;
		}
			//printf("    %d %d",i,a);
	}
	printf("\n\n---------FIN-------- \n");	
}

void fourmisInit(fourmis *fourmisIn, int longueur , int largeur){
	int angle, longueurC, largeurC; 
	switch(rand()%4){
		case 0:
			angle = 0; 
		case 1:
			angle = 90; 
		case 2:
			angle = 180; 
		case 3:
			angle = 270; 
	}
	longueurC = rand()%longueur;
	largeurC = rand()%largeur;	
	fourmisIn->angle=angle;
	fourmisIn->caseCouleur=0;
	fourmisIn->caseActuelle[0]=longueurC;
	fourmisIn->caseActuelle[1]=largeurC;
	printf("CASE DE BASE %d \n",fourmisIn->caseActuelle[0]);
}


void fourmisBouge(fourmis *fourmisIn,int ** damier,int longueur ,int largeur){
	for(double y=0;y<100000;y++){
		//printf("POSITION %d %d\n",fourmisIn->caseActuelle[0],fourmisIn->caseActuelle[1]);	
		//afficheDam(damier,longueur,largeur);
		if(damier[fourmisIn->caseActuelle[0]][fourmisIn->caseActuelle[1]]==0){ // ROTATION DROITE
			damier[fourmisIn->caseActuelle[0]][fourmisIn->caseActuelle[1]]=1;	
			printf("\n ");
			switch (fourmisIn->angle){
				case 0:
					fourmisIn->angle=270;
					if((fourmisIn->caseActuelle[0])==longueur-1){ //270 DROITE
						fourmisIn->caseActuelle[0]=1;
					}
					else{
						fourmisIn->caseActuelle[0]++;
					}
					//printf("270 DROITE\n");
					continue;
				case 90:
					fourmisIn->angle=0;			
					if(fourmisIn->caseActuelle[1]==(largeur-1)){ // 0 DROITE
						fourmisIn->caseActuelle[1]=0;
					}
					else{
					fourmisIn->caseActuelle[1]++;
					}
					//printf("0 DROITE\n");
					continue;
				case 180:
					fourmisIn->angle=90;
					if((fourmisIn->caseActuelle[0])==0){ // 90 DROITE
						fourmisIn->caseActuelle[0]=longueur-1;
					}
					else{
					fourmisIn->caseActuelle[0]--;
					}
					//printf("90 DROITE\n");
					continue;
				case 270:
					fourmisIn->angle=180;
					if(fourmisIn->caseActuelle[1]==0){  // 180 DROITE
						fourmisIn->caseActuelle[1]=largeur-1;
					}
					else{
					fourmisIn->caseActuelle[1]--;
					}
					//printf("180 DROITE\n");
					continue;
			}
		}
		else{  // ROTATION GAUCHE
			damier[fourmisIn->caseActuelle[0]][fourmisIn->caseActuelle[1]]=0; 
			switch (fourmisIn->angle){
				case 0:
					fourmisIn->angle=90;
					if((fourmisIn->caseActuelle[0])==0){ // 90 GAUCHE
						fourmisIn->caseActuelle[0]=longueur-1;
					}
					else{
					fourmisIn->caseActuelle[0]--;
					}
					//printf("90 GAUCHE\n");
					continue;
				case 90:
					fourmisIn->angle=180;
					if(fourmisIn->caseActuelle[1]==0){ // 180 GAUCHE
						fourmisIn->caseActuelle[1]=largeur-1;
					}
					else{
					fourmisIn->caseActuelle[1]--;
					}
					//printf("180 GAUCHE\n");
					continue;
				case 180:
					fourmisIn->angle=270; 
					if((fourmisIn->caseActuelle[0])==longueur-1){ // 270 GAUCHE
						fourmisIn->caseActuelle[0]=0;
					}
					else{
					fourmisIn->caseActuelle[0]++;
					}
					//printf("270 GAUCHE\n");
					continue;
				case 270:
					fourmisIn->angle=0;
					if(fourmisIn->caseActuelle[1]==(largeur-1)){ // 0 GAUCHE
						fourmisIn->caseActuelle[1]=0;
					}
					else{
					fourmisIn->caseActuelle[1]++;
					}
					//printf("0 GAUCHE\n");
					continue;
			}
		}	
	}

}

int main(int argc, char * argv[]){
	srand(time(NULL));
	fourmis fourmis1;
	int longueur = 50;
	int largeur = 50;	
	
	int ** damier; 

	fourmisInit(&fourmis1,longueur,largeur);	
	damier = allocationMemDam(longueur,largeur);	
	creerDam(damier,longueur, largeur);
	afficheDam(damier,longueur,largeur);
	fourmisBouge(&fourmis1,damier,longueur,largeur);
	afficheDam(damier,longueur,largeur);
	libererMemDam(damier,largeur);
	return 0;
}

