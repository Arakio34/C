#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONGUEUR 500
#define GRANDEURNB 100


//DEFINITION DES FONCTION
int * memTab();
void afficheTab(int * tab);
void remplirTab(int * tab);
void trierTab(int * tab);

//FONCTION PRINCIPAL

int main(){
	srand(time(NULL));
	int *tabTrie;
	tabTrie = memTab();
	remplirTab(tabTrie);	
	afficheTab(tabTrie);
	trierTab(tabTrie);
	afficheTab(tabTrie);
	free(tabTrie);
}


// ALLOUE LA MEMOIRE NECESAIRE AU TABLEAU

int * memTab(){
	int * tab;
	tab=malloc(LONGUEUR*sizeof(int));
	return tab;
}	

void afficheTab(int * tab){
	int i;
	printf("\n");
	for(i=0;i<LONGUEUR;i++){
		printf(" %d,",tab[i]);
	}
	printf("\n");
}

void remplirTab(int * tab){
	int i;
	for(i=0;i<LONGUEUR;i++){
		tab[i]=rand()%GRANDEURNB;	
	}
	printf("\n");
}

void trierTab(int * tab){
    int i,y;
    for(y=0;y<LONGUEUR;y++){
        for(i=0;i<(LONGUEUR-y);i++){
            if(tab[i]>tab[i+1]){
                int tmp;
                tmp=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=tmp;
            }
        }
    }
}


