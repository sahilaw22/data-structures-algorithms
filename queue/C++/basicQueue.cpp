#include <iostream>

/* Basic queue using a fixed-size array and menu operations. */
static const int MAX = 50;

int main() {
    int q[MAX];
    int front = -1, rear = -1;
    int choice;

    while (true) {
        std::cout << "\n1.Enqueue  2.Dequeue  3.Front  4.Display  5.Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            int x;
            std::cout << "Enter value: ";
            std::cin >> x;
            if (rear == MAX - 1) {
                std::cout << "Queue full\n";
            } else {
                if (front == -1) front = 0;
                q[++rear] = x;
            }
        } else if (choice == 2) {
            if (front == -1 || front > rear) {
                std::cout << "Queue empty\n";
            } else {
                std::cout << "Deleted: " << q[front++] << "\n";
            }
        } else if (choice == 3) {
            if (front == -1 || front > rear) {
                std::cout << "Queue empty\n";
            } else {
                std::cout << "Front: " << q[front] << "\n";
            }
        } else if (choice == 4) {
            if (front == -1 || front > rear) {
                std::cout << "Queue empty\n";
            } else {
                std::cout << "Queue: ";
                for (int i = front; i <= rear; i++) {
                    std::cout << q[i] << " ";
                }
                std::cout << "\n";
            }
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
