#include <iostream>

/* Doubly linked list with insert, delete, and forward/backward display. */
struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *insertEnd(Node *head, int data) {
    Node *node = new Node{data, nullptr, nullptr};
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

    delete cur;
    return head;
}

void displayForward(Node *head) {
    std::cout << "Forward: ";
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

void displayBackward(Node *head) {
    if (!head) {
        std::cout << "Backward: \n";
        return;
    }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    std::cout << "Backward: ";
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->prev;
    }
    std::cout << "\n";
}

int main() {
    Node *head = nullptr;
    int choice;

    while (true) {
        std::cout << "\n1.InsertEnd  2.Delete  3.Display  4.Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            int x;
            std::cout << "Enter value: ";
            std::cin >> x;
            head = insertEnd(head, x);
        } else if (choice == 2) {
            int x;
            std::cout << "Enter value to delete: ";
            std::cin >> x;
            head = deleteValue(head, x);
        } else if (choice == 3) {
            displayForward(head);
            displayBackward(head);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
