#include <iostream>

/* Sort numbers by inserting into a BST and printing inorder. */
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int data) {
    if (!root) {
        Node *node = new Node{data, nullptr, nullptr};
        return node;
    }
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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

    std::cout << "Sorted order: ";
    inorder(root);
    std::cout << "\n";
    return 0;
}
