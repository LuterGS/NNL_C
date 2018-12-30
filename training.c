#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void do_actfunc (Layer **input){
	
	int a;
	
	for(a = 0; a < (*input)->perceptron; a++){
		(*input)->layer->matrix[0][a] = (*input)->activation_func((*input)->layer->matrix[0][a]);
	}
}

void do_actfunc (EndLayer **input){
	
	int a;
	
	for(a = 0; a < (*input)->perceptron; a++){
		(*input)->layer->matrix[0][a] = (*input)->activation_func((*input)->layer->matrix[0][a]);
	}
}

Matrix *do_actfunc_calculus(Layer **input){
	
	int a, b;
	Matrix *output = sized_matrix(1, (*input)->perceptron);
	
	for(a = 0; a < (*input)->perceptron; a++){
		output->matrix[0][a] = (*input)->activation_func_calculus((*input)->layer->matrix[0][a]);
	}
	
	return output;
}

Matrix *do_actfunc_calculus_end(EndLayer **input){
	
	int a, b;
	Matrix *output = sized_matrix(1, (*input)->perceptron);
	
	for(a = 0; a < (*input)->perceptron; a++){
		output->matrix[0][a] = (*input)->activation_func_calculus((*input)->layer->matrix[0][a]);
	}
	
	return output;
}

void do_errfunc(EndLayer **input){
	
	int a;
	
	for(a = 0; a < (*input)->perceptron; a++){
		(*input)->error_layer[0][a] = (*input)->error_func((*input)->layer->matrix[0][a], (*input)->answer_layer->matrix[0][a]);
	}
}

void set_error_layer(EndLayer **input, int layer_num){
	
	int a;
	Layer *locator = (*input)->pre;
	
	m_product_fb_error(&(locator->error_layer),
			   m_transpowe(&(locator->weight)),
			   &(locator->end->error_layer)
			   )
	locator = locator->pre;
	
	for(a = 0; a < layer_num-2; a++){
		m_product_fb_error(&(locator->error_layer),
			   m_transpowe(&(locator->weight)),
			   &(locator->next->error_layer)
			   )
		locator = locator->pre;		//마지막 반복시 null로
	}
}


void weight_update(EndLayer **input, int layer_num, double learning_rate){		//경사하강법 기반 backprop

	int a;
	Layer *locator = (*input)->pre;
	
	m_plus_fb(
		&(locator->weight),
		m_multiple_fb(
			m_product_fb(
				m_linear_product(
					&((*input)->error_layer),
					do_actfunc_calculus_end(input)),
				m_transpose(&(locator->layer))),
			learning_rate));
	locator = locator->pre;
	
	for(a = 0; a < layer_num - 2; a++){
		m_plus_fb(
			&(locator->weight),
			m_multiple_fb(
				m_product_fb(
					m_linear_product(
						&(locator->next->error_layer),
						do_actfunc_calculus_end(&(locator->next))),
					m_transpose(&(locator->layer))),
				learning_rate));
		locator = locator->pre;		//마지막 반복시 null;
	}
}

void *temp_weight_update(EndLayer **input_EndLayer, Matrix ***input, int layer_num, double learning_rate){
	
	int a;
	Layer *locator = (*input_EndLayer)->pre;
	
	m_plus_fb(
		&((*input)[layer_num-2]),
		m_multiple_fb(
			m_product_fb(
				m_linear_product(
					&((*input_EndLayer)->error_layer),
					do_actfunc_calculus_end(input_EndLayer)),
				m_transpose(&(locator->layer))),
			learning_rate));
	locator = locator->pre;
	
	for(a=layer_num-3; a >= 0; a--){
		m_plus_fb(
			&((*input)[a]),
			m_multiple_fb(
				m_product_fb(
					m_linear_product(
						&(locator->next->error_layer),
						do_actfunc_calculus_end(&(locator->next))),
					m_transpose(&(locator->layer))),
				learning_rate));
		locator = locator->pre;		//마지막 반복시 null
	}
}

void add_weight(Layer **input_Layer, Matrix ***input, int layer_num){
	
	int a;
	Layer *locator = (*input_Layer);
	
	for(a = 0; a < layer_num-1; a++){
		m_plus_pointer(&(locator->weight), &((*input)[a]));
		locator = locator->next;	//마지막 반복시 null
	}
}
