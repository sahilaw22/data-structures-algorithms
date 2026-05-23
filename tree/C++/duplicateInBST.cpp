#include <iostream>

/* Find duplicate values in a BST by counting insertions. */
struct Node {
    int data;
    int count;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int data) {
    if (!root) {
        Node *node = new Node{data, 1, nullptr, nullptr};
        return node;
    }
    if (data == root->data) {
        root->count++;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void printDuplicates(Node *root) {
    if (!root) return;
    printDuplicates(root->left);
    if (root->count > 1) {
        std::cout << root->data << " (count=" << root->count << ")\n";
    }
    printDuplicates(root->right);
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 1;

    Node *root = nullptr;
    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        root = insert(root, x);
    }

    std::cout << "Duplicates:\n";
    printDuplicates(root);
    return 0;
}
