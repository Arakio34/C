#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrice.h"

int main(){
    int nbc, nbl;
    userData(&nbc,&nbl);
    printf("Debut\n");
    srand(time(NULL));
    matrice mat;
    creerMatrice(&mat,nbc,nbl);
    rempRandMatrice(&mat,nbc,nbl);
    afficheMatrice(mat,nbc,nbl);
    videMatrice(&mat,nbc);
}
