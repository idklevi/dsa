#include <stdio.h>

#define MAX 40

typedef struct {
    int row, col, val;
} Element;

Element A[MAX], B[MAX], Result [MAX], Trans[MAX];

int readMatrix(Element mat[]) {
    int n;
    printf("Enter rows cols non-zero count: ");
    scanf("%d %d %d", &mat[0].row, &mat[0].col, &mat[0].val);
    n = mat[0].val;
    printf("Enter %d non-zero elements (row col val):\n", n);
    for (int i=1; i <= n; i++) {
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].val);
    }
    return n+1;
}

void showFull(Element mat[], int count) {
    int r = mat[0].row, c = mat[0].col;
    int data[r][c];
    
    for (int i=0; i < r; i++)
        for (int j=0; j<c; j++)
            data[i][j] = 0;
            
    for (int i=1; i < count; i++)
        data[mat[i].row][mat[i].col] = mat[i].val;
        
    for (int i=0; i < r; i++) {
        for (int j=0; j < c; j++)
            printf("%3d", data[i][j]);
        printf("\n");
    }
}

int addMatrices(Element A[], int na, Element B[], int nb, Element R[]) {
    if (A[0].row != B[0].row || A[0].col != B[0].col)
        return -1;
        
    R[0] = A[0];
    int i=1, j=1, k=1;
    
    while (i < na && j < nb) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            R[k] = A[i];
            R[k++].val += B[j++].val;
            i++;
        } else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            R[k++] = A[i++];
        } else {
            R[k++] = B[j++];
        }
    }
    
    while (i < na) R[k++] = A[i++];
    while (j < nb) R[k++] = B[j++];
    
    R[0].val = k-1;
    return k;
}

int transposeMatrix(Element mat[], Element trans[]) {
    int n = mat[0].val;
    trans[0].row = mat[0].col;
    trans[0].col = mat[0].row;
    trans[0].val = n;
    
    int k=1;
    for (int col = 0; col < mat[0].col; col++) {
        for (int i=1; i <= n; i++) {
            if (mat[i].col == col) {
                trans[k].row = mat[i].col;
                trans[k].col = mat[i].row;
                trans[k].val = mat[i].val;
                k++;
            }
        }
    }
    return k;
}

int main() {
    int na, nb, nsum, nt;
    
    printf("Matrix A:\n");
    na = readMatrix(A);
    printf("Matrix B:\n");
    nb = readMatrix(B);
    
    printf("\nMatrix A:\n");
    showFull(A, na);
    printf("\nMatrix B:\n");
    showFull(B, nb);
    
    nsum = addMatrices(A, na, B, nb, Result);
    if (nsum == -1)
        printf("\nCannot add matrices: different sizes.\n");
    else {
        printf("\nA + B:\n");
        showFull (Result, nsum);
    }
    
    nt = transposeMatrix(A, Trans);
    printf("\nTranspose of A:\n");
    showFull(Trans, nt);
    
    return 0;
}
