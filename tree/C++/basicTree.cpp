#include <iostream>

/* Basic binary search tree with inorder, preorder, and postorder traversals. */
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

void preorder(Node *root) {
    if (!root) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

int main() {
    int n;
    std::cout << "Enter number of nodes: ";
    if (!(std::cin >> n)) return 1;

    Node *root = nullptr;
    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        root = insert(root, x);
    }

    std::cout << "Inorder: ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Preorder: ";
    preorder(root);
    std::cout << "\n";

    std::cout << "Postorder: ";
    postorder(root);
    std::cout << "\n";

    return 0;
}
