//6) Write a program to evaluate a prefix expression.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePrefix(char *prefix) {
    int i, operand1, operand2, result;
    int len = strlen(prefix) - 1;

    for (i = len; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        } else {
            operand1 = pop();
            operand2 = pop();

            switch (prefix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
    }

    return pop();
}

int main() {
    char prefix[100];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}
