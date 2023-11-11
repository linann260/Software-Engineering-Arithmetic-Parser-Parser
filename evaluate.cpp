#include <iostream>
#include <math.h>
#include <cmath>
#include <stack>
#include "Evaluate.h"
using namespace std;
//Note: stack of operators and operands are given; operators follow precedence and no parathesis exits

double Evaluate::Solver(stack<char> operators, stack<double> operands) {
    char operation;
    long num1;
    long num2;

    while (!operators.empty()){
        operation = operators.top();
        operators.pop();
        num1 = operands.top();
        operands.pop();
        num2 = operands.top();
        operands.pop();

        if (operation == '+'){
            operands.push(num1 + num2);
        }
        else if (operation == '-'){
            operands.push(num1 - num2);
        }
        else if (operation == '*'){
            operands.push(num1 * num2);
        }
        else if (operation == '/'){
            operands.push(num1 / num2);
        }
        else if (operation == '%'){
            operands.push(num1 % num2);
        }
        else if (operation == '^'){
            operands.push(pow(num1,num2));
        }
    }

    return operands.top();
}

int main() {
    stack<char> operators;
    operators.push('*');
    stack<double> operands;
    operands.push(7);
    operands.push(+15);
    
    Evaluate example1; 
    double result = example1.Solver(operators,operands);
    cout << result << endl;

}