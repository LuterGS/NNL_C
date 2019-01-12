#include <stdio.h>
#include "declare.h"

double reLU(double input){
      if(input>0){ return input;}
      else {return 0;}
}

double reLU_calculus(double input){
      if(input>0) {return 1;}
      else {return 0;}
}

double Leaky_reLU(double input){
      if(input>0){return input;}
      else {return input/10;}
}

double Leaky_reLU_calculus(double input){
      if(input>0){ return 1;}
      else {return 0.1;}
}

double softmax(double input){
      //fake function for "real" softmax!
}

void real_softmax(EndLayer **input){
      int a;
      double sum_of_perceptron = 0.0;
      
      for(a = 0; a < (*input)->perceptron; a++){
            sum_of_perceptron += (*input)->layer_in->matrix[0][a];
      }
      for(a = 0; a < (*input)->perceptron; a++){
            (*input)->layer_out->matrix[0][a] = (*input)->layer_in->matrix[0][a] / sum_of_perceptron;
      }
}
