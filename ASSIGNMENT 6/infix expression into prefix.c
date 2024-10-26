//4) Write a program to convert an infix expression into its equivalent prefix notation.
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

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    int i, j;
    reverseString(infix);

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ')
            continue;
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(infix[i]);
        } else if (infix[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(); // Remove ')'
            }
        } else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';

    reverseString(prefix);
}

int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
