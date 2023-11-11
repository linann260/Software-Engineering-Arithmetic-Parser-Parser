#include <iostream>
using namespace std;
#include <stack>
#ifndef EVALUATE_H
#define EVALUATE_H

//Note: intially assume that inputs are integers
class Evaluate
{
   public:
   std::stack<double> operators; //stack of operands
   std::stack<char> operands; //stack of operators

   //private:
   double Solver(stack<char> operators, stack<double> operands);
};
#endif