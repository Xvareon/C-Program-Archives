#include<stdio.h>
#include<math.h>

int main ()
{
int n,temp,r,digits=0,sum;

printf("Enter the number:");
scanf("%d",&n);

temp=n;
    while(temp>0)
    {
    r=temp%10;
    digits++;     //knowing how many digits you input.
    temp/=10;
    }

    temp=n;   // overwrite the value of temp in the first while so that it return the value that the user input.
    sum=0;
    while(temp>0)
    {
        r=temp%10;
        sum+=pow(r,digits); // this loop is pertaining the logic of armstrong which is the number of digits serve as exponent.
        temp/=10;           // the r or the remainder serve as base. And lastly the line 24 divide the n to prevent infinite loop.
    }
    //printf("%d",sum);

    if (n==sum/*||n==153*/)
    {
        printf("%d is an Armstrong Number\n",n);
    }
    else
        printf("%d is not an Armstrong Number\n",n);
}