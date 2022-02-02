#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vecteur.h"

void creerVec3D(vecteur3D * u , double x, double y, double z){
    u->x = x;   
    u->y = y;   
    u->z = z;
}
void creerVec2D(vecteur2D * u, double x, double y){
    u->x = x;   
    u->y = y;  
}

void afficheVec3D(vecteur3D u){
    printf("vecteur 3D : \n\t x{%f} \n\t y{%f} \n\t z{%f}\n",u.x, u.y, u.z);
}
void afficheVec2D(vecteur2D u){
    printf("vecteur 3D : \n\t x{%f} \n\t y{%f} \n",u.x, u.y);
}

double produitSca(vecteur2D u, vecteur2D v){
    double scal;
    scal = (u.x*v.x)+(u.y*v.y);
    return scal;
}
vecteur3D produitVec(vecteur3D u, vecteur3D v){
/*  u v
   {x x'}
   {y y'}
   {z z'}
  
*/
    vecteur3D prod;
    prod.x = (u.y*v.z)-(u.z*v.y);
    prod.y = (u.z*v.x)-(u.x*v.z);
    prod.z = (u.x*v.y)-(u.y*v.x);
    return prod;
}

double norme3D(vecteur3D u){
    double norme;
    norme=sqrt(pow(u.x,2)+pow(u.y,2)+pow(u.z,2));
    return norme;
}
double norme2D(vecteur2D u){
    double norme;
    norme=sqrt(pow(u.x,2)+pow(u.y,2));
    return norme;
}


