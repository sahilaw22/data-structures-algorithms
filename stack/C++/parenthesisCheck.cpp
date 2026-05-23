#include <iostream>
#include <string>

/* Check balanced parentheses using an array stack. */
static bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

static bool isClosing(char c) {
    return c == ')' || c == '}' || c == ']';
}

static bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    std::string input;
    std::cout << "Enter expression: ";
    std::getline(std::cin, input);

    char stack[256];
    int top = -1;

    for (char c : input) {
        if (isOpening(c)) {
            if (top == 255) {
                std::cout << "Not Correct\n";
                return 0;
            }
            stack[++top] = c;
        } else if (isClosing(c)) {
            if (top < 0 || !matches(stack[top], c)) {
                std::cout << "Not Correct\n";
                return 0;
            }
            top--;
        }
    }

    std::cout << (top == -1 ? "Correct\n" : "Not Correct\n");
    return 0;
}
