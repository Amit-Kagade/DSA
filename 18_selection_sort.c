#include<stdio.h>
#include<stdlib.h>

void main(){

    int a[10];
    int p,n,s,temp,min,index;

    printf("Enter a range: ");
    scanf("%d",&n);

    printf("Enter %d Numbers: ",n);
    for(p=0; p<n; p++){
        scanf("%d",&a[p]);
    }

    for(p=0; p<n-1; p++){
        min=a[p];
        index=p;

        for(s=p+1; s<n; s++){
            if(min>a[s]){
                min=a[s];
                index=s;
            }
        }
        temp = a[p];
        a[p] = a[index];
        a[index] = temp;

    }

    printf("After sorting : ");
    for(p=0; p<n; p++){
        printf(" %d",a[p]);
    }
    printf("\n");

}