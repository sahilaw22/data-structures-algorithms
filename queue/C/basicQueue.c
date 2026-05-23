#include <stdio.h>

/* Basic queue using a fixed-size array and menu operations. */
#define MAX 50

int main(void) {
    int q[MAX];
    int front = -1, rear = -1;
    int choice;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Front  4.Display  5.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            int x;
            printf("Enter value: ");
            scanf("%d", &x);
            if (rear == MAX - 1) {
                printf("Queue full\n");
            } else {
                if (front == -1) front = 0;
                q[++rear] = x;
            }
        } else if (choice == 2) {
            if (front == -1 || front > rear) {
                printf("Queue empty\n");
            } else {
                printf("Deleted: %d\n", q[front++]);
            }
        } else if (choice == 3) {
            if (front == -1 || front > rear) {
                printf("Queue empty\n");
            } else {
                printf("Front: %d\n", q[front]);
            }
        } else if (choice == 4) {
            if (front == -1 || front > rear) {
                printf("Queue empty\n");
            } else {
                printf("Queue: ");
                for (int i = front; i <= rear; i++) {
                    printf("%d ", q[i]);
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
