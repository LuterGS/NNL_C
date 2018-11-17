typedef struct matrix {
	int row, col;		//row가 행(가로), col이 열(세로)
	int **matrix;
}Matrix;

typedef struct first_neuralnet {

	Matrix *input_node;

}First_NeuralNet;


//function from data.c
Matrix *new_matrix();
void malloc_matrix(Matrix **input, int row_input, int col_input);


//function from math.c
Matrix *matrix_product(Matrix **first_input, Matrix **second_input);


//function from print.c
void print_matrix(Matrix *input);
