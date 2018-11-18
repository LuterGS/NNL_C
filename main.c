#include <stdio.h>
#include <Windows.h>
#include "declare.h"

/*
Neural Network Library for C


����ü Linked List�� �����Ϸ� �ߴµ�, input�� hidden�� ���� ����ü�� ����,
input-weight, hidden-weight�� ���� �ϳ��� ����ü�� ��� ����ü linked_list ����� ����
hiddennode���� ������ inputnode���� ���� �͵� (activation_func, error_layer ���)�� �޸𸮸� 0���� �Ҵ��ϰų�
inputnode���� �Ͻ��ϴ� ���� �������ν� �ذ��� �� ���� ������?

�������� answer-outputnode�� ���������� ������ ó�����ִ� �Լ��� �����ϸ�
������ �����ϰ�, �������� �������� �ʰ�, �޸𸮵� �� ���̰� ����.




basic
	reLU = 0;
	...
	-> Activation Function�� Struct�� ���ڷ� ����


������, Windows���� �� �� ������ input�� ���� ����ڰ� ���Ƿ� �����ϸ� �˾Ƽ� ���̺귯���� �ش� OS�� ����� ����ϰԲ� ����


*/


int main() {

	Matrix *test = sized_matrix(2, 3);
	test->matrix[0][0] = 1;
	test->matrix[0][1] = 2;
	test->matrix[0][2] = 3;
	test->matrix[1][0] = 4;
	test->matrix[1][1] = 5;
	test->matrix[1][2] = 6;

	void *test2 = test;
	print_matrix(test2);


	printf("this is 'Neural Network Library for C'\n");
	return 0;

	
}