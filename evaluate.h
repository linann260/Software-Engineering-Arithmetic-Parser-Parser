#include <iostream>
#include <stack>
#ifndef EVALUATE_H
#define EVALUATE_H
//Note: intially assume that inputs are integers

class Evaluate
{
   public:
   long operators; //stack of operands
   char operands; //stack of operators

   private:
   long Solver(char operators, long operands);
};
#endif