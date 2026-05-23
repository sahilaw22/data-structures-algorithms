#include <stdio.h>
#include <stdlib.h>

/* Sort numbers by inserting into a BST and printing inorder. */
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

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    Node *root = NULL;
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Sorted order: ");
    inorder(root);
    printf("\n");

    return 0;
}
