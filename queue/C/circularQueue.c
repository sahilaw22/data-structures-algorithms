#include <stdio.h>

/* Circular queue using a fixed-size array. */
#define MAX 50

int main(void) {
    int q[MAX];
    int n;
    int front = -1, rear = -1;
    int choice;

    printf("Enter queue size (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            int x;
            printf("Enter value: ");
            scanf("%d", &x);
            if ((front == 0 && rear == n - 1) || (rear + 1) % n == front) {
                printf("Queue full\n");
            } else {
                if (front == -1) front = 0;
                rear = (rear + 1) % n;
                q[rear] = x;
            }
        } else if (choice == 2) {
            if (front == -1) {
                printf("Queue empty\n");
            } else {
                printf("Deleted: %d\n", q[front]);
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % n;
                }
            }
        } else if (choice == 3) {
            if (front == -1) {
                printf("Queue empty\n");
            } else {
                int i = front;
                printf("Queue: ");
                while (1) {
                    printf("%d ", q[i]);
                    if (i == rear) break;
                    i = (i + 1) % n;
                }
                printf("\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
