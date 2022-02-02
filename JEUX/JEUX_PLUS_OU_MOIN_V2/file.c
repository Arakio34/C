#include <stdio.h>
#include <stdlib.h>

int stoquerScoreF(int score, char* name){

    FILE* fichier= NULL;

    fichier = fopen("score.txt", "a");

    if(fichier != NULL){
        fprintf(fichier,"Score de %s est de %d \n",name,score);

    }
    else{
        printf("Une erreur dans l'ouverture du fichier est survenue\n");

    }
    fclose(fichier);

}

void clearScoreFile(){
    FILE* fichier = NULL;
    fichier = fopen("score.txt","w");
    fprintf(fichier,"");

}

void main(){
    stoquerScoreF(15,"tom");
    
}