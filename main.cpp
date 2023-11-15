//main file
#include <iostream>
#include <string>
#include <algorithm>
#include "Tokens.h"
#include "Evaluate.h"

using namespace std;

int main(){
   string UserInput;
   cout << "Enter you expression: ";
   getline(cin, UserInput);
   UserInput.erase(std::remove_if(UserInput.begin(), UserInput.end(), ::isspace), UserInput.end());

   Tokens token;
   Evaluate ex1;
   vector<string> expression = token.tokenizer_input(UserInput);
   double result = ex1.evaluateExpression(expression);
   cout << result << endl;

   return 0;
}