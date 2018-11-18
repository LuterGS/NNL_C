typedef struct matrix {
	int row, col;		//row가 행(가로), col이 열(세로)
	double **matrix;
}Matrix;

typedef struct weight {

	Matrix *weight;


}Weight;

typedef struct inputnode{

	int perceptron;
	Matrix *layer;
	Weight *next_weight;

}InputNode;

typedef struct hiddennode {

	int perceptron, activation_func;
	Matrix *layer, *error_layer, *bias;
	Weight *pre_weight, *next_weight;

}HiddenNode;

typedef struct outputnode {

	int perceptron;
	Matrix *layer, *answer;
	Weight *pre_weight;

}OutputNode;





//function from data.c
Matrix *sized_matrix(int row_input, int col_input);
Matrix *new_matrix();
void malloc_matrix(Matrix **input, int row_input, int col_input);


//function from math.c
Matrix *matrix_product(Matrix **first_input, Matrix **second_input);
Matrix *matrix_transpose(Matrix **input);
double reLU(double input);


//function from print.c
void print_matrix(Matrix *input);
