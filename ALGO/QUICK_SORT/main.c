#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONGUEUR 100 // NOMBRE DE CASE DU TABLEAU 
#define RANGE 100 // VALEUR MAX QUE PEUT AVOIRE LES NOMBRE DANS LE TABLEAU

void remplirTab(int * tabFonc);
void afficheTab(int * tabFonc);
void quickSort(int * tabFonc, int debut,int fin);

// FONCTION PRINCIPAL
int main(){
	srand(time(NULL));
	int * tab;
	tab = malloc(LONGUEUR*sizeof(int));
	remplirTab(tab);
	afficheTab(tab);
	quickSort(tab,0,(LONGUEUR-1));
	afficheTab(tab);
	free(tab);
}

// REMPLIE LE TABLEAU
void remplirTab(int * tabFonc){
	int i;
	for(i=0;i<LONGUEUR;i++){
		tabFonc[i]=rand()%(RANGE+1);	
	}

}

// AFFICHE LE TABLEAU
void afficheTab(int * tabFonc){
	int i;
	printf("\n");	
	for(i=0;i<LONGUEUR;i++){
		printf("%d,",tabFonc[i]);	
	}
	printf("\n");	

}

void quickSort(int * tabFonc, int debut,int fin){
	// compteF = compteur Fin
	// compteD = compteur Debut 
	// base  = valeur de base
	// tmp = temporaire
	// move = nombre de mouvement
	int compteF,compteD,base,tmp,move;
	move=0;
	compteF=fin;
	compteD=debut;
	//JE METS MA VALEUR PIVOT A DROITE DU TABLEAU POUR QUELLE NE ME GENE PAS LORS DU TRIE
	base=tabFonc[debut];
	tabFonc[debut]=tabFonc[fin];
	tabFonc[fin]=base;
	// LA METHODE DE BASE QUE J'UTILISAIT CONSISTAIT A PARCOURIRE LE TABLEAU DE GAUCHE A DROITE, ET DE RENPLACER A L'AIDE DE
	// DEUX CURSEUR A LA FIN ET AU DEBUT DU TABLEAU LES VALEUR. CELA NE FONCTIONAIT PAS.
	// CETTE FOIS SI J'AI TOUJOURS MES DEUX CURSEUR MAIS JE COMPARE LEUR VALEUR AFIN DE SAVOIR SI IL SONT PLUS GRAND OU PLUS
	// PETIT QUE MA VALEUR DE BASE.
	// SI LA VALEUR DE GAUCHE EST PLUS GRANDE ET LA VALEUR DE DROITE PLUS PETITE JE LES INVERSES.
	while(compteD<=compteF){
		if(tabFonc[compteD]>=base && tabFonc[compteF]<base){
			tmp=tabFonc[compteD];	
			tabFonc[compteD]=tabFonc[compteF];	
			tabFonc[compteF]=tmp;	
			move++;
			compteD++;
			compteF--;

		}
		if(tabFonc[compteD]<base){
			compteD++;
		}
		if(tabFonc[compteF]>=base){
			compteF--;
		}
	
	}
	// JE REMETS MA VALEUR DE BASE AU L'INTERSECTION DU TABLEAU
	tabFonc[fin]=tabFonc[compteD];
	tabFonc[compteD]=base;

	// SI LA TAILLE DU TABLEAU EST INFERIEUR OU EGALE A 2 ET QUE A LA FIN ON N'AS FAIT AUCUN MOUVEMENT ALORS ON FINI LA FONCTION
	if((fin-debut)<1 && move==0){
		return;
	}
	// ICI ON INCLUE PAS LA VALEUT PIVOT PRECEDENTE CAR SINON CELA REMELANGERAIT TOUT LE TABLEAU
	quickSort(tabFonc,debut,(compteD-1));
	quickSort(tabFonc,(compteD+1),fin);
	return;
}

