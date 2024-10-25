/*Implement all functions in Linked List*/

#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};
struct node *start=0;

struct node *createNode(){

    struct node *h1;
    h1 = (struct node *)malloc(sizeof(struct node));
    
    printf ("Enter a data: ");
    scanf("%d",&h1->data);

    h1->next = 0;
    return h1;

}

void insertStart(){

    struct node *k1;
    k1 = createNode();

    if (start == 0){

        start = k1;
    }
    else{

        k1->next = start;
        start = k1;
    }


}

void insertEnd(){

    struct node *j1,*g1;

    j1 = createNode();

    if(start == 0){

        start = j1;
    }
    else {

        g1 = start;
        while(g1->next != 0){
            g1 = g1->next;
        }
        g1->next=j1;
    }
}

void insertMiddle(){

    struct node *j1,*g1,*f1;
    int d;
    j1 = createNode();

    if(start ==0 ){

        start = j1;

    }
    else{

        printf ("Enter a data where you want to insert: ");
        scanf("%d",&d);

        g1 = start;
        while(g1->next->next != d){

            g1=g1->next;
        }
        f1 = g1->next;
        g1->next = j1;
        j1->next = f1;
    }
}

void deleteStart(){

struct node *j1;

if (j1 == 0){

    printf("There is no data to delete !!!");
}
else{

    j1 = start;
    start = start->next;
    j1->next = 0;
    free(j1);
}

}

void deleteEnd(){

    struct node *j1,*a1;
    j1 = start;

    if (j1 == 0){

        printf("There no any node to delete !!!");
    }
    else {

        while(j1->next->next != 0){
            j1 = j1->next;
        }
        a1 = j1->next;
        j1->next =0;
        free(a1);
    }

}

void deleteMiddle(){



}

void display(){

    struct node *j1;
    j1 = start;

    while(j1 != 0){

        printf(" %d",j1->data);
        j1 = j1->next;
    }
}

// int Exit(){

//     return 0;
// }


int main(){

int ch;
    printf("\n1. Insertion from start");
    printf("\n2. Insertion from end");
    printf("\n3. Insertion from middle");
    printf("\n4. Deletion from start");
    printf("\n5. Deletion from end");
    printf("\n6. Deletion from middle");
    printf("\n7. Display");
    printf("\n8. Exit");
    printf("\n**************************\n");

    while(1){
    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);

    switch(ch){

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
        printf("\n");
        return 0;
        break;
 
        default:
            printf("\nWrong Input !!!");
            break;
    }
}
}