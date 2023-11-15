//tokenizer.cpp
#include <iostream>
#include <vector>
#include <sstream>
#include "Tokens.h"

using namespace std;
vector<string> Tokens::tokenizer_input(const string& UserInput)
{
    vector<string> tokenizer_vector;
    for (int i = 0; i < UserInput.length(); i++){

//If there a number greater than 1 digit
        if ((UserInput[i] == '0' || UserInput[i] == '1' || UserInput[i] == '2' || UserInput[i] == '3' || UserInput[i] == '4' || UserInput[i] == '5' || UserInput[i] == '6' || UserInput[i] == '7' || UserInput[i] == '8' || UserInput[i] == '9' || UserInput[i] == '.')){
            if((UserInput[i + 1] != '\0') && (UserInput[i+1] != ' ') && (UserInput[i+1] == '0' || 
            UserInput[i+1] == '1' || UserInput[i+1] == '2' || UserInput[i+1] == '3' || UserInput[i+1] == '4' || 
            UserInput[i+1] == '5' || UserInput[i+1] == '6' || UserInput[i+1] == '7' || UserInput[i+1] == '8' || 
            UserInput[i+1] == '9' || UserInput[i+1] == '.')){
                    int j = 0;
                    int k = i;
                    while ((UserInput[k] != '\0') && (UserInput[k] == '0' || 
                    UserInput[k] == '1' || UserInput[k] == '2' || UserInput[k] == '3' || 
                    UserInput[k] == '4' || UserInput[k] == '5' || UserInput[k] == '6' || 
                    UserInput[k] == '7' || UserInput[k] == '8' || UserInput[k] == '9' || UserInput[k] == '.')){
                        j++;
                        k++;
                    }

                    tokenizer_vector.push_back(UserInput.substr(i, j));

                    i = i + j -1;
            }

            else{
                tokenizer_vector.push_back(UserInput.substr(i, 1));
            }
        }




//If there is  a '-' or '+' at index 0 eg: '-1+2' or '+5-4'
        else if((UserInput[i] != '\0') && (i == 0) && (UserInput[i] == '-' || UserInput[i] == '+')){
            if((UserInput[i + 1] != '\0') && (UserInput[i+1] == '0' || UserInput[i+1] == '1' || UserInput[i+1] == '2' || UserInput[i+1] == '3' || UserInput[i+1] == '4' || UserInput[i+1] == '5' || UserInput[i+1] == '6' || UserInput[i+1] == '7' || UserInput[i+1] == '8' || UserInput[i+1] == '9' || UserInput[i+1] == '.')){
                int j = 1;
                int k = i + 1;
                while ((UserInput[k] != '\0') && (UserInput[k] == '0' || 
                UserInput[k] == '1' || UserInput[k] == '2' || UserInput[k] == '3' || 
                UserInput[k] == '4' || UserInput[k] == '5' || UserInput[k] == '6' || 
                UserInput[k] == '7' || UserInput[k] == '8' || UserInput[k] == '9' || UserInput[k] == '.')){
                    j++;
                    k++;
                }

                tokenizer_vector.push_back(UserInput.substr(i, j));

                i = i + j -1;
            }

            else{
                tokenizer_vector.push_back(UserInput.substr(i, 1));
            }

        }





//if there is negative numbers inside of a parentheses
        else if(UserInput[i] == '('){

            if((UserInput[i + 1] != '\0') && (UserInput[i + 1] == '-' || UserInput[i + 1] == '+')){
                tokenizer_vector.push_back(UserInput.substr(i, 1));
                if((UserInput[i + 2] != '\0') && (UserInput[i+2] == '0' || UserInput[i+2] == '1' || UserInput[i+2] == '2' || UserInput[i+2] == '3' || UserInput[i+2] == '4' || UserInput[i+2] == '5' || UserInput[i+2] == '6' || UserInput[i+2] == '7' || UserInput[i+2] == '8' || UserInput[i+2] == '9' || UserInput[i+2] == '.')){
                    int j = 1;
                    int k = i + 2;
                    while ((UserInput[k] != '\0') && (UserInput[k] == '0' || 
                    UserInput[k] == '1' || UserInput[k] == '2' || UserInput[k] == '3' || 
                    UserInput[k] == '4' || UserInput[k] == '5' || UserInput[k] == '6' || 
                    UserInput[k] == '7' || UserInput[k] == '8' || UserInput[k] == '9' || UserInput[k] == '.')){
                        j++;
                        k++;
                    }

                    tokenizer_vector.push_back(UserInput.substr(i+1, j));

                    i = i + j;
                }
            }

            else{
                tokenizer_vector.push_back(UserInput.substr(i, 1));
            }
        }



//accounts for inputs which 2 consecutive symbols, eg: 1++3 or +2^-3
        else if(UserInput[i] == '+' || UserInput[i] == '-' || UserInput[i] == '*' || 
        UserInput[i] == '^' || UserInput[i] == '%' || UserInput[i] == '/'){



            if((UserInput[i + 1] != '\0') && (UserInput[i + 1] == '-' || UserInput[i + 1] == '+')){
                tokenizer_vector.push_back(UserInput.substr(i, 1));
                if((UserInput[i + 2] != '\0') && (UserInput[i+2] == '0' || UserInput[i+2] == '1' || UserInput[i+2] == '2' || UserInput[i+2] == '3' || UserInput[i+2] == '4' || UserInput[i+2] == '5' || UserInput[i+2] == '6' || UserInput[i+2] == '7' || UserInput[i+2] == '8' || UserInput[i+2] == '9' || UserInput[i+2] == '.')){
                    int j = 1;
                    int k = i + 2;
                    while ((UserInput[k] != '\0') && (UserInput[k] == '0' || 
                    UserInput[k] == '1' || UserInput[k] == '2' || UserInput[k] == '3' || 
                    UserInput[k] == '4' || UserInput[k] == '5' || UserInput[k] == '6' || 
                    UserInput[k] == '7' || UserInput[k] == '8' || UserInput[k] == '9')){
                        j++;
                        k++;
                    }

                    tokenizer_vector.push_back(UserInput.substr(i+1, j));

                    i = i + j;
                }


                if((UserInput[i + 1] != '\0') && (UserInput[i + 1] == '-' || UserInput[i + 1] == '+')){

                    if (UserInput[i + 1] == '-'){
                        tokenizer_vector.push_back("-1");
                        tokenizer_vector.push_back("*");
                        i = i+1;

                    }

                }
            }



            else{
                tokenizer_vector.push_back(UserInput.substr(i, 1));
            }

        }


//appends to the vector if all the above statments is false
        else{
            tokenizer_vector.push_back(UserInput.substr(i, 1));
        }

    }


 //Iterates through the vector and shows what is stored inside of it, th sis only for the purpose of testing our code
 /*
    for (int i = 0; i < tokenizer_vector.size(); i ++){
        cout << tokenizer_vector[i] << endl;
    }
*/

return tokenizer_vector;



}