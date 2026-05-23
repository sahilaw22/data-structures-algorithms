#include <stdio.h>

/* Priority queue using array sorted by priority (lower value is higher priority). */
#define MAX 50

typedef struct {
    int data;
    int pr;
} Item;

int main(void) {
    Item q[MAX];
    int size = 0;
    int choice;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            int data, pr;
            printf("Enter value and priority (lower number = higher priority): ");
            scanf("%d %d", &data, &pr);
            if (size == MAX) {
                printf("Queue full\n");
                continue;
            }
            int i = size - 1;
            while (i >= 0 && q[i].pr > pr) {
                q[i + 1] = q[i];
                i--;
            }
            q[i + 1].data = data;
            q[i + 1].pr = pr;
            size++;
        } else if (choice == 2) {
            if (size == 0) {
                printf("Queue empty\n");
            } else {
                printf("Deleted: %d (p=%d)\n", q[0].data, q[0].pr);
                for (int i = 1; i < size; i++) {
                    q[i - 1] = q[i];
                }
                size--;
            }
        } else if (choice == 3) {
            if (size == 0) {
                printf("Queue empty\n");
            } else {
                printf("Queue: ");
                for (int i = 0; i < size; i++) {
                    printf("%d(p=%d) ", q[i].data, q[i].pr);
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
