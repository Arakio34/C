#include <stdio.h>
#include <stdlib.h>
#include "factoriel.h"


int factoriel(int nb){
    if(nb == 2){
        return 2;
    }
    else{
        return nb*factoriel(nb-1);
    }
}

int arangement(int p, int n){
    if(p>n){
        printf("P ne peut pas être plus grand que N !");
        return -1;
    }
    return factoriel(n)/factoriel(n-p);
}

int convolution(int p, int n){
    if(p>n){
        printf("P ne peut pas être plus grand que N !");
        return -1;
    }
    return factoriel(n)/(factoriel(p)*factoriel(n-p));
}
