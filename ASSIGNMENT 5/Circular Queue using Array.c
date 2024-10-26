//3) Write a Menu driven C program to accomplish the following functionalities in Circular Queue using Array:
//i. Insert an element into the circular queue.
//j. Delete an element from the circular queue.
//k. Return the value of the FRONT element of the circular queue (without deleting it from the queue).
//l. Display the elements of a circular queue using the circular queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is Full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("%d dequeued from queue\n", queue[front]);
}

void peek() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front element is %d\n", queue[front]);
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != rear);
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
