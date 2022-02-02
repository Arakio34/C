#ifndef __SUDOKU__H__
#define __SUDOKU__H__

typedef struct {
    int value;
    int posibiliter[9];

} caseD;

void creerSudoku(caseD *** sudoku);
void printSudoku(caseD ** sudoku);
void freeSudoku(caseD *** sudoku);
int verifLigne(caseD ** sudoku);
int sommeTab(int * tab, int taille);
#endif
