#include <stdio.h>

void CalcUlam(int ulam_x[],int search);//function for computing the ulam numbers

int main()
{
    int i,a;
    int search;

    printf("Enter a number: ");//number to be searched
    scanf("%d", &search);//integer to be search is the size of array

    int ulam_x[search];//declaration after scanning for array size

    CalcUlam(ulam_x,search);//will return the array of ulam numbers

    for (i=0;i<=search;i++)//searching of the ulam number in the array
    {
        if (search==ulam_x[i])
            a=1;//a will be the marker if the number is found in the array
    }
    if (a==1)
    {
        printf("Ulam");
    }
    else
    {
        printf("Not Ulam");
    }

    return 0;
}
void CalcUlam(int ulam_x[],int search)
{
    int x,y,z,b=2;//b is equal to 2 since it is the next index,it will also11 act as a limiter
    int num;

    //Starting Ulam Numbers
    ulam_x[0]=1;
    ulam_x[1]=2;

    for (x=3; x<=search;x++)//looping of indexes until the size starting from 2
    {
        num=0;//num value wil reset to zero after the two loops
        //searching for integers to be added
        for (y=0; y<b; y++)//loop for searching the first integer
        {
            for (z=y+1; z<b; z++)//loop for 2nd integer starting next to the 1st integer
            {
                if (ulam_x[y]+ulam_x[z]==x)
                {
                    num+=1;//num value will increase if the right integers are found
                }
            }
        }
        if(num==1)//since ulam numbers are sum of two distinct earlier term of the sequence in exactly one way.
        {
            ulam_x[b]=x;//index b is equal to x if the condition is true
            b++;//the next index will be used
        }
    }
}
