// Simple Polynomial Operations using Linked Lists
#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff, exp;
    struct Term* next;
} Term;

Term* head1 = NULL;
Term* head2 = NULL;

// Create new term
Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Insert term in polynomial (maintaining descending order of exponents)
void insertTerm(Polynomial* poly, int coeff, int exp) {
    if (coeff == 0) return; // Don't insert zero coefficients
    
    Term* newTerm = createTerm(coeff, exp);
    if (newTerm == NULL) return;
    
    // If polynomial is empty or new term has highest exponent
    if (poly->head == NULL || poly->head->exp < exp) {
        newTerm->next = poly->head;
        poly->head = newTerm;
        return;
    }
    
    // Find correct position or combine like terms
    Term* current = poly->head;
    Term* prev = NULL;
    
    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }
    
    // If same exponent found, add coefficients
    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        free(newTerm);
        
        // Remove term if coefficient becomes zero
        if (current->coeff == 0) {
            if (prev == NULL) {
                poly->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
        return;
    }
    
    // Insert new term
    newTerm->next = current;
    if (prev == NULL) {
        poly->head = newTerm;
    } else {
        prev->next = newTerm;
    }
}

// Read polynomial from user input
void readPolynomial(Polynomial* poly) {
    int n, coeff, exp;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Enter terms (coefficient exponent):\n");
    printf("Note: Terms will be automatically sorted by exponent\n");
    
    for (int i = 0; i < n; i++) {
        printf("Term %d - Coefficient Exponent: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        
        if (exp < 0) {
            printf("Warning: Negative exponents not supported in this implementation.\n");
            continue;
        }
        
        insertTerm(poly, coeff, exp);
    }
}

// Display polynomial in mathematical form
void displayPolynomial(Polynomial* poly, const char* name) {
    if (poly == NULL || poly->head == NULL) {
        printf("%s: 0\n", name);
        return;
    }
    
    printf("%s: ", name);
    Term* current = poly->head;
    int first = 1;
    
    while (current != NULL) {
        // Handle sign
        if (!first) {
            if (current->coeff > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else if (current->coeff < 0) {
            printf("-");
        }
        
        int absCoeff = abs(current->coeff);
        
        // Handle coefficient
        if (current->exp == 0 || absCoeff != 1) {
            printf("%d", absCoeff);
        }
        
        // Handle variable and exponent
        if (current->exp > 0) {
            printf("x");
            if (current->exp > 1) {
                printf("^%d", current->exp);
            }
        }
        
        current = current->next;
        first = 0;
    }
    printf("\n");
}

// Add two polynomials
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();
    if (result == NULL) return NULL;
    
    Term* p1 = poly1->head;
    Term* p2 = poly2->head;
    
    // Merge terms from both polynomials
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            // Same exponent, add coefficients
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // Add remaining terms
    while (p1 != NULL) {
        insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    
    while (p2 != NULL) {
        insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    
    return result;
}

// Multiply two polynomials
Polynomial* multiplyPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();
    if (result == NULL) return NULL;
    
    if (poly1->head == NULL || poly2->head == NULL) {
        return result; // Return empty polynomial (zero)
    }
    
    // Multiply each term of poly1 with each term of poly2
    Term* p1 = poly1->head;
    
    while (p1 != NULL) {
        Term* p2 = poly2->head;
        
        while (p2 != NULL) {
            int newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;
            
            insertTerm(result, newCoeff, newExp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    
    return result;
}

// Free memory allocated for polynomial
void freePolynomial(Polynomial* poly) {
    if (poly == NULL) return;
    
    Term* current = poly->head;
    while (current != NULL) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

// Main function with menu-driven interface
int main() {
    Polynomial* poly1 = createPolynomial();
    Polynomial* poly2 = createPolynomial();
    Polynomial* result = NULL;
    int choice;
    
    printf("=== POLYNOMIAL OPERATIONS USING LINKED LISTS ===\n\n");
    
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Read first polynomial\n");
        printf("2. Read second polynomial\n");
        printf("3. Display polynomials\n");
        printf("4. Add polynomials\n");
        printf("5. Multiply polynomials\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n--- Reading First Polynomial ---\n");
                // Clear existing polynomial
                freePolynomial(poly1);
                poly1 = createPolynomial();
                readPolynomial(poly1);
                printf("First polynomial read successfully!\n");
                break;
                
            case 2:
                printf("\n--- Reading Second Polynomial ---\n");
                // Clear existing polynomial
                freePolynomial(poly2);
                poly2 = createPolynomial();
                readPolynomial(poly2);
                printf("Second polynomial read successfully!\n");
                break;
                
            case 3:
                printf("\n--- Current Polynomials ---\n");
                displayPolynomial(poly1, "P1(x)");
                displayPolynomial(poly2, "P2(x)");
                break;
                
            case 4:
                printf("\n--- Polynomial Addition ---\n");
                displayPolynomial(poly1, "P1(x)");
                displayPolynomial(poly2, "P2(x)");
                
                if (result) freePolynomial(result);
                result = addPolynomials(poly1, poly2);
                
                if (result) {
                    printf("\nAddition Result:\n");
                    displayPolynomial(result, "P1(x) + P2(x)");
                } else {
                    printf("Error in addition!\n");
                }
                break;
                
            case 5:
                printf("\n--- Polynomial Multiplication ---\n");
                displayPolynomial(poly1, "P1(x)");
                displayPolynomial(poly2, "P2(x)");
                
                if (result) freePolynomial(result);
                result = multiplyPolynomials(poly1, poly2);
                
                if (result) {
                    printf("\nMultiplication Result:\n");
                    displayPolynomial(result, "P1(x) * P2(x)");
                } else {
                    printf("Error in multiplication!\n");
                }
                break;
                
            case 6:
                printf("Freeing memory and exiting...\n");
                freePolynomial(poly1);
                freePolynomial(poly2);
                if (result) freePolynomial(result);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
