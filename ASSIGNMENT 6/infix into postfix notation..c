//3) Write a program to convert an infix expression into its equivalent postfix notation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void push(char op) {
    stack[++top] = op;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ')
            continue;
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(); // Remove '('
            }
        } else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
