#include <stdio.h>

/* Basic stack using a fixed-size array and menu operations. */
#define MAX 50

int main(void) {
    int stack[MAX];
    int top = -1;
    int choice;

    while (1) {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            int x;
            printf("Enter value: ");
            scanf("%d", &x);
            if (top == MAX - 1) {
                printf("Stack full\n");
            } else {
                stack[++top] = x;
            }
        } else if (choice == 2) {
            if (top == -1) {
                printf("Stack empty\n");
            } else {
                printf("Popped: %d\n", stack[top--]);
            }
        } else if (choice == 3) {
            if (top == -1) {
                printf("Stack empty\n");
            } else {
                printf("Top: %d\n", stack[top]);
            }
        } else if (choice == 4) {
            if (top == -1) {
                printf("Stack empty\n");
            } else {
                printf("Stack: ");
                for (int i = top; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
