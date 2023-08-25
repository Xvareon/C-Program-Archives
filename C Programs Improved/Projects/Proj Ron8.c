#include<stdio.h>

int main() {
    int faulty, digit, ctr=0, ctr2=0, fixed=0;

    printf("Faulty Odometer\nEnter Odometer reading: ");
    scanf("%d",&faulty);

    //Scans for the digit 4 and counts the number of digits of the input.
    for(int i=0, divisor=1; i<9; i++) {
        divisor=divisor*10;
        ctr++;

        //Gets the digit at the (i+1)th place value.
        digit=(faulty%divisor-faulty%(divisor/10))/(divisor/10);

        //Terminates the loop when leftmost digit is reached or digit '4' is encountered.
        if(faulty%divisor==faulty||digit==4)
        {
            if(digit==4) ctr2=1;
            i=9;
        }
    }

    if(ctr2==1)
    {
        printf("Input should not contain digit '4'.");
        return 0;
    };

    //Converts input to base 10.
    for(int i=0, divisor=1; i<ctr; i++)
    {
        divisor=divisor*10;
        digit=(faulty%divisor-faulty%(divisor/10))/(divisor/10);

        //Digits greater than 4 is decreased by 1.
        if(digit>4) digit=digit-1;

        int mult=1;
        for(int j=0;j<i;j++)
        {
            mult=mult*9;
        }
        fixed=fixed+digit*mult;

    }

    printf("%d: %d",faulty,fixed);
    return 0;
}
