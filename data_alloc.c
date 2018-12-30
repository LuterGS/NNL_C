#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Matrix *new_matrix() {

	Matrix *output = (Matrix *)malloc(sizeof(Matrix));
	output->col = 0;
	output->row = 0;
	return output;
}

Matrix *sized_matrix(int row, int col) {

	Matrix *output = new_matrix();
	malloc_matrix(&output, row, col);
	return output;
}


Layer *new_Layer() {

	Layer *output = (Layer *)malloc(sizeof(Layer));
	outputr->activation_func = 0;
	output->perceptron = 0;
	return output;
}

Layer *sized_Layer(int perceptron, int next_perceptron, int activation_num) {

	Layer *output = new_Layer();
	output->perceptron = perceptron;
	output->layer = sized_matrix(1, perceptron);
	output->error_layer = sized_matrix(1, perceptron);
	output->weight = sized_matrix(perceptron, next_perceptron);
	output->bias = sized_matrix(perceptron, next_perceptron);
	set_actfunc(&output, activation_num);	//calculus 버전도 처리
	
	return output;
}

EndLayer *new_EndLayer() {

	EndLayer *output = (EndLayer *)malloc(sizeof(EndLayer));
	output->activation_func = 0;
	output->perceptron = 0;
	return output;
}

EndLayer *sized_EndLayer(int perceptron, int activation_num) {

	EndLayer *output = new_EndLayer();
	output->layer = sized_matrix(1, perceptron);
	output->answer_layer = sized_matrix(1, perceptron);
	output->error_layer = sized_matrix(1, perceptron);
	set_actfunc_end(&output, activation_num);
	
	return output;
}

Matrix **new_temp_weight(Layer **input, int layer_num){
	
	int a;
	Matrix **output = (Matrix**)malloc(sizeof(Matrix**) * layer_num);
	Layer *locator = (*input);
	
	for(a = 0; a < layer_num-2; a++){
		output[a] = sized_matrix(locator->perceptron, locator->next->perceptron);
		locator = locator->next;
	}
	output[a] = sized_matrix(locator->perceptron, locator->end->perceptron);
	
	return output;
}


void malloc_matrix(Matrix **input, int row, int col) {

	int a, b;
	(*input)->row = row;
	(*input)->col = col;

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
