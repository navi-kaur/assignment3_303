#pragma once 
#include <string> 
#include <iostream>
#include <stack>
using namespace std;

//expression manager class with the public + private attributes and functions
class ExpressionManager {
public:
    void readInfix();
    bool checkIfValid();
    void convertToPostfix();
    string getMessage();

private:
    string message;
    int getPriority(char c);
    bool is_operator(char c);
    void process_operator(char c, stack<char>& stack, string& postfix);
};

