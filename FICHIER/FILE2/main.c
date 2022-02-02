#include <stdio.h>
#include <stdlib.h>


#define TAILLECHAR 20
int main(){
	FILE * fichier = fopen("text", "r");
	/*int lettre = 0;*/
	char txt1[20], txt2[20], txt3[20];
	
	if(fichier == NULL){
		exit(1);
	}
	

	//FGETC récupérer un caractère et passe au suivant

	/*while(feof(fichier)==0){
		lettre = fgetc(fichier);
		printf("%c",lettre);
	}	*/
	//FGETS lis un nombre de caractère	
	//fgets(txt,200,fichier);

	//FSCANF
	fscanf(fichier,"%s %s %s",txt1,txt2,txt3);

	printf("%s %s %s\n",txt1,txt2,txt3);
	fclose(fichier);
	return 0;	
}




	
