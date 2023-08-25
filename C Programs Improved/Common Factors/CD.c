/**C Program that prints the GCD AND LCD between two numbers**/

#include <stdio.h>
#include <stdlib.h>

void CD(int N1,int N2,int Limit);

int main(){
	int n1,n2,L,c;

	printf("Enter first number: ");
	scanf(" %d",&n1);
	printf("\nEnter second number: ");
	scanf(" %d",&n2);

	if(n1<n2)
        L=n1;
	else
        L=n2;

    CD(n1,n2,L);

	printf("\n\nDo you want to loop?\nYes-->1\nNo-->2\nAnswer: ");
    scanf("%d",&c);
    switch(c){
        case 1:system("cls");main();break;
        default:return 0;break;
    }
}

void CD(int N1,int N2,int Limit){
    int GCD=1,LCD=1,i;

    for(i=1;i<=Limit;i++){
		if(N1%i==0 && N2%i==0)
            GCD=i;
	}
	for(i=2;i<=Limit;i++){
        if(N1%i==0 && N2%i==0){
            LCD=i;
            break;
		}
	}
	printf("\nThe GCD between %d and %d is %d", N1,N2,GCD);
	if(LCD>1)
        printf("\nThe LCD is %d",LCD);
	else
        printf("\nThe LCD is 1");
}
