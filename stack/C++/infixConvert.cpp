#include <iostream>
#include <string>

/* Convert infix expression to postfix and prefix using an array stack. */
static bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

static int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

static bool isRightAssoc(char op) {
    return op == '^';
}

static std::string toPostfix(const std::string &infix) {
    char stack[256];
    int top = -1;
    std::string out;

    for (char c : infix) {
        if (c == ' ' || c == '\t' || c == '\n') continue;
        if (isOperand(c)) {
            out.push_back(c);
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                out.push_back(stack[top--]);
            }
            if (top >= 0 && stack[top] == '(') top--;
        } else {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && !isRightAssoc(c)))) {
                out.push_back(stack[top--]);
            }
            stack[++top] = c;
        }
    }
    while (top >= 0) out.push_back(stack[top--]);
    return out;
}

static std::string toPrefix(const std::string &infix) {
    std::string reversed;
    reversed.reserve(infix.size());
    for (int i = (int)infix.size() - 1; i >= 0; i--) {
        char c = infix[i];
        if (c == '(') reversed.push_back(')');
        else if (c == ')') reversed.push_back('(');
        else reversed.push_back(c);
    }

    std::string postfix = toPostfix(reversed);
    std::string prefix(postfix.rbegin(), postfix.rend());
    return prefix;
}

int main() {
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);

    std::string postfix = toPostfix(infix);
    std::string prefix = toPrefix(infix);

    std::cout << "Postfix: " << postfix << "\n";
    std::cout << "Prefix: " << prefix << "\n";
    return 0;
}
