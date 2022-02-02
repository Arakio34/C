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
	int sort=0;
	int i=0;
	for(;;){
		if(i==LONGUEUR){
			i=0;
			sort=0;	
		}

		if(tab[i]>tab[i+1]){
			int buf;
			buf=tab[i];
			tab[i]=tab[i+1];
			tab[i+1]=buf;
		}
		else{
			sort++;
		}

		printf("%d\n",sort);
		i++;
		
		if(sort==LONGUEUR){
			break;
		}	
		//afficheTab(tab);
	}
}
