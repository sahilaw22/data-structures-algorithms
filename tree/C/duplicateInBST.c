#include <stdio.h>
#include <stdlib.h>

/* Find duplicate values in a BST by counting insertions. */
typedef struct Node {
    int data;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int data) {
    if (!root) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->count = 1;
        node->left = node->right = NULL;
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
        printf("%d (count=%d)\n", root->data, root->count);
    }
    printDuplicates(root->right);
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

    printf("Duplicates:\n");
    printDuplicates(root);

    return 0;
}
