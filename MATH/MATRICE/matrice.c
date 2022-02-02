#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrice.h"


void userData(int * nbc, int * nbl){
    char snbl[10];
    char snbc[10];
    printf("Donner les dimension de votre matrice.\n");
    printf("Nombre de lignes :\n");
    gets(snbl);
    *nbl=atoi(snbl); 
    printf("Nombre de collone :\n");
    gets(snbc);
    *nbc=atoi(snbc);
}

void creerMatrice(matrice * mat, int nbL, int nbC){
    mat->tableau = malloc(sizeof(int *)* nbL);
    int i;
    for(i=0;i<nbC;i++)
        mat->tableau[i]=malloc(sizeof(int)*nbC);
}
/*
matrice addMatrice(matrice * mat1, matrice * mat2){
    matrice matAdd;
    
    return matAdd;

}*/

void afficheMatrice(matrice mat,int nbL,int nbC){
    int i ,y;
    for(i=0;i<nbL;i++){
        for(y=0;y<nbC;y++){
            printf("%d\t",mat.tableau[i][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void rempRandMatrice(matrice * mat, int nbL, int nbC){
    int i ,y; 
    for(i=0;i<nbL;i++){
        for(y=0;y<nbC;y++){
            mat->tableau[i][y]=rand() % 101;
        }
    }
}


void videMatrice(matrice * mat, int nbC){
    int i;
    for(i=nbC;i>0;i--)
        free(mat->tableau[i]);
    free(mat->tableau);
}


