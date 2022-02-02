#include <stdio.h>
#include <stdlib.h>
#include "complexeTT.h"



int main(){
	double moduleNb1,arg;
	complexe nb1;

	creerComplexe(-2,2,&nb1);
	afficheComplexe(&nb1);
	moduleNb1 = calculeMod(&nb1);
	arg = calculeArg(&nb1);
	printf("module : %f argument : %f \n", moduleNb1,arg);
	return 0;
}
