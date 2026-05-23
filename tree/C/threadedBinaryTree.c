#include <stdio.h>
#include <stdlib.h>

/* Simple right-threaded binary tree with inorder traversal. */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int rightThread;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->rightThread = 1;
    return node;
}

Node *insert(Node *root, int data) {
    Node *parent = NULL;
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
        parent->rightThread = 0;
    }

    return root;
}

Node *leftMost(Node *root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

void inorder(Node *root) {
    Node *cur = leftMost(root);
    while (cur) {
        printf("%d ", cur->data);
        if (cur->rightThread) {
            cur = cur->right;
        } else {
            cur = leftMost(cur->right);
        }
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 1;

    Node *root = NULL;
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder: ");
    inorder(root);
    return 0;
}
