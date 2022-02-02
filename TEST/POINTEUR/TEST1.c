#include<stdio.h>
#include<stdlib.h>

struct personne{

	int POIDS;
	int TAILLE;

};
typedef struct personne personne;

int var1 = 15;
void test(personne *people){
	people->TAILLE = 175;	
}

int main(){
	personne tom;
	tom.POIDS = 60;
	test(&tom);
	printf("%d\n",tom.TAILLE);
	return 0;
}
