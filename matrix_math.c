#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void m_product_pointer(Matrix **output, Matrix **first_input, Matrix **second_input){
	
	int a,b,c;
	
	for(a = 0; a < (*first_input)->col; a++){
		for(b = 0; b < (*second_input)->row; b++){
			for(c = 0; c < (*first_input)->row; c++){
				(*output)->matrix[b][a] = (*first_input)->matrix[c][a] * (*second_input)->matrix[b][c];
			}
		}
	}
}

Matrix *m_product_fb(Matrix *first_input, Matrix *second_input){
	
	int a,b,c;		//checker 필요
	Matrix *output = sized_matrix(second_input->row, first_input->col);
	
	for(a = 0; a < first_input->col; a++){
		for(b = 0; b < second_input->row; b++){
			for(c = 0; c < first_input->row; c++){
				output->matrix[b][a] = first_input->matrix[c][a] * second_input->matrix[b][c];
			}
		}
	}
	
	return output;
}

void m_product_fb_error(Matrix **output, Matrix *first_input, Matrix **second_input){
	
	int a,b,c;		//checker 필요
	
	for(a = 0; a < first_input->col; a++){
		for(b = 0; b < (*second_input)->row; b++){
			for(c = 0; c < first_input->row; c++){
				(*output)->matrix[b][a] = first_input->matrix[c][a] * (*second_input)->matrix[b][c];
			}
		}
	}
}

void m_multiple_pointer(Matrix **output, double input){
	
	int a, b;
	
	for(a = 0; a < (*output)->col; a++){
		for(b = 0; b < (*output)->row; b++){
			(*output)->matrix[a][b] *= input;
		}
	}
}

Matrix *m_multiple_fb(Matrix *output, double input){
	
	int a, b;
	
	for(a = 0; a < output->col; a++){
		for(b = 0; b < output->row; b++){
			output->matrix[a][b] *= input;
		}
	}
	
	return output;
}

void m_plus_pointer(Matrix **output, Matrix **input){
	
	int a, b;
	
	for(a = 0; a < (*output)->col; a++){
		for(b = 0; b < (*output)->row; b++){
			(*output)->matrix[a][b] += (*input)->matrix[a][b];
		}
	}
}

void m_plus_fb(Matrix **output, Matrix *input){
	
	int a, b;
	
	for(a = 0; a < (*output)->col; a++){
		for(b = 0; b < (*output)->row; b++){
			(*output)->matrix[a][b] += input->matrix[a][b];
		}
	}
}

Matrix *m_linear_product(Matrix **first_input, Matrix *second_input){
	
	int a, b;
	Matrix *output = sized_matrix((*first_input)->row, (*first_input)->col);
	
	for(a = 0; a < (*first_input)->col; a++){
		for(b = 0; b < (*first_input)->row; b++){
			output->matrix[a][b] = (*first_input)->matrix[a][b] * second_input->matrix[a][b];
		}
	}

	return output;
}

Matrix *m_transpose(Matrix **input){
	
	int a, b;
	Matrix *output = sized_matrix((*input)->col, (*input)->row);
	
	for(a = 0; a < (*input)->col; a++){
		for(b = 0; b < (*input)->row; b++){
			output->matrix[a][b] = (*input)->matrix[b][a];
		}
	}
	
	return output;
}

int m_pmchecker(Matrix **first_input, Matrix **second_input){	//0 is false, 1 is true
	
	if(((*first_input)->row == (*second_input)->row_ && ((*first_input)->col == (*second_input)->col)){
		return 1;
	}else{
		return 0;
	}
}
	
