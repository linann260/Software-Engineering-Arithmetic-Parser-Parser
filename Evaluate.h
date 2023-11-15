#ifndef EVALUATE_H
#define EVALUATE_H

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//Note: intially assume that inputs are integers
class Evaluate
{
  public:
  vector<char> expression; //vector

  //private:
  bool isOperator(string c);
  int getPrecedence(char op);
  double evaluateExpression(const vector<string>& expression);
  double evaluateRemainding(stack<double> & operands, stack<char> & operators);
  /*
  void CreateStack(vector<char> expression, stack<char>* operators, stack<double>* operands);
  bool isOperator(char expression);
  void ParenthesesHandler(stack<char> &operators, stack<double> &operands);
  void OperatorPrecedence(char expression, stack<char> *operators, stack<double> *operands);
  int getPrecedence(char expression);
  double SimplyRemainding(stack<char> &operators, stack<double> &operands);
  double Solve(vector<char> expression);
  */
};

#endif