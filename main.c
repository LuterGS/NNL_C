#include <stdio.h>
#include <Windows.h>
#include "declare.h"

/*
Neural Network Library for C


구조체 Linked List로 구현하려 했는데, input과 hidden을 같은 구조체를 쓰고,
input-weight, hidden-weight를 같은 하나의 구조체로 묶어서 구조체 linked_list 방법을 쓰고
hiddennode에는 있지만 inputnode에는 없는 것들 (activation_func, error_layer 등등)은 메모리를 0으로 할당하거나
inputnode임을 암시하는 값을 넣음으로써 해결할 수 있지 않을까?

마지막에 answer-outputnode는 마지막에만 별도로 처리해주는 함수만 구현하면
구성도 간편하고, 논리적으로 복잡하지 않고, 메모리도 별 차이가 없다.




basic
	reLU = 0;
	...
	-> Activation Function을 Struct에 숫자로 저장


리눅스, Windows에서 쓸 때 안전한 input을 위해 사용자가 임의로 지정하면 알아서 라이브러리가 해당 OS의 기능을 사용하게끔 구성


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