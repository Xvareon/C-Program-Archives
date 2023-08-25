#include <stdio.h>

void Negate(double arr[], int size);

int main()
{
	int i, size;
	
	printf("Enter size of array: ");
	scanf("%d", &size);
	double arr[size];
	
	printf("\nEnter values: \n");
	for (i=0; i<size; i++)
	{
		printf("Index[%d]: ", i);
		scanf("%lf", &arr[i]);
	}
	printf("\n");
	Negate(arr, size);
	
	return 0;
}

void Negate(double arr[], int size)
{
	int i;
	
	for (i=0; i<size; i++)
	{
		if (arr[i] < 1)
		arr[i] = arr[i];
		else
		arr[i] *= -1;
	}
	printf("\nThe negated values are: ");
	for (i=0; i<size; i++)
	{
		printf("%.0lf ", arr[i]);
	}
}