#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"


void defineMatrice(Matrice * m1,int c , int l){
    m1->tab = (int *)malloc(sizeof(int) * l * c);
    m1->nbC = c;
    m1->nbL = l;
}

void freeMatrice(Matrice * m1){
    free(m1->tab);
}
void printMatrice(Matrice * m1){
    int i = 0;
    for(i;i<(m1->nbC * m1->nbL);i++){
        if(i%m1->nbL==0){
            printf("\n");
        }
        printf(" %d ",m1->tab[i]);
    }
    printf("\n");
}
void addMatrice(Matrice * m1,Matrice * m2, Matrice * m3){
    int i = 0;
    if(m1->nbC==m2->nbC){
        if(m1->nbL==m2->nbL){
            for(i=0; i<(m1->nbL*m1->nbC);i++){  
                m3->tab[i]=m2->tab[i]+m1->tab[i];        
            }
        }
    }
}

void tabToMatrice(Matrice * m1,int * tab){
    int i = 0;
    for(i;i<(m1->nbC*m1->nbL); i++){
        m1->tab[i]=tab[i];
    }
}



void multMatrice(Matrice * m1,Matrice * m2, Matrice * m3){
    int i = 0;
    int x = 0;
    int changeLig = 0;
    int col = m3->nbC;
    int lig = m3->nbL;
    int b = 0;
    if(m1->nbC==m2->nbL){
        for(i=0;i<(col*lig); i++){        
            for(x=0;x<col; x++){
                if(i%col == 0 && i!=b){
                    changeLig++;  
                    b=i;
                }
                m3->tab[i]=m1->tab[changeLig*col+x]*m2->tab[x*col+(i%col)] + m3->tab[i];           
            }
        }
    }
    else{
    printf("Bad format !\n The numbers of colons of Matrix A need to be equals to the lines number B\n");
    }
}

int det(Matrice * m1){
    int i;
    int x;
    int determinant = 0;
    int detTmp=0;
    int col=m1->nbC;
    int lig=m1->nbL;
    int tab[(col-1)*(lig-1)]; 
    int a = 0;
    
    if(lig!=col){
        
	printf("Bad format need to be a quarter matrix");		    
	return -1;
    }
    // Si c'est une matrice d'ordre deux on peut directement faire le calcul
    if(col == 2){
	determinant = (m1->tab[0]*m1->tab[3])-(m1->tab[1]*m1->tab[2]); 
    	return determinant;
    }
    else{
	for(int y=0;y<col;y++){
		a=lig;
		for(x = 0 ,i = lig; i < (col*lig);i++,x++){
			// J'initialise la variable i a lig afin de ne pas prendre en compte la premier ligne.
            // Ici a permet de surveiller le changement de ligne.
            // J'utilise 
            if(i>((a+col))-1){
				a=a+lig;
			}
			if(i==(a+y)){
				i++;
			}
			tab[x]=m1->tab[i];
    	}	
		Matrice m2;
		defineMatrice(&m2,col-1,lig-1);
    	tabToMatrice(&m2,tab);
		
        if(y%2==0){	
			detTmp = detTmp + m1->tab[y]*det(&m2);
		}
		else{
			detTmp = detTmp - m1->tab[y]*det(&m2);
		}
		freeMatrice(&m2);
	
	}
    determinant = detTmp ;
	return determinant;
    }
}
void trMatrice(Matrice * m1 , Matrice * trm1){
    
    if(m1->nbC != trm1->nbL){
        printf("Bad format ! \n");
        return;
    }
    if(m1->nbL != trm1->nbC){
        printf("Bad format ! \n");
        return;
    }
}

//TODO
//void comMatrice(Matrice * m1,Matrice * m2){}
//void invMatrice(Matrice * m1,Matrice * m2){}
