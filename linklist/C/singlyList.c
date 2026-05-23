#include <stdio.h>
#include <stdlib.h>

/* Singly linked list with insert, delete, and display. */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insertEnd(Node *head, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (!head) return node;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    return head;
}

Node *deleteValue(Node *head, int data) {
    if (!head) return head;
    if (head->data == data) {
        Node *tmp = head->next;
        free(head);
        return tmp;
    }
    Node *cur = head;
    while (cur->next && cur->next->data != data) cur = cur->next;
    if (cur->next) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
    }
    return head;
}

void display(Node *head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
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
            display(head);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
