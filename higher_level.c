#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Layer *init() {

	/*
	숫자 입력 받았다고 가정 후 진행
	숫자 입력은
		1. 전체 layer의 수 (input, output 노드 포함) -> 변수 a에 저장한다고 하자.
		2. a만큼 반복하며 layer의 perceptron 수를 받음
		3. 받은 값만큼 할당
	*/
	int layer_num, *layer_perceptron_num, a, b, c;
	Layer *input_Layer = new_Layer(), *maker_Layer = new_Layer();
	EndLayer *end_Layer = new_EndLayer;


	layer_num = 3;
	layer_perceptron_num = (int *)malloc(sizeof(int) * layer_num);
	layer_perceptron_num[0] = 255;
	layer_perceptron_num[0] = 400;
	layer_perceptron_num[0] = 10;

	input_Layer = sized_Layer(layer_perceptron_num[a], layer_perceptron_num[a + 1]);
	maker_Layer = input_Layer;
	for (a = 1; a < layer_num - 1; a++) {
		maker_Layer->next = sized_Layer(layer_perceptron_num[a], layer_perceptron_num[a + 1]);
		maker_Layer = maker_Layer->next;
	}
	maker_Layer->end = sized_EndLayer(layer_perceptron_num[layer_num - 1]);


}


void propagation(Layer *input_Layer) {


}
