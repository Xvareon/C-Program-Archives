#include <stdio.h>

int main()
{
	int num, ini, end;
	printf("Enter beginning of Series\n");
	scanf("%d", &ini);
	printf("Enter end of Series\n");
	scanf("%d", &end);

	printf("\n\nEven Numbers:");
for (num=ini; num<=end; num++){
	if (num%2==0)
     printf("\n%d", num);
}

    printf("\n\nOdd Numbers:");

for (num=ini; num<=end; num++){
	if (num%2==1)
     printf("\n%d", num);
}

    return 0;
}



//Sample1
/*{
	int ctr;
printf("Even numbers between 0 and 30\n");
for (ctr=2; ctr<=30; ctr=ctr+2)
printf("%d ", ctr);


return 0;
}*/
