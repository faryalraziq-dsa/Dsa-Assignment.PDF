#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 This function uses stack to check balanced brackets.
 Whenever an opening bracket appears, it is pushed into the stack.
 When a closing bracket appears, the top element is checked.
 If brackets match correctly, the stack pops the opening bracket.
 At the end, if stack becomes empty, brackets are balanced.
*/
bool isBalanced(string expr) {
    stack<char> s;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) {
                return false;
            }
            char topChar = s.top();
            if ((ch == ')' && topChar == '(') ||
                (ch == ']' && topChar == '[') ||
                (ch == '}' && topChar == '{')) {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string exp1 = "(a+[b*(c+d)])";
    string exp2 = "{a+(b-[c]}";

    if (isBalanced(exp1)) {
        cout << "Expression 1 is Balanced" << endl;
    } else {
        cout << "Expression 1 is Not Balanced" << endl;
    }

    if (isBalanced(exp2)) {
        cout << "Expression 2 is Balanced" << endl;
    } else {
        cout << "Expression 2 is Not Balanced" << endl;
    }

    return 0;
}
