#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void print_matrix(Matrix *input) {

	int a, b;

	/*
	0 0
	0 1
	0 2

	1 0
	1 1
	1 2
	
	
	
	*/

	for (a = 0; a < input->col; a++) {
		for (b = 0; b < input->row; b++) {
			printf("%d	", input->matrix[b][a]);
		}
		printf("\n");
	}
}