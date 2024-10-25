/*Write a menu driven program to perform operations in an array.
 Enter size of Array: 
***************************************
 Menu : 
 1. Insert 
 2. Delete 
 3. Search 
 4. Display
 5. Exit
***************************************/

#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int size);
void delete(int arr[], int size);
void search(int arr[], int size);
void display(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0, choice;

    // Get the size of the array
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid array size! Exiting program.\n");
        return 1;
    }

    printf("***************************\n");

    while (1) { // Infinite loop to keep showing the menu until "Exit" is selected
        // Menu
        printf("MENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("***************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(arr, size);
                break;
            case 2:
                delete(arr, size);
                break;
            case 3:
                search(arr, size);
                break;
            case 4:
                display(arr, size);
                break;
            case 5:
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("***************************\n");
    }

    return 0;
}

// Function to insert elements into the array
void insert(int arr[], int size) {
    printf("Enter %d elements for the array: \n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Elements inserted successfully.\n");
}

// Function to delete an element from the array
void delete(int arr[], int size) {
    int pos;

    printf("Enter the position of the element to delete (1 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left after deletion
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted successfully.\n");
}

// Function to search for an element in the array
void search(int arr[], int size) {
    int value, found = 0;
    printf("Enter the value to search for: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element found at index %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    }
}

// Function to display the array elements
void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
