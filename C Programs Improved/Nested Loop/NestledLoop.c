#include <stdio.h>


int main()
{
	int rows, cols, n;
	char symbol;

	printf("Enter Symbol for figures: \n");
	scanf("%c", &symbol);

    //box
	printf("Enter the size of the box(Affects box only): \n");
	scanf("%d", &n);
	printf("\n\n\n");
	for (cols=1; cols<=n; cols++)
	{
		for (rows=1; rows<=n; rows++)
		printf("%c ", symbol);
		printf("\n");
	}

	//diamond
	int i, j, drows;
    printf("\n\n\nenter diamond rows:\n");
    scanf("%d", &drows);
    //upper pyramid
    for (i=1; i<=drows; i++){
        for (j=i; j<drows; j++){
            printf(" ");
        }
        for (j=1; j<=(2*i-1); j++){
            printf("%c", symbol);
        }
        printf("\n");
    }
    //lower pyramid
    for (i=drows-1; i>0; i--){
        for (j=i; j<drows; j++){
            printf(" ");
        }
        for (j=1; j<=(2*i-1); j++){
            printf("%c", symbol);
        }
        printf("\n");
    }

	return 0;
}
