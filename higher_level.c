#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Layer *init() {

	/*
	���� �Է� �޾Ҵٰ� ���� �� ����
	���� �Է���
		1. ��ü layer�� �� (input, output ��� ����) -> ���� a�� �����Ѵٰ� ����.
		2. a��ŭ �ݺ��ϸ� layer�� perceptron ���� ����
		3. ���� ����ŭ �Ҵ�
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
