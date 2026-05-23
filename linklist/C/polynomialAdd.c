#include <stdio.h>
#include <stdlib.h>

/* Add two polynomials using linked lists. */
typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *append(Node *head, int coeff, int exp) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;

    if (!head) return node;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    return head;
}

Node *readPoly(void) {
    int n;
    Node *head = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter terms as: coeff exp (descending exp)\n");
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        head = append(head, c, e);
    }
    return head;
}

Node *addPoly(Node *a, Node *b) {
    Node *res = NULL;
    while (a && b) {
        if (a->exp == b->exp) {
            int sum = a->coeff + b->coeff;
            if (sum != 0) res = append(res, sum, a->exp);
            a = a->next;
            b = b->next;
        } else if (a->exp > b->exp) {
            res = append(res, a->coeff, a->exp);
            a = a->next;
        } else {
            res = append(res, b->coeff, b->exp);
            b = b->next;
        }
    }
    while (a) {
        res = append(res, a->coeff, a->exp);
        a = a->next;
    }
    while (b) {
        res = append(res, b->coeff, b->exp);
        b = b->next;
    }
    return res;
}

void printPoly(Node *p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    printf("Polynomial A:\n");
    Node *a = readPoly();
    printf("Polynomial B:\n");
    Node *b = readPoly();

    Node *sum = addPoly(a, b);
    printf("Sum: ");
    printPoly(sum);

    return 0;
}
