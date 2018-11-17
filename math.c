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