#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

inline void set_mat_val(int *mat, int i, int j, int val, 
					int row, int col)
{
	mat[i * row + j] = val;
}

inline int get_mat_val(int *mat, int i, int j, int row, int col)
{
	return mat[i * row + j];
}

inline void mod_mat_val(int *mat, int i, int j, int val, 
					int row, int col, int add)
{
	if(add)
		mat[i * row + j] += val;
	else
		mat[i * row + j] -= val;
}

int* init_graph(int row, int col, ...)
{
	int i, j;
	va_list elm;
	int *mat;
	
	mat = (int*)malloc(sizeof(int) * row * col);
	va_start(elm, col);
	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++){
			set_mat_val(mat, i, j, va_arg(elm, int), col, row);
	}

	va_end(elm);

	return mat;		
}

