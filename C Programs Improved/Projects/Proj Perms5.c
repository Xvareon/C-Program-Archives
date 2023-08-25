#include <stdio.h>
#include <stdlib.h>

int main()
{    //w=team,x=round,y=1st triangle,z=2nd triangle,n=numner of teams
    int w,x,y,z,n;
//input
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Round \t");
//for the number of teams
    for (w=1;w<=n;w++)
    {
       printf("Team %d \t",w);
    }
    printf("\n");
//For Even number teams
if(n%2==0)
    {
    for (x=1;x<=n;x++)
    {
         printf("%d \t",x);
         for (y=x-1;y>=1;y--)
            {
             printf("%d \t",y);
            }
             for (z=n;z>=x;z--)
              {
                printf("%d \t",z);
              }
               printf("\n");
            }
   }
//For odd number teams & the presence of Bye
else
{
     for (x=1;x<=n;x++)
       {
         w=0;
         printf("%d \t",x);
         for (y=x-1;y>=1;y--)
            {
            w++;
            if (y==w)
            {
                printf ("bye\t");}
            else
             printf("%d \t",y);
            }
             for (z=n;z>=x;z--)
              {
            w++;
            if (z==w)
            {
                printf ("bye\t");}
            else
                printf("%d \t",z);
              }
               printf("\n");
            }
    }
    return 0;
}