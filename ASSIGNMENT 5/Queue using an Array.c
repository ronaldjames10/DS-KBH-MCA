//1) Write a Menu driven C program to accomplish the following functionalities in Queue using an Array:
//a. Insert an element into the queue using an array (Enqueue Operation).
//b. Delete an element from the queue using an array (Dequeue Operation).
//c. Return the value of the FRONT element of the queue (without deleting it from the queue) using an array (Peep operation).
//d. Display the elements of a queue using an array.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", queue[front]);
}

void display() {
	int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
