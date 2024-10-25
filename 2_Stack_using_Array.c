/*Implement stack using arrays */

#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;
int x;

void push()
{
    if(top == MAX_SIZE-1)
    {
        printf("Array is full\n");
    }
    else{
        
        printf("Enter the element to push in stack :");
        scanf("%d",&x);
        top= top+1;
        stack[top]=x;    // stack[++top]=x; 
    }
}

void pop()
{
    if(top == -1)
    {
        printf("There is no element to pop.\n");
        return;
    }
        printf("%d popped from the stack.\n", stack[top]);
    top--;
}

void Top()
{
  if(top==-1)
    {
        printf("Stack is empty.\n");
    }
   else{
    printf("Top most element of stack is %d.\n",stack[top]);
   }  
}

int IsEmpty()
{
    return top==-1;
    
}

void print()
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
    }else{

    printf("Stack :");
    for(int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
   printf("\n") ;
    }
}


int main()
{
    int choice;

     while (1) {
        printf("-------Menu------\n");
        printf("1 : Push element in stack\n");
        printf("2 : pop element from stack\n");
        printf("3 : Top element in stack\n");
        printf("4 : check stack is empty\n");
        printf("5 : Print elements of stack\n");
        printf("6 : Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
             push(); 
             break;

            case 2:
             pop() ;  
             break;

            case 3:
            Top();
            break;

            case 4:
              if (IsEmpty())
              {
                    printf("Stack is empty.\n");
              }
              else
              {
                    printf("Stack is not empty.\n"); 
              }
              break;

            case 5:
            print();
            break;

            case 6:
            printf("Exiting the program...\n");
            return 0;
            break;
           

            default:
                printf("Invalid choice.\n");
        }
    }



//return 0;
}