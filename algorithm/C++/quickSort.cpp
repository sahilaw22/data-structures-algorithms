#include <iostream>

/* Quick sort using last element as pivot. */
void swap(int &a, int &b) {
    int t = a; a = b; b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n;
    int arr[100];

    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n <= 0 || n > 100) return 1;

    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
