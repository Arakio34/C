#ifndef __MATRICE__H__
#define __MATRICE__H__

struct matrice{
    int ** tableau;
};

typedef struct matrice matrice;

void userData(int * nbl, int * nbc);
void creerMatrice(matrice * mat, int nbL, int nbC);
void rempRandMatrice(matrice * mat, int nbL, int nbC);
void afficheMatrice(matrice mat,int nbL,int nbC);
void videMatrice(matrice * mat,int nbC);
matrice addMatrice(matrice * mat1, matrice * mat2);
#endif
