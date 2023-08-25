/**C Program that calculates bills**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float CalcEnvelopes(float No,float Chrg);
float CalcPages(float No,float Chrg);
void CalcBill(char n[]);

int main(){
    char Name[20];

	printf("Enter Customer Name:\t");
	scanf("%s", Name);

    CalcBill(Name);
    return 0;
}

float CalcEnvelopes(float No,float Chrg){
    float AmtEnv;
	AmtEnv=No*Chrg;
	printf("\nYou are billed for $%.2f for Envelopes\n\n",AmtEnv);
	return AmtEnv;
}

float CalcPages(float No,float Chrg){
    float AmtPg;
	AmtPg=No*Chrg;
	printf("You are billed for $%.2f for Pages\n\n",AmtPg);
	return AmtPg;
}

void CalcBill(char n[]){
    float No1,No2,Chrg1,Chrg2,AmtBill;

    printf("\nHow many Envelopes would the customer like to buy?: ");
	scanf(" %f",&No1);
	printf("How much is the charge for the Envelopes?: $");
	scanf(" %f",&Chrg1);

	printf("\nHow many Pages would the customer like to buy?: ");
	scanf(" %f",&No2);
	printf("How much is the charge for the Pages?: $");
	scanf(" %f",&Chrg2);

    AmtBill=CalcEnvelopes(No1,Chrg1)+CalcPages(No2,Chrg2);

    printf("%s, ",n);
	printf("Your Total Bill is $%.2f\n\n",AmtBill);
}
