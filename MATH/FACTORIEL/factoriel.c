#include <stdio.h>
#include <stdlib.h>
#include "factoriel.h"


int factoriel(int nb){
    if(nb == 1){
        return 1;
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

int premier(int val){
    int test = 0;
    for(int i = 2 ; i<val || test==1; i++){
        if(val%i == 0){
            test++;
            return 1;
        }
    }
    return 0;
}
