#include <stdio.h>

void arrsum(int size);

int main()
{
    int s;
    printf("Enter size of the two arrays: ");
	scanf("%d", &s);
    arrsum(s);
    return 0;
}

void arrsum(int size){

    int i;
	float sum1=0, sum2=0;
	float a[size], b[size];


	for (i=0; i<size; i++)
	{
		printf("[a%d]Enter number: ", (i+1));
		scanf("%f", &a[i]);
		sum1+=a[i];
	}
	printf("\nSum for array a is %.0f\n\n", sum1);

	for (i=0; i<size; i++)
	{
		printf("[b%d]Enter number: ", (i+1));
		scanf("%f", &b[i]);
		sum2+=b[i];
	}
	printf("\nSum for array b is %.0f", sum2);

	printf("\n\nTotal sum is %.0f and total average is %.2f\n\n", (sum1+sum2), (sum1+sum2)/(size*2));
}
