#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Matrix *new_matrix() {

	Matrix *return_matrix = (Matrix *)malloc(sizeof(Matrix));
	return_matrix->col = 0;
	return_matrix->row = 0;
	return return_matrix;
}

Matrix *sized_matrix(int row_input, int col_input) {

	Matrix *return_matrix = new_matrix();
	malloc_matrix(&return_matrix, row_input, col_input);
	return return_matrix;
}


Layer *new_Layer() {

	Layer *return_Layer = (Layer *)malloc(sizeof(Layer));
	return_Layer->activation_func = 0;
	return_Layer->perceptron = 0;
	return return_Layer;
}

Layer *sized_Layer(int input_perceptron, int input_next_perceptron) {

	Layer *return_Layer = new_Layer();
	return_Layer->perceptron = input_perceptron;
	return_Layer->layer = sized_matrix(1, input_perceptron);
	return_Layer->weight = sized_matrix(input_perceptron, input_next_perceptron);
	return return_Layer;
}

EndLayer *new_EndLayer() {

	EndLayer *return_Layer = (EndLayer *)malloc(sizeof(EndLayer));
	return_Layer->activation_func = 0;
	return_Layer->perceptron = 0;
	return return_Layer;
}

EndLayer *sized_EndLayer(int input_perceptron) {

	EndLayer *return_EndLayer = new_EndLayer();
	return_EndLayer->layer = sized_matrix(1, input_perceptron);
	return_EndLayer->answer_layer = sized_matrix(1, input_perceptron);
	return_EndLayer->error_layer = sized_matrix(1, input_perceptron);
	return return_EndLayer;
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
