#include <stdio.h> 

#define MAX 10 

struct Term { 
    int coeff; 
    int exp; 
};

void input(struct Term poly[], int *n) { 
    printf("Enter number of terms: "); 
    scanf("%d", n); 
    for (int i = 0; i < *n; i++) { 
        printf("Term %d (coeff exp): ", i + 1); 
        scanf("%d %d", &poly[i].coeff, &poly[i].exp); 
    } 
} 

void display(struct Term poly[], int n) { 
    for (int i = 0; i < n; i++) { 
        printf("%dx^%d", poly[i].coeff, poly[i].exp); 
        if (i < n - 1) printf(" + "); 
    } 
    printf("\n"); 
} 

int add(struct Term p1[], int n1, struct Term p2[], int n2, struct Term res[]) { 
    int i = 0, j = 0, k = 0; 
    while (i < n1 && j < n2) { 
        if (p1[i].exp > p2[j].exp) 
            res[k++] = p1[i++]; 
        else if (p1[i].exp < p2[j].exp) 
            res[k++] = p2[j++]; 
        else { 
            res[k].exp = p1[i].exp; 
            res[k].coeff = p1[i].coeff + p2[j].coeff; 
            k++; i++; j++;
        } 
    } 
    while (i < n1) res[k++] = p1[i++]; 
    while (j < n2) res[k++] = p2[j++]; 
    return k; 
} 

int main() { 
    struct Term p1[MAX], p2[MAX], sum[MAX]; 
    int n1, n2, ns; 
    
    printf("Polynomial 1:\n"); 
    input(p1, &n1); 
    
    printf("Polynomial 2:\n"); 
    input(p2, &n2); 
    
    ns = add(p1, n1, p2, n2, sum); 
    
    printf("Sum: "); 
    display(sum, ns); 
    
    return 0; 
}
