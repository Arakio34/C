#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


int main()
{
	Tcase * sudoku1;
	int * values;
	values = malloc(sizeof(int)*81);
	for(int i = 0; i < 81;i++){
		values[i]=0;
	}
	creeSudoku(&sudoku1,values);
	free(sudoku1);
}
