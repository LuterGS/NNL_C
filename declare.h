typedef struct matrix {
	int row, col;		//row�� ��(����), col�� ��(����)
	double **matrix;
}Matrix;


typedef struct layer {

	int perceptron, activation_func;
	Matrix *layer;			//�� layer�� �ִ� 1 x n ũ���� layer
	Matrix *error_layer;		//�� layer�� �ִ� ����ũ�� ���� layer (for backpropagation)
	Matrix *bias;			//�� layer �ڿ� �ִ� weight�� bias (���Ŀ� �ٸ� �˰��� ������� ���� ����)
	Matrix *weight;			//�� layer �ڿ� �ִ� weight
	struct layer *next;		//�� layer,weight ���� ���� Layer
	struct endlayer *end;		//������ layer�� ���� ���� ���� end;

}Layer;

typedef struct endlayer {

	int perceptron, activation_func;
	Matrix *layer;			//�� layer�� �ִ� 1 x n ũ���� layer
	Matrix *error_layer;		//�� layer�� �ִ� ����ũ�� ���� layer (for backpropagation)
	Matrix *answer_layer;		//�Ű���� answer_layer;
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
