#include <iostream>
#include <math.h>
#include <cmath>
#include <stack>
#include <vector>
#include "Evaluate.h"
using namespace std;
//Note: stack of operators and operands are given; operators follow precedence and no parathesis exits

void Evaluate::CreateStack(char expression, stack<char> &operators, stack<double> &operands){
    for (int i = 0; i < expression.size(), i++){
        if (!is_operator(expression[i])){
            operands.push(expression[i])
        }

        else if (expression[i] == "("){
            operators.push(expression[i])
        }

        else if (expression[i] == ")"){
            ParenthesesHandler(operators, operands); //does the math in the parentheses
            }
        
        else if (is_operator(expression[i])){
            OperatorPrecedence(expression[i], operators, operands); //does the math so that operators in stack follow precedence
            operators.push(expresion[i])//then adds the current operator to operators
        }
    }
}

bool Evaluate::isOperator(char expression):
    if (expression == "+" || expression == "-" || expression == "*" || expression == "/" || expression == "%" || expression == "^"){
        return true
    }

    else (){
        return false
    }

void Evaluate::ParenthesesHandler(stack<char> &operators, stack<double> &operands) {
    char operation;
    long num1;
    long num2;

    while (operators.top() != "("){ //does all the math in the parentheses
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

    operands.pop(); //removes "("
}

void Evaluate::OperatorPrecedence(char expression, stack<char> &operators, stack<double> &operands) {
    char operation;
    long num1;
    long num2;

    while (getPrecedence(operators.top()) >= getPrecedence(expression)){ //does math until operators follow order of precedence
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
}

int Evaluate::getPrecedence(char expression){
    if expression == "^"{
        return 3
    }

    else if expression == "*" || expression == "/" || expression == "%"{
        return 2
    }

    else if expression == "+" || expression == "-"{
        return 1
    }
}

double Evaluate::SimplyRemainding(stack<char> &operators, stack<double> &operands) {
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

double Evaluate:: Solve(char expression){
    stack<char> operators;
    stack<double> operands;

    CreateStack(expression, operators, operands);
    result = SimplyRemainding(operators, operands);

}

int main() {
    /*
    stack<char> operators;
    operators.push('*');
    stack<double> operands;
    operands.push(7);
    operands.push(+15);
    
    Evaluate example1; 
    double result = example1.Solver(operators,operands);
    cout << result << endl;
    */
}