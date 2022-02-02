#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


int main(){
	pile joliePile = initialisation();
	empile(&joliePile, 12);
	empile(&joliePile, 16);
	empile(&joliePile, 17);
	empile(&joliePile, 60);
	empile(&joliePile, 72);
	empile(&joliePile, 903);
	affichePile(&joliePile);
	depile(&joliePile);	
	affichePile(&joliePile);
	depileTout(&joliePile);
	affichePile(&joliePile);
}
