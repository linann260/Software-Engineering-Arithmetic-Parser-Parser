#include <iostream>
#include <math.h>
#include <cmath>
#include <stack>
#include "evaluate.h"
//Note: stack of operators and operands are given; operators follow precedence and no parathesis exits

template <typename T>
long Solver(char operators, long operands) {
    char operation;
    long num1;
    long num2;

    while (!operators.empty()){
        operation = operators.top();
        operators.pop();
        num1 = operands.top();
        operands.pop();
        num2 = operands.top();
        operands.pop()

        if (operation == '+'){
            operands.push(num1 + num2);
        }
        else if (operation == '-'){
            operands.push(num1 - num2);
        }
        else if (operation == '*'){
            operands.push(num1 * num2)
        }
        else if (operation == '/'){
            operands.push(num1 / num2)
        }
        else if (operation == '%'){
            operands.push(num1 % num2)
        }
        else if (operation == '^'){
            operands.push(num1 ** num2)
        }
    }

    return operands.top();
}
