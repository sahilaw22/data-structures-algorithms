#include <stdio.h>
#include <string.h>

/* Convert infix expression to postfix and prefix using an array stack. */
#define MAX 256

int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssoc(char op) {
    return op == '^';
}

void toPostfix(const char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ' ' || c == '\t' || c == '\n') continue;
        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') top--;
        } else {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && !isRightAssoc(c)))) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top >= 0) postfix[k++] = stack[top--];
    postfix[k] = '\0';
}

void reverseAndSwap(const char *infix, char *out) {
    int len = (int)strlen(infix);
    int k = 0;
    for (int i = len - 1; i >= 0; i--) {
        char c = infix[i];
        if (c == '(') out[k++] = ')';
        else if (c == ')') out[k++] = '(';
        else out[k++] = c;
    }
    out[k] = '\0';
}

void toPrefix(const char *infix, char *prefix) {
    char reversed[MAX];
    char postfix[MAX];
    reverseAndSwap(infix, reversed);
    toPostfix(reversed, postfix);
    int len = (int)strlen(postfix);
    for (int i = 0; i < len; i++) {
        prefix[i] = postfix[len - 1 - i];
    }
    prefix[len] = '\0';
}

int main(void) {
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];

    printf("Enter infix expression: ");
    if (!fgets(infix, sizeof(infix), stdin)) return 1;

    toPostfix(infix, postfix);
    toPrefix(infix, prefix);

    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
