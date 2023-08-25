#include<stdio.h>
#include<math.h>

void HappyNumber(int start);

int main()
{
    int start;

 printf("Enter a number:");
 scanf("%d",&start);
 printf("\n");

 HappyNumber(start);

 return 0;
}




void HappyNumber(int start)
{
    int num, sum=0, remainder, i;

 if(start!=0)
{ num=start; // tranfered to another variable so the input number can be called to display later.
  while(sum!=1 && sum!=4) // 1 is the number needed to end the loop and 'sum=0' is for the if statement. 4 is the smallest number in the infinite loop.
   {sum=0;
     while(num!=0) //formula to get the sum of the squares of each digit.
      {remainder=num%10; // ex. 25%10=5; remainder=5
       sum=sum+(remainder*remainder); //0+25=25
       num=num/10;} //num= 25/10=2; only 2 because the data type is int(integer). Then, num=2 will enter again to the loop (repeat process).

       num=sum; //num=sum; sum=25+4=29; sum!=0 and num!=0 so it will loop again.
       printf(" %d", num);

   }

  printf("\n");

    if(sum==1)
     printf("\n The number %d is a HAPPY number.", start);

    else
     printf("\n The number %d is an UNHAPPY number.", start);
}


else
    printf("INVALID INPUT");

}

