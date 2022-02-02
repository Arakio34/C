#include <stdio.h>
#include <stdlib.h>

struct ville{

	int nbHabitant;
	int taille;
	int codePostal;
	char maire[20];
};

typedef struct ville ville;

double habitantParMettreCarrer(ville *city);

int main (int argc , char* argv[]){
	
	ville Bezier = {2000,2000,34500,"Menard"};
	
	printf("%s\n",Bezier.maire);
	int a = 10;
	int* test = &a;
	printf("%d\n",a);
	*test=129;
	printf("%d\n",a);
	printf("%f\n",habitantParMettreCarrer(&Bezier));
	
}
double habitantParMettreCarrer(ville *city){
	double hpmc;
	hpmc = (double)city->taille/(double)city->nbHabitant;
	return hpmc;

}
