// /*Implement Insertion sort */


#include<stdio.h>

int main(){

    int n, a[50], temp;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("ENter %d numbers\n",n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }


    for(int i=0; i<n; i++){
        temp = a[i];
        int j= i-1;

        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]= temp;
    }


printf("\nSorted array: ");
for(int i=0; i<n; i++){
    printf(" %d",a[i]);
}
printf("\n");
return 0;
}

