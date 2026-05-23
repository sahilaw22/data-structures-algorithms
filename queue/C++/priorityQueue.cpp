#include <iostream>

/* Priority queue using array sorted by priority (lower value is higher priority). */
static const int MAX = 50;

struct Item {
    int data;
    int pr;
};

int main() {
    Item q[MAX];
    int size = 0;
    int choice;

    while (true) {
        std::cout << "\n1.Insert  2.Delete  3.Display  4.Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            int data, pr;
            std::cout << "Enter value and priority (lower number = higher priority): ";
            std::cin >> data >> pr;
            if (size == MAX) {
                std::cout << "Queue full\n";
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
                std::cout << "Queue empty\n";
            } else {
                std::cout << "Deleted: " << q[0].data << " (p=" << q[0].pr << ")\n";
                for (int i = 1; i < size; i++) {
                    q[i - 1] = q[i];
                }
                size--;
            }
        } else if (choice == 3) {
            if (size == 0) {
                std::cout << "Queue empty\n";
            } else {
                std::cout << "Queue: ";
                for (int i = 0; i < size; i++) {
                    std::cout << q[i].data << "(p=" << q[i].pr << ") ";
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
