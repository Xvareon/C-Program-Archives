#include <stdio.h>
#include <conio.h>

void loop(int n);

int main()
{
    int num;
    printf("\nEnter Multiplication Size: ");
    scanf("%d", &num);
    loop(num);
	return 0;
}

void loop(int n)
{
	int i, j;

		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			printf("%d\t", i*j);
			printf("\n");
		}
		getch();
	printf("\n\nThank you!\n\n");
}
