/*Write a program to create a Linked list with n elements. */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = 0;  

// Function to create a new node
struct node* createNode(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = 0;
    return newNode;
}

// Function to insert data at the end of the list
void insertAtEnd(int value) {

    struct node *temp;
    struct node *newNode = createNode(value);

    if (start == 0) {

        start = newNode;  
    } 
    else {

        temp = start;
        while (temp->next != 0) {  

            temp = temp->next;

        }
        temp->next = newNode;  
    }
}

// Function to display the linked list
void displayList() {

    struct node *temp = start;

    if (start == 0) {

        printf("\nThe list is empty!\n");

    } 
    else {

        printf("\nThe linked list elements are: ");
        while (temp != 0) {
            printf("%d -> ", temp->data);
            temp = temp->next;
            
        }

        printf("NULL\n");
    }
}

int main() {
    int n, value, i;

    printf("Enter the number of elements to add to the list: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Data %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }

    displayList();

    return 0;
}
