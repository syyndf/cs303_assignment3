#include <iostream>
#include <stack>
#include <cstring>
#include "Header.h"
using namespace std;

//functions use stack to check the balance
bool isBalanced(string e) {
    stack<char> st;
    for (int i = 0; i < e.length(); i++) {
        if (e [i] == '(' || e[i] == '{' || e [i] == '[') {
            st.push(e [i]);
        } else if (e [i] == ')' || e [i] == '}' || e [i] == ']') {
            if (st.empty()) {
                return false;
            } else if ((e [i] == ')' && st.top() == '(') ||
                       (e [i] == '}' && st.top() == '{') ||
                       (e [i] == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int getOrder(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else
        return 0;
}

//checks and converts inflx to expression
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ' || infix[i] == ',') {
            continue;
        } else if (isOperand(infix[i])) {
            while (isOperand(infix[i])) {
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += " ";
        } else if (isOperator(infix[i])) {
            while (!st.empty() && st.top() != '(' && getOrder(st.top()) >= getOrder(infix[i])) {
                postfix += st.top();
                st.pop();
                postfix += " ";
            }
            st.push(infix[i]);
        } else if (infix[i] == '(') {
            st.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
                postfix += " ";
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
        postfix += " ";
    }

    return postfix;
}
