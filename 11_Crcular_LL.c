/*Implement Circular LinkList*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct node **head, int value) {
    struct node *newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point the new node to itself
    } else {
        struct node *temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head; // Make it circular
    }
}

// Function to delete a node from the circular linked list
void deleteNode(struct node **head, int value) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = *head, *prev = NULL;

    // Check if the head needs to be deleted
    if (temp->data == value) {
        if (temp->next == *head) {
            // Only one node in the list
            free(temp);
            *head = NULL;
        } else {
            // Find the last node to update its next pointer
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next; // Update last node's next to the second node
            free(*head); // Delete head node
            *head = temp->next; // Update head to the next node
        }
        return;
    }

    // Traverse the list to find the node to delete
    while (temp->next != *head && temp->next->data != value) {
        temp = temp->next;
    }

    // Node not found
    if (temp->next == *head) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Node found, delete it
    struct node *toDelete = temp->next;
    temp->next = toDelete->next; // Bypass the node to delete
    free(toDelete);
}

// Function to display the circular linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}

// Main function to demonstrate circular linked list operations
int main() {
    struct node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert at end");
        printf("\n2. Delete a node");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct node **head, int value) {
    struct node *newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point the new node to itself
    } else {
        struct node *temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head; // Make it circular
    }
}

// Function to delete a node from the circular linked list
void deleteNode(struct node **head, int value) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = *head, *prev = NULL;

    // Check if the head needs to be deleted
    if (temp->data == value) {
        if (temp->next == *head) {
            // Only one node in the list
            free(temp);
            *head = NULL;
        } else {
            // Find the last node to update its next pointer
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next; // Update last node's next to the second node
            free(*head); // Delete head node
            *head = temp->next; // Update head to the next node
        }
        return;
    }

    // Traverse the list to find the node to delete
    while (temp->next != *head && temp->next->data != value) {
        temp = temp->next;
    }

    // Node not found
    if (temp->next == *head) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Node found, delete it
    struct node *toDelete = temp->next;
    temp->next = toDelete->next; // Bypass the node to delete
    free(toDelete);
}

// Function to display the circular linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}

// Main function to demonstrate circular linked list operations
int main() {
    struct node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert at end");
        printf("\n2. Delete a node");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
