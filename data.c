#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Matrix *new_matrix() {

	Matrix *return_matrix = (Matrix *)malloc(sizeof(Matrix));
	return_matrix->col = 0;
	return_matrix->row = 0;
	return return_matrix;
}

void malloc_matrix(Matrix **input, int row_input, int col_input) {

	int a, b;
	(*input)->row = row_input;
	(*input)->col = col_input;

	(*input)->matrix = (int **)malloc(sizeof(int *) * (*input)->row);
	for (a = 0; a < (*input)->row; a++) {
		(*input)->matrix[a] = (int *)malloc(sizeof(int) * (*input)->col);
	}
	
	for (a = 0; a < (*input)->row; a++) {
		for (b = 0; b < (*input)->col; b++) {
			(*input)->matrix[a][b] = 0;
		}
	}
}
