// Postfix evaluation in C++ 

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to evaluate the postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> st;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            // Push the digit value onto the stack
            st.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Pop two operands
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            int val;
            switch (ch) {
                case '+':
                    val = b + a;
                    break;
                case '-':
                    val = b - a;
                    break;
                case '*':
                    val = b * a;
                    break;
                case '/':
                    val = b / a;
                    break;
            }
            // Push the result back onto the stack
            st.push(val);
        }
        // Ignore any other characters (e.g., spaces) for simplicity
    }
    
    // The final result is the top of the stack
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: "; // Example input: "23*54*+9-"
    cin >> postfix;
    
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl; // Output for the example input: "Result: 17"
    
    return 0;
}