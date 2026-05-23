#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Convert prefix expression to postfix using a string stack. */
#define MAX 256
#define STRMAX 512

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main(void) {
    char prefix[MAX];
    char stack[STRMAX][STRMAX];
    int top = -1;

    printf("Enter prefix expression (no spaces): ");
    if (!fgets(prefix, sizeof(prefix), stdin)) return 1;

    int len = (int)strlen(prefix);
    while (len > 0 && (prefix[len - 1] == '\n' || prefix[len - 1] == '\r')) {
        prefix[--len] = '\0';
    }

    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ' || c == '\t') continue;
        if (isOperator(c)) {
            if (top < 1) {
                printf("Invalid expression\n");
                return 0;
            }
            char a[STRMAX];
            char b[STRMAX];
            strcpy(a, stack[top--]);
            strcpy(b, stack[top--]);
            char temp[STRMAX];
            snprintf(temp, sizeof(temp), "%s%s%c", a, b, c);
            strcpy(stack[++top], temp);
        } else {
            char temp[2];
            temp[0] = c;
            temp[1] = '\0';
            strcpy(stack[++top], temp);
        }
    }

    if (top == 0) {
        printf("Postfix: %s\n", stack[top]);
    } else {
        printf("Invalid expression\n");
    }

    return 0;
}
