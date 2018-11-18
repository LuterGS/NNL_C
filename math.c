#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "declare.h"

Matrix *matrix_product(Matrix **first_input, Matrix **second_input) {

	//4x3 3x5 亜 焼艦虞 3x4 5x3
	//
	//し し し	し し し し し		
	//し し し	し し し し し 	
	//し し し	し し し し し
	//し し し	
	//
	int a, b, c, d;
	bool checker;
	Matrix *matrix_return = new_matrix();

	if ((*first_input)->row == (*second_input)->col) { checker = true; }
	else { checker = false; }

	if (checker == false) {
		printf("First matrix's column size and second matrix's row is not same.\n");
		printf("Matrix product fail!\n");
	}
	else {
		malloc_matrix(&matrix_return, (*second_input)->row, (*first_input)->col);
		d = 0;
		for (a = 0; a < (*first_input)->col; a++) {
			for (b = 0; b < (*second_input)->row; b++) {
				for (c = 0; c < (*first_input)->row; c++){
					matrix_return->matrix[b][a] += (*first_input)->matrix[c][a] * (*second_input)->matrix[b][c];
				}
			}
		}
	}

	return matrix_return;
}


Matrix *matrix_transpose(Matrix **input) {

	int a, b;
	Matrix *return_matrix = sized_matrix((*input)->col, (*input)->row);
	for (a = 0; a < (*input)->col; a++) {
		for (b = 0; b < (*input)->row; b++) {
			return_matrix->matrix[a][b] = (*input)->matrix[b][a];
		}
	}
	return return_matrix;
}


double reLU(double input) {

	if (input < 0) {
		return 0.0;
	}
	else {
		return input;
	}
}