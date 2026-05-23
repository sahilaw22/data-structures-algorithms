#include <iostream>
#include <sstream>
#include <string>

/* Evaluate a postfix expression using an integer stack. */
static bool isOperator(const std::string &t) {
    return t == "+" || t == "-" || t == "*" || t == "/" || t == "%";
}

int main() {
    std::string line;
    std::cout << "Enter postfix expression (space separated): ";
    std::getline(std::cin, line);

    int stack[256];
    int top = -1;

    std::stringstream ss(line);
    std::string token;
    while (ss >> token) {
        if (isOperator(token)) {
            if (top < 1) {
                std::cout << "Invalid expression\n";
                return 0;
            }
            int b = stack[top--];
            int a = stack[top--];
            int result = 0;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;
            else if (token == "%") result = a % b;
            stack[++top] = result;
        } else {
            stack[++top] = std::stoi(token);
        }
    }

    if (top == 0) {
        std::cout << "Result: " << stack[top] << "\n";
    } else {
        std::cout << "Invalid expression\n";
    }

    return 0;
}
