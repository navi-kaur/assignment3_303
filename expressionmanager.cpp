#include <string> 
#include "ExpressionManager.h";
#include <sstream>
#include <iostream>
using namespace std;

//reads the entire user input
void ExpressionManager::readInfix() {
    cout << "Enter message: ";
    getline(cin, message);
}

//checks if message is valid, the symbols have matching ones, displays message at end indicating if user input is valid or not 
bool ExpressionManager::checkIfValid() {
    stack<char> stack;

    for (int i = 0; i < message.size(); i++) {
        if (message[i] == '(' || message[i] == '{' || message[i] == '[') {
            stack.push(message[i]);
        }
        else if (message[i] != '(' && message[i] != ')' && message[i] != '{' && message[i] != '}' && message[i] != '[' && message[i] != ']') {
            continue;
        }
        else if ((message[i] == ')' && stack.top() == '(') || (message[i] == '}' && stack.top() == '{') || (message[i] == ']' && stack.top() == '[')) {
            stack.pop();
        }
        else {
            cout << "Message is invalid" << endl;
            return false;
        }
    }
    cout << "Message is valid" << endl;
    return true;
}

//converts the user input into post fix notation, part of code taken from notes given in class
void ExpressionManager::convertToPostfix() {
    string postfix = "";
    stack<char> stack;

    istringstream infix_tokens(message);
    string next_token;

    while (infix_tokens >> next_token) {
        if (isalnum(next_token[0])) {
            postfix += next_token;
            postfix += " ";
        }
        else if (is_operator(next_token[0])) {
            process_operator(next_token[0], stack, postfix);
        }
    } // end while

    //pop any remaining operators and add to postfix
    while (!stack.empty()) {
        char op = stack.top();
        stack.pop();
        postfix += op;
        postfix += " ";
    }
    cout << postfix;
}

//gives priority in order of operations
int ExpressionManager::getPriority(char c) {
    if (c == '/' || c == '*' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '(' || c == ')')
        return -1;
    return -2;
}

//returns the message
string ExpressionManager::getMessage() {
    return message;
}

//part of postfix conversion code
bool ExpressionManager::is_operator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '(' || c == ')';
}

//code to add to stack to help convert to postfix conversion
void ExpressionManager::process_operator(char c, stack<char>& stack, string& postfix) {
    if (stack.empty() || (c == '(')) {
        stack.push(c);
    }
    else {
        if (getPriority(c) > getPriority(stack.top())) {
            stack.push(c);
        }
        else {
            // Pop all stacked operators with equal
            // or higher precedence than op.
            while (!stack.empty()
                && (stack.top() != '(')
                && (getPriority(c) <= getPriority(stack.top()))) {
                postfix += stack.top();
                postfix += " ";
                stack.pop();
            }
            // assert: Operator stack is empty or
           //         top of stack is '(' or current
           //         operator precedence > top of stack operator
           //         precedence;
            if (c == ')') {
                if (!stack.empty()
                    && (stack.top() == '(')) {
                    stack.pop();
                }
            }
            else {
                stack.push(c);
            }
        }
    }
}