#include <stdio.h>

float OtPay(float RegHrRate, float OvtWork);
float GrossPay(float RegPay, float RegHrRate, float OvtWork);
float Deduction(float RegPay, float RegHrRate, float OvtWork);
void NetPay(float AmtNetPay);
float Total(float RegPay, float RegHrRate, float OvtWork);

int main()
{
    float RegPay, RegHrRate, AmtNetPay, OvtWork;
    printf("What is your Regular hourly rate?: ");
    scanf("%f", &RegHrRate);
    printf("What is your Total hours of work?: ");
    scanf("%f", &RegPay);
    printf("What is your Total Overtime Work?: ");
    scanf("%f", &OvtWork);

    printf("\n\nRegular Pay: $%.2f",(RegHrRate*RegPay));
    printf("\n\nOvertime Pay: $%.2f",OtPay(RegHrRate, OvtWork));
    printf("\n\nGross Pay: $%.2f",GrossPay(RegPay, RegHrRate, OvtWork));
    printf("\n\nDeduction Tax: $%.2f",Deduction(RegPay, RegHrRate, OvtWork));
    AmtNetPay = Total(RegPay, RegHrRate, OvtWork);
    NetPay(AmtNetPay);

    return 0;

}


float OtPay(float RegHrRate, float OvtWork)
{
    float OtPay;
    OtPay = RegHrRate * OvtWork * 1.5;
    return OtPay;
}

float GrossPay(float RegPay, float RegHrRate, float OvtWork)
{
    float GrossPay;
    GrossPay = RegPay * RegHrRate + OtPay(RegHrRate, OvtWork);
    return GrossPay;
}

float Deduction(float RegPay, float RegHrRate, float OvtWork)
{
	float DeductionTax, Total;
	DeductionTax = GrossPay(RegPay, RegHrRate, OvtWork) * .32;
    return DeductionTax;
}

float Total(float RegPay, float RegHrRate, float OvtWork){
    float Total;
    Total = GrossPay(RegPay, RegHrRate, OvtWork) - Deduction(RegPay, RegHrRate, OvtWork);
    return Total;
}

void NetPay(float AmtNetPay)
{
    printf("\n\nYour Total Net Pay is $%.2f", AmtNetPay);
    printf("\n");
}



