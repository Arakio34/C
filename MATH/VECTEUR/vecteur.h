#ifndef __VECTEUR__H__
#define __VECTEUR__H__

struct vecteur3D{
    double x;
    double y;
    double z;
};

struct vecteur2D{
    double x;
    double y;
};

typedef struct vecteur3D vecteur3D;
typedef struct vecteur2D vecteur2D;


void creerVec3D(vecteur3D * u , double x, double y, double z);
void creerVec2D(vecteur2D * u, double x, double y);

void afficheVec3D(vecteur3D u);
void afficheVec2D(vecteur2D u);

double produitSca(vecteur2D u, vecteur2D v);
vecteur3D produitVec(vecteur3D u, vecteur3D v);

double norme3D(vecteur3D u);
double norme2D(vecteur2D u);

#endif
