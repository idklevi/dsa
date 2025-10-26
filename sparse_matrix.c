#include <stdio.h>
struct element {
    int row, col, val;
};
int main() {
    struct element A[10], B[10], sum[20];
    int n1, n2, i, j, k;
    printf("Enter number of non-zero elements in A: ");
    scanf("%d", &n1);
    printf("Enter row, column and value of A:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].val);
    }
    printf("Enter number of non-zero elements in B: ");
    scanf("%d", &n2);
    printf("Enter row, column and value of B:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].val);
    }
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (A[i].row < B[j].row || 
           (A[i].row == B[j].row && A[i].col < B[j].col)) {
            sum[k++] = A[i++];
        } else if (A[i].row > B[j].row || 
                  (A[i].row == B[j].row && A[i].col > B[j].col)) {
            sum[k++] = B[j++];
        } else { 
            sum[k] = A[i];
            sum[k++].val = A[i++].val + B[j++].val;
        }
    }
    while (i < n1) sum[k++] = A[i++];
    while (j < n2) sum[k++] = B[j++];
    printf("\nSum of matrices:\n");
    for (i = 0; i < k; i++) {
        if (sum[i].val != 0)  // avoid zero entries
            printf("%d %d %d\n", sum[i].row, sum[i].col, sum[i].val);
    }
    printf("\nTranspose of matrix A:\n");
    for (i = 0; i < n1; i++) {
        printf("%d %d %d\n", A[i].col, A[i].row, A[i].val);
    }
    return 0;
}
