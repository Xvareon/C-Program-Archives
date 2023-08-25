#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char membership;
	float age, semfee;

	printf("SEMINAR FEES\n\na)Members less than 65y/o = $10\nb)Members that are 65y/o and above = $5\nc)Non-Members = $20\n\nAre you a member? (M/N)");
	scanf("%c", &membership);
	membership = toupper(membership);
if (membership=='M')
	{
		printf("State your age:");
		scanf("%f", &age);
		if (age<65)
		{
			semfee = 10;
			printf("\nThe seminar fee is $%.2f", semfee);
		}
		else if (age>=65)
		{
		   semfee = 5;
		   printf("\nThe seminar fee is $%.2f", semfee);
		}
		else
		{
		   printf("\nInvalid Age Input");
		}
	}
else if (membership=='N')
	    {
	    	semfee = 20;
	    	printf("\nThe seminar fee is $%.2f", semfee);
	    }
else
	    {
	    	printf("\nInvalid Input");
	    }
    printf("\n\n");
	   return 0;
}


