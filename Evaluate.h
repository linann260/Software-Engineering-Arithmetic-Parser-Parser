#include <iostream>
#include <stack>
using namespace std;
#ifndef EVALUATE_H
#define EVALUATE_H

//Note: intially assume that inputs are integers
class Evaluatex
{
   public:
   char expression; //vector

   //private:
   void MakeStack(char expression, stack<char> &operators, stack<double> &operands);
   bool isOperator(char expression);
   void ParenthesesHandler(stack<char> &operators, stack<double> &operands);
   void OperatorPrecedence(char expression, stack<char> &operators, stack<double> &operands);
   int getPrecedence(char expression);
   double SimplyRemainding(stack<char> operators, stack<double> operands);
   double Solve(char expression);
};
#endif