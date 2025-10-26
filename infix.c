#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char opStack[MAX];
int topOp = -1;
int valStack[MAX];
int topVal = -1;
void pushOp(char c) {
    opStack[++topOp] = c;
}
char popOp() {
    return opStack[topOp--];
}
char peekOp() {
    return opStack[topOp];
}
void pushVal(int v) {
    valStack[++topVal] = v;
}
int popVal() {
    return valStack[topVal--];
}
// precedence
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // handle multi-digit number
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // delimiter
            continue;
        }
        else if (infix[i] == '(') {
            pushOp(infix[i]);
        }
        else if (infix[i] == ')') {
            while (topOp != -1 && peekOp() != '(') {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            popOp(); // remove '('
        }
        else { // operator
            while (topOp != -1 && precedence(peekOp()) >= precedence(infix[i])) {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            pushOp(infix[i]);
        }
        i++;
    }
    while (topOp != -1) {
        postfix[k++] = popOp();
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}
// Evaluate Postfix
int evaluate(char postfix[]) {
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushVal(num);
        }
        else if (postfix[i] == '+' || postfix[i] == '-' ||
                 postfix[i] == '*' || postfix[i] == '/') {
            int b = popVal();
            int a = popVal();
            switch (postfix[i]) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
            }
        }
        i++;
    }
    return popVal();
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);  // no spaces required
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluating the postfix expression...\n");
    int result = evaluate(postfix);
    printf("Result = %d\n", result);
    return 0;
}