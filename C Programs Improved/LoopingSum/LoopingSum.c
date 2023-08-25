#include <stdio.h>

void spave(float num1, float num2, float count);

int main()
{
	float n1, n2, c;

	printf("How many numbers would you like to input? ");
	scanf("%f", &c);
	scanf("%f", &n1);
	scanf("%f", &n2);

	spave(n1,n2,c);

    return 0;
}

void spave(float num1, float num2, float count){
    int i;
    float num, sum, largest, smallest, average;

    sum = num1+num2;

	if (num1 > num2)
	{
		largest = num1;
		smallest = num2;
	}
	else
	{
		largest = num2;
		smallest = num1;
	}

	for (i = 1; i <= count-2; i++)
	{
		scanf("%f", &num);
		sum = sum+num;
		if (num > largest)
		largest = num;
		if (num < smallest)
		{
		smallest = num;
		}
	}

	average = sum / count;

		printf("\nThe largest number is %.0f and the smallest number is %.0f\n", largest, smallest);
		printf("\nThe sum is %.2f\n", sum);
		printf("\nThe average is %.2f\n", average);

}
