#include <stdio.h>
#include <string.h>

void DisplaySalary(float Salary, char Dept);

int main()
{
char Dept;
float Salary;

puts("Codes for Departments are: \nA - 2% raise\nB - 2% raise\nC - 1.5% raise\nD - 3% raise\n\n\n");
puts("Salary Program\n");
printf("Enter your Department Code to view bonus:\t");
scanf("%c", &Dept);
Dept = toupper(Dept);
printf("Enter your Salary:\t");
printf("$");
scanf("%f", &Salary);

DisplaySalary(Salary, Dept);
return 0;
}

void DisplaySalary(float Salary, char Dept)
{
	float raise, AmtAB, AmtC, AmtD;
	
	if (Dept=='A' || Dept=='B')
	{
		raise = Salary*0.02;
		AmtAB = Salary + raise;
		printf("The total salary for $%.2f is:\t", Salary);
		printf("$%.2f", AmtAB);
		printf("\nYour raise was: $%.2f", raise);
	}
	
	else if (Dept=='C')
	{
		raise = Salary*0.015;
		AmtC = Salary + raise;
		printf("The total salary for $%.2f is:\t", Salary);
		printf("$%.2f", AmtC);
		printf("\nYour raise was: $%.2f", raise);
	}
	
	else if (Dept=='D')
	{
		raise = Salary*0.03;
		AmtD = Salary + raise;
		printf("The total salary for $%.2f is:\t", Salary);
		printf("$%.2f", AmtD);
		printf("\nYour raise was: $%.2f", raise);
	}
	
	else
	puts("Invalid Input");
}
	