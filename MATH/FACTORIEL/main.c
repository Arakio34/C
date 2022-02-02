#include <stdio.h>
#include <stdlib.h>
#include "factoriel.h"


int main(int argv, char ** argc){
    int a = 8;
    int factorielA = 0;
    factorielA=factoriel(a);
    printf("Factoriel de %d : %d\n",a,factorielA); 
    
    
    int n1=10;
    int p1=5;
    int arangement1 = 0;
    arangement1=arangement(p1,n1);
    printf("Arangement de p = %d et n = %d : %d\n",p1,n1,arangement1);
    
    
    int n2=6;
    int p2=3;
    int convolution1 = 0;
    convolution1=convolution(p2,n2);
    printf("Convolution de p = %d et n = %d : %d\n",p2,n2,convolution1);
    return 0;
}
