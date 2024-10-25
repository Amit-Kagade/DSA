#include<stdio.h>

void bubble_sort(int a[], int n){

    int i,j,temp;

    for(i=0; i<n; i++){

        for(j=0; j<n-1; j++){

        if(a[j]>a[j+1]){

            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }
    }
    printf("After sorting: ");
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }

}


void main(){

    int i,n;

    printf("\nEnter a range: ");
    scanf("%d",&n);

     int a[n];

    printf("Enter %d elements: ",n);
    for(i=0; i<n; i++){
        printf("Element no %d: ",i+1);
        scanf("%d",&a[i]);
    }

    bubble_sort(a,n); 
    
}