#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void print_matrix(Matrix *input) {

	int a, b;
	for (a = 0; a < input->col; a++) {
		for (b = 0; b < input->row; b++) {
			printf("%.4f	", input->matrix[b][a]);
		}
		printf("\n");
	}
}