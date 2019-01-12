#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void set_actfunc(Layer **input, int act_num){
    if(act_num == 1){
        (*input)->activation_func = reLU;
        (*input)->activation_func_calculus = reLU_calculus;
    }else if(act_num == 2 ){
        (*input)->activation_func = Leaky_reLU;
        (*input)->activation_func_calculus = Leaky_reLU_calculus;
      ... //미구현
    }
}

void set_actfunc_end(EndLayer **input, int act_num){
    if(act_num == 1){
        (*input)->activation_func = reLU;
        (*input)->activation_func_calculus = reLU_calculus;
    }else if(act_num == 2 ){
        (*input)->activation_func = Leaky_reLU;
        (*input)->activation_func_calculus = Leaky_reLU_calculus;
      ... //미구현
    }
}
//EndLayer의 함수는 무조건 softmax로 되어야 하는 만큼 추가적인 수정이 필요

EndLayer *find_EndLayer(Layer **input, int layer_num){
  
    int a;
    Layer *locator = (*input);
    EndLayer *output;
  
    for(a = 0; a < layer_num - 2; a++){
        locator = locator->next;
    }
    output = locator->end;
  
    return output;
}
