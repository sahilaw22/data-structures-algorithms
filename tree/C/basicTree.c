#include <stdio.h>
#include <stdlib.h>

/* Basic binary search tree with inorder, preorder, and postorder traversals. */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int data) {
    if (!root) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
