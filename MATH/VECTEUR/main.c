#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vecteur.h"

int main(){
    printf("Debuts\n");
   
    vecteur3D u,v,z;
    vecteur2D a,b;
   
    double scalaireAB;
   
    creerVec3D(&u,2,3,4);
    creerVec3D(&v,6,6,7);
   
    creerVec2D(&a,5,5);
    creerVec2D(&b,10,-2);
   
    scalaireAB=produitSca(a,b);
   
    printf("scalaire AB : %f\n",scalaireAB);
   
    z=produitVec(u,v); 
    afficheVec3D(z);
    
   double normeU=norme3D(u);
    printf("norme de U %f\n",normeU);
}
