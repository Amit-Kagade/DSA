/*Write a program to print the elements in a link list. */


#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *start;

struct node* createNode(){

    struct node *h1;
    h1 = (struct node *)malloc(sizeof(struct node));

    printf("Enter a Data: ");
    scanf("%d",&h1->data);

    h1->next =0;

    return h1;

}

void insertData(){

    struct node *h1;
    h1 = createNode();

    if (start ==0){

        start = h1;
    }
    else{

        h1->next = start;
        start = h1;
    }

}

void Display(){

    struct node *h1;
    h1 = start;

    if (start == 0){

        printf ("\nThere is no Data !!!");

    }
    else{
        printf("\nLinked List: ");
        while(h1 != 0){

            printf(" ->%d",h1->data);
            h1= h1->next;
        }
        printf(" NULL\n");
    }
}


int main(){

int ch;
printf ("\n***************************");
printf ("\n1. To Insert data(element) ");
printf ("\n2. To Display Elements ");
printf ("\n3. To Exit the code ");
printf ("\n***************************\n");
while(1){
printf("\nEnter your Choice: ");
scanf("%d",&ch);

switch(ch){

    case 1:
    insertData();
    break;

    case 2:
    Display();
    break;

    case 3:
    return 0;

    default:
    printf("Enter Valid No !!!");
    break;
}
}
}