#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ttutils.h"
#define esc 27

void clearScreen(){
    printf("%c[2J%c[H" , esc , esc);
}

int nowSize(char * txt ){
    int i=0;   
    for(i;txt[i]!=0;i++); 
    return i;
}

void delay(int i){
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

//void printTxt(char * text){
//    for(int i=0; i<taille)}
