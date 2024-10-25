#include <stdio.h>
#include <stdlib.h>

// Structure of a node in doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = 0;

// Function to create a new node
struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->prev = 0;
    newNode->next = 0;
    return newNode;
}

// Insert at the beginning of the list
void insertStart() {
    struct node *newNode = createNode();

    if (start == 0) {
        start = newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}

// Insert at the end of the list
void insertEnd() {
    struct node *newNode = createNode();
    
    if (start == 0) {
        start = newNode;
    } else {
        struct node *temp = start;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Insert in the middle (after a specific data)
void insertMiddle() {
    int data;
    struct node *newNode = createNode();
    
    printf("Enter the data after which to insert: ");
    scanf("%d", &data);
    
    struct node *temp = start;

    while (temp != 0 && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == 0) {
        printf("Node with data %d not found!\n", data);
    } else {
        newNode->next = temp->next;
        if (temp->next != 0) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete from the beginning
void deleteStart() {
    if (start == 0) {
        printf("List is empty!\n");
    } else {
        struct node *temp = start;
        start = start->next;
        if (start != 0) {
            start->prev = 0;
        }
        free(temp);
    }
}

// Delete from the end
void deleteEnd() {
    if (start == 0) {
        printf("List is empty!\n");
    } else {
        struct node *temp = start;
        
        while (temp->next != 0) {
            temp = temp->next;
        }
        
        if (temp->prev != 0) {
            temp->prev->next = 0;
        } else {
            start = 0;
        }
        
        free(temp);
    }
}

// Delete a node by its value
void deleteMiddle() {
    int data;
    printf("Enter the data of the node to delete: ");
    scanf("%d", &data);
    
    struct node *temp = start;
    
    while (temp != 0 && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == 0) {
        printf("Node with data %d not found!\n", data);
    } else {
        if (temp->prev != 0) {
            temp->prev->next = temp->next;
        } else {
            start = temp->next;
        }
        if (temp->next != 0) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// Display the list
void display() {
    struct node *temp = start;
    
    if (temp == 0) {
        printf("List is empty!\n");
    } else {
        printf("Doubly linked list: ");
        while (temp != 0) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
     printf("\n1. Insert at start\n2. Insert at end\n3. Insert in middle\n4. Delete from start\n5. Delete from end\n6. Delete from middle\n7. Display\n8. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStart();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertMiddle();
                break;
            case 4:
                deleteStart();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteMiddle();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
