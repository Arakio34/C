#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexeTT.h"

void afficheComplexe(complexe *nbFonc){
	if(nbFonc->imaginaire>0)
		printf("%f + %fi\n",nbFonc->reel,nbFonc->imaginaire);
	else if(nbFonc->imaginaire==0)
		printf("%f\n",nbFonc->reel);
	else
		printf("%f %fi\n",nbFonc->reel,nbFonc->imaginaire);
	if(nbFonc->reel==0)
		printf("%fi\n",nbFonc->imaginaire);
}

void creerComplexe(int reel, int img, complexe *nbFonc){
	
	nbFonc->reel = reel;
	nbFonc->imaginaire = img;
}

double calculeArg(complexe *nb){
	
	double module,reel,img,argument,sin,cos;
	
	module=calculeMod(nb);
	
	reel=nb->reel;
	img=nb->imaginaire;
	
	cos=reel/module;
	sin=img/module;

	argument = atan2(sin,cos);

	return argument;
}

double calculeMod(complexe *nb){
	double reel,img,module;
	reel = nb->reel;
	img = nb->imaginaire;
	module = pow(reel,2) +pow(img,2);
	module = sqrt(module);
	return module;
}

complexe calculeAdd(complexe *nb1 ,complexe *nb2){
	complexe nb3;
	nb3.reel= nb1->reel + nb2->reel;
	nb3.imaginaire= nb1->imaginaire + nb2->imaginaire;
	return nb3;

}

