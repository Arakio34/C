#ifndef __SUDOKU__H__
#define __SUDOKU__H__

struct Scase {
	int chiffre;
	int * possibiliter;
};

typedef struct Scase Tcase;

void creeSudoku(Tcase ** sudoku, int * valeur);
int verifyTableau(int * valeur);
#endif
