#include <stdio.h>
#include <string.h>
#include <math.h>

int CalcOdometer(int Odometer);

int main()
{
	int Odometer;
	int finale;


	do
	{
		printf("\n\tInput Odometer: ");
		scanf("%d", &Odometer);

		finale = CalcOdometer(Odometer);
		printf("\n\t%d: %d\n", Odometer, finale);
	}while (Odometer != 0);
	return 0;

}

int CalcOdometer(int Odometer)
{
	int placement;
	int total = 0;
	int i = 1;
	int j = 10;
	int array[i];
	int value = 1;

	array[0] = Odometer % 10;
	// to get each value of place values
	if (Odometer > 9)
	{
		do
		{
			placement = (Odometer / j) % 10;
			array[i] = placement;
			i++;
			j = j * 10;
			value++;
		}
		while (Odometer >= j);
	}
	else
		value = 1;

	/* To remove leading 0's. */
	for (i = 0; i < value; i++)
	{
		if (array[i] == 0)
			array[i] = array[i] + array[i];
	}
	/* Total no. of 4 appeared depending on the place value */
	for (i = 0; i < value; i++)
	{
		if (array[i] < 4)
			array[i] = array[i] * pow(9, i);
		else
		{
			array[i] = (array[i] - 1) * (pow(9, i));
		}
	}
	/* To get the total distance covered. */
	for (i = 0; i < value; i++)
	{
		total = total + array[i];
	}

	 return total;
}