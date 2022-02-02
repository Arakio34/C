#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


int main()
{
    caseD ** sudoku;
    creerSudoku(&sudoku);
    printSudoku(sudoku);
    freeSudoku(&sudoku);
}
