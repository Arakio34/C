#ifndef __MATRICE__H__
#define __MATRICE__H__

struct matrice {
    int * tab;
    int nbC;
    int nbL;
};
typedef struct matrice Matrice;


void addMatrice(Matrice * m1,Matrice * m2, Matrice * m3);
void tabToMatrice(Matrice * m1,int * tab); 
void defineMatrice(Matrice * m1,int c , int l);
void freeMatrice(Matrice * m1);
void multMatrice(Matrice * m1,Matrice * m2, Matrice * m3);
void printMatrice(Matrice * m1);
void invMatrice(Matrice * m1,Matrice * m2, Matrice * m3);
void trMatrice(Matrice * m1,Matrice * trm1);
int det(Matrice * m1);

#endif
