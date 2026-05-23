#include <iostream>

/* Basic stack using a fixed-size array and menu operations. */
static const int MAX = 50;

int main() {
    int stack[MAX];
    int top = -1;
    int choice;

    while (true) {
        std::cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            int x;
            std::cout << "Enter value: ";
            std::cin >> x;
            if (top == MAX - 1) {
                std::cout << "Stack full\n";
            } else {
                stack[++top] = x;
            }
        } else if (choice == 2) {
            if (top == -1) {
                std::cout << "Stack empty\n";
            } else {
                std::cout << "Popped: " << stack[top--] << "\n";
            }
        } else if (choice == 3) {
            if (top == -1) {
                std::cout << "Stack empty\n";
            } else {
                std::cout << "Top: " << stack[top] << "\n";
            }
        } else if (choice == 4) {
            if (top == -1) {
                std::cout << "Stack empty\n";
            } else {
                std::cout << "Stack: ";
                for (int i = top; i >= 0; i--) {
                    std::cout << stack[i] << " ";
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
