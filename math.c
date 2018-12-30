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

double square_error(double output, double answer){
      return answer - output;
}
