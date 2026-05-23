#include <iostream>
#include <string>

/* Convert prefix expression to postfix using a string stack. */
static bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main() {
    std::string prefix;
    std::cout << "Enter prefix expression (no spaces): ";
    std::getline(std::cin, prefix);

    std::string stack[256];
    int top = -1;

    for (int i = (int)prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ' || c == '\t') continue;
        if (isOperator(c)) {
            if (top < 1) {
                std::cout << "Invalid expression\n";
                return 0;
            }
            std::string a = stack[top--];
            std::string b = stack[top--];
            stack[++top] = a + b + c;
        } else {
            stack[++top] = std::string(1, c);
        }
    }

    if (top == 0) {
        std::cout << "Postfix: " << stack[top] << "\n";
    } else {
        std::cout << "Invalid expression\n";
    }

    return 0;
}
