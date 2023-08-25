#include<stdio.h>

int main()
{
    printf("Lucky Numbers\n");

    int range;
    printf("Input: ");
    scanf("%d",&range);

    int arr[range], sieve, i, j, x, y;

    //Generates the initial array from 1-range.
    for(i=0;i<range;i++)
    {
        arr[i]=i+1;
    };

    for(i=0;i<range;i++)
    {
        //First two sieving numbers will be at index 1.
        if(i<2) sieve=arr[1];
        else sieve=arr[i];

        for(j=0,x=0,y=0;j<range;j++)
        {
            if((j+1)%sieve!=0)
            {
                arr[x]=arr[j];
                x++; //number of array elements remaining.
            }
            else y++; //number of array elements sieved.
        };

        //Terminates the loop when no more array elements are sieved.
        if(y==0) i=range;

        //Re-evaluates the range as the number of remaining array elements.
        range=x;

    };
    printf("Output:");
    for(i=0;i<x;i++)
    {
        printf(" %d,",arr[i]);
    };
    return 0;
}
