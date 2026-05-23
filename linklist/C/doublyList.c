#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list with insert, delete, and forward/backward display. */
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *insertEnd(Node *head, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    if (!head) return node;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    node->prev = cur;
    return head;
}

Node *deleteValue(Node *head, int data) {
    Node *cur = head;
    while (cur && cur->data != data) cur = cur->next;
    if (!cur) return head;

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;

    free(cur);
    return head;
}

void displayForward(Node *head) {
    printf("Forward: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void displayBackward(Node *head) {
    if (!head) {
        printf("Backward: \n");
        return;
    }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    printf("Backward: ");
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

int main(void) {
    Node *head = NULL;
    int choice;

    while (1) {
        printf("\n1.InsertEnd  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            int x;
            printf("Enter value: ");
            scanf("%d", &x);
            head = insertEnd(head, x);
        } else if (choice == 2) {
            int x;
            printf("Enter value to delete: ");
            scanf("%d", &x);
            head = deleteValue(head, x);
        } else if (choice == 3) {
            displayForward(head);
            displayBackward(head);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
