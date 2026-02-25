#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
    string exp;
    cout << "Enter the expression: ";
    cin >> exp;

    stack<char> s;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.empty()) {
                cout << "Invalid Expression\n";
                return 0;
            }
            s.pop();
        }
    }

    if (s.empty()) {
        cout << "Valid Expression\n";
    } else {
        cout << "Invalid Expression\n";
    }

    return 0;
}