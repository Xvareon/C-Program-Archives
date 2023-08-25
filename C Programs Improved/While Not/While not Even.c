#include <stdio.h>

int main()
{
	int n1=1, n2=2, i=0;

	do
	{
		printf("\nLoop[%d]\n", i);
		printf("Dividend: ");
		scanf("%d", &n1);
		printf("Divisor: ");
		scanf("%d", &n2);
		if (n1%n2!=0)
		printf("Not evenly divided, Again\n");
		i++;
	}
	while (n1%n2!=0);
	printf("Evenly divided, End\n\n");
	return 0;
}
