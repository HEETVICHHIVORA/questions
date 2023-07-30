#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int pre(char a);

void convert(string infix) {
    int i = 0;
    string postfix = "";

    stack<char> s;
    while (i < infix.length()) {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
            postfix += infix[i];
            i++;
        } else if (infix[i] == '(') {
            s.push(infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        } else {
            while (!s.empty() && pre(infix[i]) <= pre(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix is : " << postfix << endl; // It will print postfix conversion
}

int pre(char a) {
    if (a == '^') {
        return 3;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

int main() {
    string infix = "((a+(b*c))-d)";
    convert(infix);
    return 0;
}
