#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

//check balance
bool isBalanced(string e);

bool isOperand(char c);

bool isOperator(char c);

int getOrder(char c);

string infixToPostfix(string infix);
