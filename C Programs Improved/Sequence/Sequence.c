#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void disp(int T, int Y);

int main()
{
	int i, N, D, T, Y, c;

	printf("Enter first term of the number: ");
	scanf("%d", &N);
	printf("\nEnter difference of the sequence: ");
	scanf("%d", &D);
	printf("\nEnter nth term you want to locate: ");
	scanf("%d", &T);

	printf("\ncheck:\n[1]: %d\n", N);
	for (i=1; i<T; i++)
	{
		N += D;
		printf("[%d]: %d\n", (i+1), N);
	}
	printf("\n");
	Y = N;
    disp(T,Y);

    printf("\n\nDo you want to loop?\n\nYes -->1\n\nNo -->2\n\n");
    scanf("%d",&c);
    switch(c){
    case 1:system("cls");main();break;
    default:return 0;break;
    }
}

void disp(int T, int Y){

    if (T==1 || T>20 && T%10==1)
	{
		if (T>100 && T%100==11)
		printf("The %dth term of the sequence is %d", T, Y);
		else
		printf("The %dst term of the sequence is %d", T, Y);
	}
	else if (T==2 || T>20 && T%10==2)
	{
		if (T>100 && T%100==12)
		printf("The %dth term of the sequence is %d", T, Y);
		else
		printf("The %dnd term of the sequence is %d", T, Y);
	}
	else if (T==3 || T>20 && T%10==3)
	{
		if (T>100 && T%100==13)
		printf("The %dth term of the sequence is %d", T, Y);
		else
		printf("The %drd term of the sequence is %d", T, Y);
	}
	else
	printf("The %dth term of the sequence is %d", T, Y);
}
