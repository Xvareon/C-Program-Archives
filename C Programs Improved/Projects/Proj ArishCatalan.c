#include <stdio.h>
#include<stdlib.h>

long long unsigned int fact(long long unsigned int);

int main()
{
long long  signed int n;
long long  unsigned int r=1;
long long  unsigned int Catalan;

    printf("Enter a number n\n");
    scanf("%llu",&n);
    system("cls");

    if(n<0)
    {
        printf("Thank You");
    }
    else
    {
        while (n>=0)
        {
        Catalan=fact(2*n)/(fact(n+r)*fact(n));
        printf("Value of Catalan %llu is %llu \n",n,Catalan);
       // Catalan++;
        printf("\nEnter the number:");
        scanf("%llu",&n);
        system("cls");
        }
    }

}
long long unsigned int fact(long long unsigned int  n)
{
long long unsigned int i,f=1;

for(i=1;i<=n;i++)
{
f=f*i;
}
return f;
}
