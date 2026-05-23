#include <iostream>

/* Ordered linked list with sorted insert and delete. */
struct Node {
    int data;
    Node *next;
};

Node *insertSorted(Node *head, int data) {
    Node *node = new Node{data, nullptr};
    if (!head || data < head->data) {
        node->next = head;
        return node;
    }
    Node *cur = head;
    while (cur->next && cur->next->data <= data) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node *deleteValue(Node *head, int data) {
    if (!head) return head;
    if (head->data == data) {
        Node *tmp = head->next;
        delete head;
        return tmp;
    }
    Node *cur = head;
    while (cur->next && cur->next->data != data) cur = cur->next;
    if (cur->next) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
    return head;
}

void display(Node *head) {
    std::cout << "List: ";
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    Node *head = nullptr;
    int choice;

    while (true) {
        std::cout << "\n1.Insert  2.Delete  3.Display  4.Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            int x;
            std::cout << "Enter value: ";
            std::cin >> x;
            head = insertSorted(head, x);
        } else if (choice == 2) {
            int x;
            std::cout << "Enter value to delete: ";
            std::cin >> x;
            head = deleteValue(head, x);
        } else if (choice == 3) {
            display(head);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
