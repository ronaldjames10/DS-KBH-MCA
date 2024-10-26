//1) Write a Menu driven C program to accomplish the following functionalities in doubly linked list.
//a) Create a doubly linked list.
//b) Display the elements of a doubly linked list.
//c) Insert a node at the beginning of a doubly linked list.
//d) Insert a node at the end of a doubly linked list.
//e) Insert a node before a given node of a doubly linked list.
//f) Insert a node after a given node of a doubly linked list.
//g) Delete a node from the beginning of a doubly linked list.
//h) Delete a node from the end of a doubly linked list.
//i) Delete a node after a given node of a doubly linked list.
//j) Delete the entire doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to display the doubly linked list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node* new_node = newNode(data);
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert a node before a given node
void insertBefore(int data, int x) {
    struct Node* new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    if (head->data == x) {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev->next = new_node;
    temp->prev = new_node;
}

// Function to insert a node after a given node
void insertAfter(int data, int x) {
    struct Node* new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

// Function to delete a node from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end
void deleteAtEnd() {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node after a given node
void deleteAfter(int x) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Node not found or node to be deleted not found\n");
        return;
    }
    struct Node* to_delete = temp->next;
    temp->next = to_delete->next;
    if (to_delete->next != NULL) {
        to_delete->next->prev = temp;
    }
    free(to_delete);
}

// Function to delete the entire doubly linked list
void deleteList() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice, data, x;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert Before\n");
        printf("6. Insert After\n");
        printf("7. Delete at Beginning\n");
        printf("8. Delete at End\n");
        printf("9. Delete After\n");
        printf("10. Delete List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter node after which to insert: ");
                scanf("%d", &x);
                insertBefore(data, x);
                break;
            case 6:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter node after which to insert: ");
                scanf("%d", &x);
                insertAfter(data, x);
                break;
            case 7:
                deleteAtBeginning();
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                printf("Enter node after which to delete: ");
                scanf("%d", &x);
                deleteAfter(x);
                break;
            case 10:
                deleteList();
                printf("List deleted\n");
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
