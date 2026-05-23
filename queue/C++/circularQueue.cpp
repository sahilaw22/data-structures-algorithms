#include <iostream>

/* Circular queue using a fixed-size array. */
static const int MAX = 50;

int main() {
    int q[MAX];
    int n;
    int front = -1, rear = -1;
    int choice;

    std::cout << "Enter queue size (max " << MAX << "): ";
    if (!(std::cin >> n) || n <= 0 || n > MAX) return 1;

    while (true) {
        std::cout << "\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            int x;
            std::cout << "Enter value: ";
            std::cin >> x;
            if ((front == 0 && rear == n - 1) || (rear + 1) % n == front) {
                std::cout << "Queue full\n";
            } else {
                if (front == -1) front = 0;
                rear = (rear + 1) % n;
                q[rear] = x;
            }
        } else if (choice == 2) {
            if (front == -1) {
                std::cout << "Queue empty\n";
            } else {
                std::cout << "Deleted: " << q[front] << "\n";
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % n;
                }
            }
        } else if (choice == 3) {
            if (front == -1) {
                std::cout << "Queue empty\n";
            } else {
                int i = front;
                std::cout << "Queue: ";
                while (true) {
                    std::cout << q[i] << " ";
                    if (i == rear) break;
                    i = (i + 1) % n;
                }
                std::cout << "\n";
            }
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
