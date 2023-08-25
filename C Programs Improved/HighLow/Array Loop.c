/**C Program that determines the least and greatest numbers in an array and computes total average**/

#include <stdio.h>
#define SIZE 5

void Func(int arr[]);

int main(){
    int i,a[50];

    for(i=0;i<SIZE;i++){
        printf("Enter number[%d]: ",i+1);
    	scanf(" %d",&a[i]);
    }
    printf("\n\n");
    Func(a);
	return 0;
}

void Func(int arr[]){
    int i,low,high;
    float sum=0;

    if(arr[0]<arr[1]){
        low=arr[0];
    	high=arr[1];
    }else{
    	low=arr[1];
    	high=arr[0];
    }
    printf("The Lowest in ");
    for(i=0;i<SIZE;i++){
    	printf("%d, ",arr[i]);
    	if(arr[i]>high)
            high=arr[i];
    	if(arr[i]<low)
    	    low=arr[i];
    	sum=sum+arr[i];
    }
    printf("\b\b and %d",arr[SIZE-1]);
    printf(" is %d\n\n",low);
    printf("The Highest in ");
    for(i=0;i<SIZE-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("\b\b and %d",arr[SIZE-1]);
    printf(" is %d\n\n",high);
    printf("The Average in ");
    for(i=0;i<SIZE-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("\b\b and %d",arr[SIZE-1]);
    printf(" is %.2f\n\n",sum/SIZE);
}
