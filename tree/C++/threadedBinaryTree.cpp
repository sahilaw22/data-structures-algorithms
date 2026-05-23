#include <iostream>

/* Simple right-threaded binary tree with inorder traversal. */
struct Node {
    int data;
    Node *left;
    Node *right;
    bool rightThread;
};

Node *createNode(int data) {
    Node *node = new Node{data, nullptr, nullptr, true};
    return node;
}

Node *insert(Node *root, int data) {
    Node *parent = nullptr;
    Node *cur = root;

    while (cur) {
        if (data == cur->data) return root;
        parent = cur;
        if (data < cur->data) {
            cur = cur->left;
        } else {
            if (cur->rightThread) break;
            cur = cur->right;
        }
    }

    Node *node = createNode(data);
    if (!parent) return node;

    if (data < parent->data) {
        parent->left = node;
        node->right = parent;
    } else {
        node->right = parent->right;
        parent->right = node;
        parent->rightThread = false;
    }

    return root;
}

Node *leftMost(Node *root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

void inorder(Node *root) {
    Node *cur = leftMost(root);
    while (cur) {
        std::cout << cur->data << " ";
        if (cur->rightThread) {
            cur = cur->right;
        } else {
            cur = leftMost(cur->right);
        }
    }
    std::cout << "\n";
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
    return 0;
}
