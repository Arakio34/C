#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int nbLigne(FILE * input);
int nbChar(FILE * input);
void printFile(FILE * input);
void convertToInt(FILE * input, int * tabvalue);
int main(){
   int ligne=0;
   int caractere=0;
   int * valeur;
   FILE * input;
   
   input = fopen("input","r");
   ligne=nbLigne(input);
   caractere=nbChar(input);
   valeur=malloc(ligne*sizeof(int));
   convertToInt(input,valeur);
   printf("test: %d",valeur[0]);
   fclose(input);
   free(valeur); 
   return 0;

}

int nbLigne(FILE * input){
    rewind(input);
    int i = 0;
    int valueOfFile = 0;
    if(input){
        while(valueOfFile!=EOF){
            valueOfFile = fgetc(input);
            if(valueOfFile == '\n'){
                i++;
            }
        }
    }
    return i;
}

void printFile(FILE * input){
    rewind(input);
    int valueOfFile=0;
    if(input){
        while(valueOfFile!=EOF){
            valueOfFile = fgetc(input);
            printf("%c" ,valueOfFile);
        }
    }
}
int nbChar(FILE * input){
    rewind(input);
    int valueOfFile = 0;
    int i = 0; 
    if(input){
        while(valueOfFile!=EOF){
            valueOfFile = fgetc(input);
            i++;
        }
    }
    return i;
}
void convertToInt(FILE * input, int * tabvalue){
    rewind(input);
    int ligne =0;
    int vof=0;
    int nbChar;
    char * chaine;
    ligne = nbLigne(input);
    rewind(input);
    for( int i=0; i<ligne||vof==EOF;i++){
        for(nbChar=0 ;vof!='\n';nbChar++){
            vof = getc(input);
            nbChar++;
        }
        chaine = malloc(nbChar * sizeof(char));
        for(int y = 0 ;vof!='\n'; y++){
            vof = getc(input);
            chaine[y]=vof;
        }
        printf("%s\n",chaine);
        tabvalue[i]=atoi(chaine);
        free(chaine);
    }
}



