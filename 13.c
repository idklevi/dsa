#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
struct Node* create_node(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}
void insert_term(struct Node** head, int coeff, int pow) {
    if (coeff == 0) return; 
    struct Node* newNode = create_node(coeff, pow);
    if (*head == NULL || (*head)->pow < pow) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL && current->pow > pow) {
        prev = current;
        current = current->next;
    }
    if (current != NULL && current->pow == pow) {
        current->coeff += coeff;
        free(newNode);
        if (current->coeff == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
        return;
    }
    newNode->next = current;
    if (prev == NULL) {
        *head = newNode;
    } else {
        prev->next = newNode;
    }
}
void display(struct Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    int first = 1;
    while (poly != NULL) {
        if (!first) {
            if (poly->coeff > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else if (poly->coeff < 0) {
            printf("-");
        } 
        int absCoeff = abs(poly->coeff);
        if (poly->pow == 0 || absCoeff != 1) {
            printf("%d", absCoeff);
        }
        if (poly->pow > 0) {
            printf("x");
            if (poly->pow > 1) {
                printf("^%d", poly->pow);
            }
        }
        poly = poly->next;
        first = 0;
    }
    printf("\n");
}
struct Node* add(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL) {
        insert_term(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insert_term(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}
struct Node* multiply(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    for (struct Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (struct Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int pow = p1->pow + p2->pow;
            insert_term(&result, coeff, pow);
        }
    }
    return result;
}
struct Node* read_poly() {
    struct Node* poly = NULL;
    int n, coeff, pow;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        insert_term(&poly, coeff, pow);
    }
    return poly;
}
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL, *product = NULL;
    printf("\nEnter first polynomial:\n");
    poly1 = read_poly();
    printf("\nEnter second polynomial:\n");
    poly2 = read_poly();
    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    sum = add(poly1, poly2);
    printf("\nSum of Polynomials: ");
    display(sum);
    product = multiply(poly1, poly2);
    printf("Product of Polynomials: ");
    display(product);
    return 0;
}