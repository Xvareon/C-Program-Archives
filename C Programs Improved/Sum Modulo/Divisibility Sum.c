#include <stdio.h>

int compsum(int n[], int d, int s);

int main()
{
	int i, div, size;
	printf("Enter array size: ");
	scanf("%d", &size);
	printf("\nEnter divisibility limiter: ");
	scanf("%d", &div);
	int n[size];
	printf("\n");
	
	for (i=0; i<size; i++)
	{
		printf("[%d]Enter Number: ", i);
		scanf("%d", &n[i]);
	}
	printf("\n\nSum of numbers that are not divisible by %d is %d", div, compsum(n, div, size));
	return 0;
}

int compsum(int n[], int d, int s)
{
	int i, sum=0;
	
	for (i=0; i<s; i++)
	{
		if (n[i]%d!=0)
		sum+=n[i];
	}
	return sum;
}