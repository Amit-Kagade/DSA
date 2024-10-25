/*Implement circular queue using Arrays*/

#include <stdio.h>
#define SIZE 5  // Set the size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int IsFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the queue is empty
int IsEmpty() {
    return (front == -1);
}

// Function to insert an element into the circular queue
void enqueue(int x) {
    if (IsFull()) {
        printf("Queue is full. Can't insert element.\n");
        return;
    }
    if (IsEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;  // Circular increment
    }
    queue[rear] = x;
    printf("Inserted %d into the queue.\n", x);
}

// Function to delete an element from the circular queue
int dequeue() {
    if (IsEmpty()) {
        printf("Queue is empty. Nothing to delete.\n");
        return -1;
    }
    int temp = queue[front];
    if (front == rear) {
        front = rear = -1;  // Reset the queue
    } else {
        front = (front + 1) % SIZE;  // Circular increment
    }
    return temp;
}

// Function to display the elements of the circular queue
void print() {
    if (IsEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements of the Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to provide menu options
int main() {
    int choice, x;

    do {
        printf("-------Menu------\n");
        printf("1: Insert element in queue\n");
        printf("2: Delete element from queue\n");
        printf("3: Check queue is empty or not\n");
        printf("4: Check queue is full or not\n");
        printf("5: Print elements of queue\n");
        printf("6: Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert in the queue: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                x = dequeue();
                if (x != -1) {
                    printf("Dequeued element: %d\n", x);
                }
                break;

            case 3:
                if (IsEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 4:
                if (IsFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;

            case 5:
                print();
                break;

            case 6:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}