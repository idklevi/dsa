#include <stdio.h>

typedef struct {
    int coeff;
    int exp;
} polyterm;



void readpoly(polyterm poly[], int *n) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", n);
    printf("Enter the coefficients and exponents of each term:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }
}

void displaypoly(polyterm poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].coeff != 0) {
            if (poly[i].coeff > 0 && i!= 0) {
                printf("+");
            }
            if (poly[i].coeff != 1 || poly[i].exp == 0) {
                printf("%d", poly[i].coeff);
            }
            if (poly[i].exp > 0) {
                printf("x");
                if (poly[i].exp > 1) {
                    printf("^%d", poly[i].exp);
                }
            }
        }
    }
    printf("\n");
}

void addpoly(polyterm poly1[], int n1, polyterm poly2[], int n2, polyterm result[], int *resultsize) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k++] = poly2[j++];
        } else {
            result[k].exp = poly1[i].exp;
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            if (result[k].coeff != 0) {
                k++;
            }
            i++;
            j++;
        }
    }
    while (i < n1) {
        result[k++] = poly1[i++];
    }
    while (j < n2) {
        result[k++] = poly2[j++];
    }
    *resultsize = k;
}

int main() {
    const int MAX_TERMS = 100;
    polyterm poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS];
    int n1, n2, resultsize;

    printf("Polynomial 1:\n");
    readpoly(poly1, &n1);

    printf("Polynomial 2:\n");
    readpoly(poly2, &n2);

    printf("Polynomial 1: ");
    displaypoly(poly1, n1);

    printf("Polynomial 2: ");
    displaypoly(poly2, n2);

    addpoly(poly1, n1, poly2, n2, result, &resultsize);

    printf("Resultant Polynomial after addition: ");
    displaypoly(result, resultsize);

    return 0;
}