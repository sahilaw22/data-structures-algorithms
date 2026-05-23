#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Evaluate a postfix expression using an integer stack. */
#define MAX 256

int isOperator(const char *t) {
    return strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
           strcmp(t, "*") == 0 || strcmp(t, "/") == 0 ||
           strcmp(t, "%") == 0;
}

int main(void) {
    char line[MAX];
    int stack[MAX];
    int top = -1;

    printf("Enter postfix expression (space separated): ");
    if (!fgets(line, sizeof(line), stdin)) {
        return 1;
    }

    char *token = strtok(line, " \t\n");
    while (token) {
        if (isOperator(token)) {
            if (top < 1) {
                printf("Invalid expression\n");
                return 0;
            }
            int b = stack[top--];
            int a = stack[top--];
            int result = 0;
            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else if (strcmp(token, "/") == 0) result = a / b;
            else if (strcmp(token, "%") == 0) result = a % b;
            stack[++top] = result;
        } else {
            stack[++top] = atoi(token);
        }
        token = strtok(NULL, " \t\n");
    }

    if (top == 0) {
        printf("Result: %d\n", stack[top]);
    } else {
        printf("Invalid expression\n");
    }

    return 0;
}
