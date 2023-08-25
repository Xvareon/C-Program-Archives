#include<stdio.h>
#include<stdlib.h>


int num;
int A [6];
int *bin(int n)
{
    int c;
    for(c=num-2; c>=0; c--)
    {
        if(n==1)
        {
            A[c]=n;
            c--;
            while(c>=0)
            {
                A[c]=0;
                c--;
            }
            break;
        }
        A[c]=n%2;
        n=n/2;
    }
    return A;
}

int main()
{
    int sum,i,j, count = 0;
    int comb=1,expo=0,base=2;
    int *p;

    printf("All is Nothing\n");
    printf("ENTER NUMBER: ");
    scanf("%d",&num);
    sum=1;
    expo=num-1;
    for(i=1; i<=expo; i++)
    {
        comb=comb*base;
    }
    comb=comb-1;
    for(i=comb; i>=0; i--)
    {
        p=bin(i);
//printf("\n");
        for(j=1; j<=num-1; j++)
        {
            if(*(p+(j-1))==1)
            {
                sum=sum+(j+1);
            }
            else
            {
                sum=sum-(j+1);
            }
        }
        if(sum==0)
        {
            count ++;
            printf("\n");
            int x=0;
            printf("%d",x+1);
            while(x <(num-1))
            {
//printf("%d",x+1);
                if(*(p+x)==1)
                {
                    printf("+");
                }
                else {
                    printf("-");
                }
                ++x;
                printf("%d",x+1);
//++x;
            }
            printf("=0");
        }
        sum=1;
    }
;
    if(count==0)
    printf("No possible COMBINATIONS");

}
