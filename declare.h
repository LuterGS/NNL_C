typedef struct matrix {
	int row, col;		//row가 행(가로), col이 열(세로)
	double **matrix;
}Matrix;


typedef struct layer {

	int perceptron;			//레이어 별 퍼셉트론 개수
	double(*activation_func)(double);		//활성함수 포인터변수
	double(*activation_func_calculus)(double);	//미분된 활성함수 포인터변수 (for backpropagation)
	Matrix *layer_in;		//한 layer에 있는 1 x n 크기의 layer (before actfunc layer)
	Matrix *layer_out;		//after actfunc layer
	Matrix *error_layer;		//한 layer에 있는 오차크기 저장 layer (for backpropagation)
	Matrix *bias;			//한 layer 뒤에 있는 weight의 bias (추후에 다른 알고리즘 방식으로 수정 가능)
	Matrix *weight;			//한 layer 뒤에 있는 weight
	struct layer *next, *pre;	//한 layer,weight 계층 앞뒤의 layer (double linked-list를 위한 방식)
	struct endlayer *end;		//마지막 layer를 향할 때만 쓰는 end;

}Layer;

typedef struct endlayer {

	int perceptron;
	double(*error_func)(double,double);		//마지막 layer의 오차함수 포인터변수
	double(*activation_func)(double);		//활성함수 포인터변수
	double(*activation_func_calculus)(double);	//미분된 활성함수 포인터변수 (for backpropagation)
	Matrix *layer_in;		//한 layer에 있는 1 x n 크기의 layer (before actfunc layer)
	Matrix *layer_out;		//after actfunc layer
	Matrix *error_layer;		//한 layer에 있는 오차크기 저장 layer (for backpropagation)
	Matrix *answer_layer;		//신경망의 answer_layer;
	struct layer *pre;		//double linked-list로 묶기 
}EndLayer;


//function from data_alloc.c
Matrix *new_matrix();
Matrix *sized_matrix(int, int);
Layer *new_Layer();
Layer *sized_Layer(int, int, int);
EndLayer *new_EndLayer();
EndLayer *sized_EndLayer(int, int);
Matrix **new_temp_weight(Matrix ***, double);
void malloc_matrix(Matrix **, int, int);

//function from matrix_math.c
void m_product_pointer(Matrix **, Matrix **, Matrix **);
Matrix *m_product_fb(Matrix *, Matrix *);
void m_product_fb_error(Matrix **, Matrix *, Matrix **);
void m_multiple_pointer(Matrix **, double);
Matrix *m_multiple_fb(Matrix *, double);
void m_plus_pointer(Matrix **, Matrix **);
void m_plus_fb(Matrix **, Matrix *);
Matrix *m_linear_product(Matrix **, Matrix *);
Matrix *m_transpose(Matrix **);
int m_pmchecker(Matrix **, Matrix **);

//function from math.c
double reLU(double);
double reLU_calculus(double);
double Leaky_reLU(double);
double Leaky_reLU_calculus(double);
double softmax(double);
void real_softmax(EndLayer **);

//function from set_network.c
void set_actfunc(Layer **, int);
void set_actfunc_end(EndLayer **, int);
EndLayer *find_EndLayer(Layer **, int);

//function from training.c
void do_actfunc(Layer **);
void do_actfunc_end(EndLayer **);
Matrix *do_actfunc_calculus(Layer **);
Matrix *do_actfunc_calculus_end(EndLayer **);
void set_error_layer(EndLayer **, int);
void weight_update(EndLayer **, int, double);
void temp_weight_update(EndLayer **, Matrix ***, int, double);
void temp_weight_multiple(Matrix ***, int, double);
void add_weight(Layer **, Matrix ***, int);

//function from higher_level.c
Layer *init(int, int *, int *);
void propagation(Layer **, int);
void sgd_training(Layer **, EndLayer **, int, Matrix ***, Matrix ***, int);
void batch_training(Layer **, EndLayer **, int, Matrix ***, Matrix ***, int);
void minibatch_training(Layer **, EndLayer **, int, Matrix ***, Matrix ***, int, int);
