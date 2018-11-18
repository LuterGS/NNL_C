typedef struct matrix {
	int row, col;		//row가 행(가로), col이 열(세로)
	double **matrix;
}Matrix;


typedef struct layer {

	int perceptron, activation_func;
	Matrix *layer;			//한 layer에 있는 1 x n 크기의 layer
	Matrix *error_layer;		//한 layer에 있는 오차크기 저장 layer (for backpropagation)
	Matrix *bias;			//한 layer 뒤에 있는 weight의 bias (추후에 다른 알고리즘 방식으로 수정 가능)
	Matrix *weight;			//한 layer 뒤에 있는 weight
	struct layer *next;		//한 layer,weight 계층 뒤의 Layer
	struct endlayer *end;		//마지막 layer를 향할 때만 쓰는 end;

}Layer;

typedef struct endlayer {

	int perceptron, activation_func;
	Matrix *layer;			//한 layer에 있는 1 x n 크기의 layer
	Matrix *error_layer;		//한 layer에 있는 오차크기 저장 layer (for backpropagation)
	Matrix *answer_layer;		//신경망의 answer_layer;
}EndLayer;


//function from higher_level.c
Layer *init();
void propagation(Layer *input_Layer);


//function from data.c
Matrix *sized_matrix(int row_input, int col_input);
Matrix *new_matrix();
Layer *new_Layer();
Layer *sized_Layer(int input_perceptron, int input_next_perceptron);
EndLayer *new_EndLayer();
EndLayer *sized_EndLayer(int input_perceptron);
void malloc_matrix(Matrix **input, int row_input, int col_input);


//function from math.c
Matrix *matrix_product(Matrix **first_input, Matrix **second_input);
Matrix *matrix_transpose(Matrix **input);
double reLU(double input);


//function from print.c
void print_matrix(Matrix *input);
