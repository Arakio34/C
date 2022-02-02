#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

void creerSudoku(caseD *** sudoku)
{

    int sodokuPapierCmp[9][9] =
	{ { 9, 8, 6, 1, 7, 2, 5, 4, 3 }, 
      { 4, 5, 2, 3, 6, 9, 1, 7, 8 },
	  { 3, 7, 1, 5, 4, 8, 9, 6, 2 },
      { 6, 9, 7, 2, 5, 4, 3, 8, 1 }, 
      { 8, 4, 5, 9, 3, 1, 7, 2, 6 },
      { 1, 2, 3, 7, 8, 6, 4, 9, 5 }, 
      { 5, 3, 4, 8, 2, 7, 6, 1, 9 },
      { 7, 1, 8, 6, 9, 3, 2, 5, 4 },
	  { 2, 6, 9, 4, 1, 5, 8, 3, 7 } };
    
    int i, y;

    (*sudoku) = (caseD **) malloc(sizeof(caseD *) * 9);

    for (i = 0; i < 9; i++) {
	(*sudoku)[i] = (caseD *) malloc(sizeof(caseD) * 9);
    }

    for (i = 0; i < 9; i++) {
	for (y = 0; y < 9; y++) {
	    (*sudoku)[i][y].value = sodokuPapierCmp[i][y];
	}
    }
}

void freeSudoku(caseD *** sudoku)
{
    int i;
    for (i = 0; i < 9; i++)
	free((*sudoku)[i]);
    free(*sudoku);
    *sudoku = NULL;
}

void printSudoku(caseD ** sudoku)
{
    int i, y;
        for (i = 0; i < 9; i++) {
	        if(y%3==0){
                printf("\n");
            }
	    for (y = 0; y < 9; y++) {
	        if(y%3==0){
                printf("|");
            }
            printf("%d", sudoku[i][y].value);
        }
    }
}

int verifLigne(caseD ** sudoku){
    int i,y,x;
    int verif = 0;
    for(i=0;i<9;i++){
    int tabVerif[9]={1,2,3,4,5,6,7,8,9};
    for(y=0;y<9;y++){
        for(x=0;x<9;x++){
            if(sudoku[i][y].value==tabVerif[x]){
                tabVerif[x]=0;
            }
        }
        verif=sommeTab(tabVerif,9);
    }
    return verif;
}

int sommeTab(int * tab, int taille){
    int i,var=0;
    for(i=0;i<9;i++){
        var=var+tab[i];
    }
    return var;
}
