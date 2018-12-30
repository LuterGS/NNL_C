#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Layer *init(int layer_num, int *layer_perceptron, int *layer_actnum) {

	/*
	layer_num은 신경망 계층수
	layer_perceptron은 신경망 퍼셉트론 정의된 배열수
	layer_actnum은 신경망 각 층의 활성함수 번호 저장된 배열수
	*/
	int a, b, c;
	Layer *output = new_Layer();
	Layer *maker = new_Layer();
	maker = output;

	output = sized_Layer(layer_perceptron[0], layer_perceptron[1], layer_actnum[0]);
	output->pre = null;
	for(a = 1; a < layer_length - 1; a++){
		maker->next = sized_Layer(layer_perceptron[a], layer_perceptron[a+1], layer_actnum[a]);
		maker->next->pre = maker;
		maker = maker->next;
	}
	maker->end = sized_EndLayer(layer_perceptron[layer_length-2], layer_actnum[layer_length-2]);
	maker->end->pre = maker;
	
	return output;		//maker로 생성되는지 검증 필요
}


void propagation(Layer **input, int layer_num) {

	int a;
	Layer *locator = (*input);
	
	for(a = 0; a < layer_num-2; a++){
		m_product_pointer(&(locator->next->layer), &(locator->weight), &(locator->layer));
		locator = locator->next;
		do_actfunc(&locator);
	}
	m_product_pointer(&(locator->end->layer), &(locator->weight), &(locator->layer));
	do_actfunc_end(&(locator->end));

}

void sgd_training(Layer **first, EndLayer **last, int layer_num, Matrix **input_data, Matrix ***answer_data, int data_length){
	
	int a;
	
	for(a = 0; a < data_length; a++){
		(*first)->layer = (*input_data)[a];
		(*last)->answer_layer = (*answer_data)[a];
		propagation(first, layer_num);
		do_error_func(last);
		set_error_layer(last, layer_num);
		weight_update(last, layer_num, learning_rate);
	}
}

void batch_training(Layer **first, EndLayer **last, int layer_num, Matrix **input_data, Matrix ***answer_data, int data_length){
	
	int a;
	Matrix **temp_weight = new_temp_weight(first, layer_num);
	
	for(a = 0; a < data_length; a++){
		(*first)->layer = (*input_data)[a];
		(*last)->answer_layer = (*answer_data)[a];
		propagation(first, layer_num);
		do_error_func(last);
		set_error_layer(last, layer_num);
		temp_weight_update(last, &temp_weight, layer_num, learning_rate);
	}
	temp_weight_multiple(&temp_weight, layer_num, 1/data_length);
	add_weight(first, &temp_weight, layer_num);
}

void minibatch_training(Layer **first, EndLayer **last, int layer_num, Matrix **input_data, Matrix ***answer_data, int data_length, int epoch){
	
	int a, b, c = 0;
	Matrix **temp_weight = new_temp_weight(first, layer_num);
	
	for(a = 0; a < data_length/epoch; a++){
		temp_weight_nultiple(&temp_weight, layer_num, 0.0);
		for(b = 0; b < epoch; b++; c++){
			(*first)->layer = (*input_data)[c];
			(*last)->answer_layer = (*answer_data)[c];
			propagation(first, layer_num);
			do_error_func(last);
			set_error_layer(last, layer_num);
			temp_weight_update(last, &temp_weight, layer_num, learning_rate);
		}	
		temp_weight_multiple(&temp_weight, layer_num, 1/epoch);
		add_weight(first, &temp_weight, layer_num);
	}
}


}
