#include <iostream>

/* Shell sort using gap reduction by half. */
int main() {
    int n;
    int arr[100];

    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n <= 0 || n > 100) return 1;

    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    std::cout << "Sorted: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
