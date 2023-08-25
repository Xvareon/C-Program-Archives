/**C Program that locates numbers in an array**/

#include <stdio.h>
#define SIZE 5

void locate(int arr[],int search);

int main(){
	int i,search;
	int arr[SIZE];

	printf("Enter %d numbers\n",SIZE);
	for(i=0;i<SIZE;i++){
		printf("Enter number[%d]: ",i);
		scanf(" %d",&arr[i]);
	}
	printf("\n\nEnter number to be searched: ");
	scanf(" %d",&search);
    locate(arr,search);

	return 0;
}

void locate(int arr[],int search){
    int i,j;

    for(i=0,j=0;i<SIZE;i++){
        if(search==arr[i]){
            arr[j]=i;j++;
		}
	}
	if(j==0){
        printf("\nNumber not found.\n");
	}else if(j==1){
        printf("\nNumber %d found once at index %d.\n",search,arr[0]);
	}else{
        printf("\nNumber %d found %d times at indexes:",search,j);
        for(i=0;i<j;i++){
            if(i<j-1){
                printf(" %d,",arr[i]);
            }else{
                printf("\b and %d.\n\n",arr[i]);
                break;
            }
        }
    }
}
