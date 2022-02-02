#ifndef	__COMPLEXETT__H__
#define __COMPLEXETT__H__


struct complexe{
	double imaginaire;
	double reel;
};
typedef struct complexe complexe;

void afficheComplexe(complexe *nbFonc);
void creerComplexe(int reel, int img,complexe *nbFonc);
double calculeArg(complexe *nb);
double calculeMod(complexe *nb);
complexe calculeAdd(complexe *nb1, complexe *nb2);
complexe calculeMul(complexe *nb1, complexe *nb2);
complexe calculeDiv(complexe *nb1, complexe *nb2);


#endif
