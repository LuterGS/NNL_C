#include <stdio.h>
#include <stdlib.h>
#include "declare.h"


Matrix *sized_matrix(int row_input, int col_input) {

	Matrix *return_matrix = new_matrix();
	malloc_matrix(&return_matrix, row_input, col_input);
	return return_matrix;
}


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

	(*input)->matrix = (double **)malloc(sizeof(double *) * (*input)->row);
	for (a = 0; a < (*input)->row; a++) {
		(*input)->matrix[a] = (double *)malloc(sizeof(double) * (*input)->col);
	}
	
	for (a = 0; a < (*input)->row; a++) {
		for (b = 0; b < (*input)->col; b++) {
			(*input)->matrix[a][b] = 0.0;
		}
	}
}
