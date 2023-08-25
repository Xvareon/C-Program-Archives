/**C Program that prints the absolute differences of two arrays**/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void AbsoluteArray(int x[],int y[]);

int main(){
	int x[SIZE],y[SIZE];
	int i;

	printf("\nEnter elements for the first array:\n");
	for(i=0;i<SIZE;i++){
		printf("Enter number x[%d]: ",i);
		scanf(" %d",&x[i]);
	}
    printf("\nEnter elements for the second array:\n");
	for(i=0;i<SIZE;i++){
		printf("Enter number y[%d]: ",i);
		scanf(" %d",&y[i]);
	}
	AbsoluteArray(x,y);
	return 0;
}

void AbsoluteArray(int x[],int y[]){
	int absarray[SIZE];
	int i;
	for(i=0;i<SIZE;i++){
	   absarray[i]=abs(x[i]-y[i]);
	   printf("\n%d",absarray[i]);
	}
}
