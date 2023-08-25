#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void pr(int N);

int main()
{
	int n, c;

	printf("Enter number: ");
	scanf("%d", &n);
	pr(n);

	printf("\n\nDo you want to loop?\n\nYes -->1\n\nNo -->2\n\n");
    scanf("%d",&c);
    switch(c){
    case 1:system("cls");main();break;
    default:return 0;break;
    }
}

void pr(int N){

    int i, count=0;

    if (N==0 || N==1){
		printf("\nNumber is not prime");
		}

	else{
	for (i=2; i<N; i++)
	{
		if (N%i==0)
		count++;
	}

	if (count>0){
	printf("\nNumber %d is not prime", N);}
	else{
	printf("\nNumber %d is prime", N);}
	}
}
