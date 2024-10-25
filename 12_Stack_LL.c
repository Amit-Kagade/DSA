/*Stack using Linked List*/

#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Stack top pointer
struct node *top = NULL;

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

// Push operation to add element to the stack
void push() {
    struct node *newNode = createNode();  // Call createNode to get a new node
    
    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    printf("%d pushed to stack\n", newNode->data);
}

// Pop operation to remove element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        struct node *temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Peek operation to return the top element of the stack
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Display stack elements
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();  // Push now calls createNode internally
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
