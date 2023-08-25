/**C Program that inserts a number into an index and computes total sum**/

#include <stdio.h>
#define SIZE 5

int main(){
    int i,j,insert,sum=0,temp;
	int n[SIZE+1];

	for(i=0;i<SIZE;i++){
        printf("[%d]Enter number: ",i);
		scanf(" %d",&n[i]);
		sum+=n[i];
	}printf("\n");

//display array
    for(i=0;i<SIZE;i++){
    	printf("\n[%d]%d",i,n[i]);
    }
//insert element
    printf("\nEnter extra number: ");
    scanf(" %d",&temp);
    sum+=temp;
    printf("\nEnter index of insertion: ");
    scanf(" %d",&insert);
    if(insert<0 || insert>SIZE){
        insert=SIZE;
    }
    for(i=SIZE;i>=insert;i--){
    	n[i]=n[i-1];
    }n[insert]=temp;
//display array with the inserted element
     for(i=0;i<=SIZE;i++){
    	printf("\n[%d]%d",i,n[i]);
    }printf("\nTotal Sum of all numbers is: %d",sum);
    return 0;
}
