/*Queue using Linked List*/


#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Queue front and rear pointers
struct node *front = NULL;
struct node *rear = NULL;

// Function to create and return a new node
struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

// Enqueue operation to add element to the queue
void enqueue() {
    struct node *newNode = createNode();  // Create a new node

    if (rear == NULL) {
        // If queue is empty, both front and rear will point to the new node
        front = rear = newNode;
    } else {
        // Add the new node at the end of the queue and change rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", newNode->data);
}

// Dequeue operation to remove element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("%d dequeued from queue\n", front->data);
    front = front->next;

    // If the queue is now empty, set rear to NULL
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);  // Free the dequeued node
}

// Peek operation to return the front element of the queue
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is %d\n", front->data);
    }
}

// Check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Display queue elements
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();  // Enqueue an element
                break;
            case 2:
                dequeue();  // Dequeue an element
                break;
            case 3:
                peek();  // Display the front element
                break;
            case 4:
                display();  // Display all elements in the queue
                break;
            case 5:
                exit(0);  // Exit the program
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
