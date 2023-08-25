//LAST DIGITS
#include<stdio.h>
#include<math.h>
int main()
{
// INPUT
    int b, i, n;
    unsigned long long int ans, result, digit;
    unsigned long long int count=0, j;

    printf("Input(b):");
    scanf("%d", &b);
// if b is equal to zero, the program will be terminated.
    if(b!=0)
{   printf("Input(i):");
    scanf("%d", &i);
    printf("Input(n):");
    scanf("%d", &n);


//to get the answer
ans=pow(b,i);//f(x)=bf(x-1) iteration count
result=pow(ans,i);//printf("The computed answer is %llu", result);
printf("The answer is %llu", result);

//for getting the number of digits of the result
digit=result;
while(digit>0)
{
    digit=digit/10;
    count++;
}//printf("%llu", count);

// OUTPUT
//for getting the number of zeros to be added to the left
printf("\n\nOutput:\n");
printf("\nThe last n digit/s: ");
if(count<n)
{
    for(j=0; j<n-count;j++)
      {printf("0");}
    printf("%llu", result);
}

if(count>n)
{   unsigned long long int number[count];
    int countvar=count-1;
     while(result!=0)
     {
         number[countvar]=result%10;
         result=result/10;
         countvar--;
     }

    for(i=count-n;i<count;i++)
        printf("%llu", number[i]);
}

if(count==n)
    printf("%llu", result);
}

else
    printf("INVALID INPUT");


return 0;
}