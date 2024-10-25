#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL; // Initialize start to NULL

// Function to create a new node
struct node *createnode() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter a data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL; // Set next pointer to NULL
    return newnode;
}

// Function to insert a node at the end of the linked list
void insertEnd() {
    struct node *newnode = createnode();

    if (start == NULL) { // If the list is empty
        start = newnode; // Set the new node as the start
    } else {
        struct node *h1 = start;
        while (h1->next != NULL) { // Traverse to the last node
            h1 = h1->next;
        }
        h1->next = newnode; // Link the new node at the end
    }
}

// Function to display the linked list
void display() {
    struct node *h1 = start;

    if (start == NULL) {
        printf("\nThere is no Data !!!");
    } else {
        printf("\nLinked List: ");
        while (h1 != NULL) {
            printf(" %d", h1->data);
            h1 = h1->next;
        }
        printf(" \n");
    }
}

// Main function
int main() {
    printf("\n************************");
    printf("\n1. Press to enter data at the end of the linked list");
    printf("\n2. Press to display the linked list");
    printf("\n3. Press to Exit the Program");
    printf("\n************************\n");

    int choice;
    while (1) {
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertEnd(); // Insert a new node at the end
                break;
            case 2:
                display(); // Display the linked list
                break;
            case 3:
                return 0; // Exit the program
            default:
                printf("Invalid Choice!!!");
                break;
        }
        printf("\n");
    }
}
