//Program for last digits
#include<stdio.h>
#include<math.h>

//Function for raising the base number then raises it again using the power function then returns it to 1
unsigned long long int exponentiation(unsigned long long int b,unsigned long long int i)
{
    if (i != 0)
    {
        return pow(b,exponentiation(b, i-1));
    }
    else
    {
        return 1;
    }
}

int main()
{
    unsigned long long int n, b, i, result;

    //For inputting the values
    printf("Input value for base(1-100): ");
    scanf("%llu", &b);
    while(b <= 0 || b > 100)
    {
       if(b==0){
        printf("ERROR! Input value for \"base\" is zero. Bye!\n");
        return 0;
        }
        printf("Please enter a number again(1-100): ");
        scanf("%llu",&b);
    }
    printf("Input value for iteration(1-100): ");
    scanf("%llu", &i);
    while(i <= 0 || i > 100)
    {
        printf("Please enter a number again(1-100): ");
        scanf("%llu",&i);
    }
    printf("Input value for decimal digit(1-7): ");
    scanf("%llu", &n);
     while(n <= 0 || n > 7)
    {
        printf("Please enter a number again(1-7): ");
        scanf("%llu",&n);
    }

    //The res array here is making all the indeces into zero
    int res[n];
    for(int itr=0; itr<n; itr++)
    {
        res[itr] = 0;
    }

    result = exponentiation(b, i);
    //printf("%d", result);

    //The loop here gets the remainder and then divides it into ten then decrements to get to tbe other index
    int itr=n-1;
    while(result != 0)
    {
        res[itr] = result % 10;
        result = result / 10;
        itr--;
    }

    //This here gets the res array and prints it
    printf("\n\nOutput: ");
    for(int itr=0; itr<n; itr++)
    {
        printf("%d", res[itr]);
    }
    printf("\n");
    return 0;
}
