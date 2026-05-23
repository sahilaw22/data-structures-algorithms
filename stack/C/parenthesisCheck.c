#include <stdio.h>
#include <string.h>

/* Check balanced parentheses using an array stack. */
#define MAX 256

int isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

int isClosing(char c) {
    return c == ')' || c == '}' || c == ']';
}

int matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main(void) {
    char input[MAX];
    char stack[MAX];
    int top = -1;
    int i;

    printf("Enter expression: ");
    if (!fgets(input, sizeof(input), stdin)) {
        return 1;
    }

    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (isOpening(c)) {
            if (top == MAX - 1) {
                printf("Not Correct\n");
                return 0;
            }
            stack[++top] = c;
        } else if (isClosing(c)) {
            if (top < 0 || !matches(stack[top], c)) {
                printf("Not Correct\n");
                return 0;
            }
            top--;
        }
    }

    if (top == -1) {
        printf("Correct\n");
    } else {
        printf("Not Correct\n");
    }

    return 0;
}
