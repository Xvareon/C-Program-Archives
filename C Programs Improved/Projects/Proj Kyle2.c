
//ALL IS NOTHING

#include<stdio.h>
#include<conio.h>
#include<math.h>

void Conditions(int n);
void CalcCombinations(int n);
int Signs(int n, int terms[]);
// variables
    int r, terms[10];
    int a=1,b=1,c=1,d=1,e=1,f=1,g=1;
    int combination;
// Main Program
  int main()
{
    int n;
    printf("Enter Number of Terms(N<=9):");
    scanf("%d",&n);

    Conditions(n);

}
// Sub Program - In main
void Conditions(int n)
{
    int i, result=0;
    for(i=0;i<n;i++)
            {terms[i]=i+1;
            result=result+terms[i];}
    result=result%2;

   if(n<=9 && n!=0)
    {if(result!=0)
        {printf("\nNo possible combinations.\n");}

    else if(result==0)
        {CalcCombinations(n);}
    }
    else
        {printf("\nInvalid Input.\n\n Tip: Try a number from one to nine.");}
}

//Sub Program - In void Conditions
void CalcCombinations(int n)
{
    r=n;
        for(int i=0;i<r;i++)
            {terms[i]=i+1;}

        double combination=pow(2,r-1);
        int loopCount=1;
        printf("\nThe possible combinations are:\n");
        while(loopCount<=combination)
        {  int sum=terms[0];//1
            for(int i=1;i<r;i++)
            {sum=sum+terms[i];}

            if(sum!=0)
            { for(int i=0;i<r;i++)
                {printf("%d ",terms[i]);}
             printf("=0\n");
            }
         Signs(n,terms);
         loopCount++;
        }
}




// Sub Program - In void CalcCombinations
int Signs(int n, int terms[])
{

    terms[n-1]=-terms[n-1];
    if(n==2)
    return 0;
    if(a==2)
    {
        terms[n-2]=-terms[n-2];
        a=1;
    }
    else
        a++;
    if(n==3)
    return 0;
    if(b==4)
    {
        terms[n-3]=-terms[n-3];
        b=1;
    }
    else
    b++;
    if(n==4)
    return 0;
    if(c==8)
    {
        terms[n-4]=-terms[n-4];
        c=1;
    }
    else
    c++;
    if(n==5)
    return 0;
    if(d==16)
    {
    terms[n-5]=-terms[n-5];
    d=1;
    }
    else
    d++;
    if(n==6)
    return 0;
    if(e==32)
    {
        terms[n-6]=-terms[n-6];
        e=1;
    }
    else
    e++;
    if(n==7)
    return 0;
    if(f==64)
    {
        terms[n-7]=-terms[n-7];
        f=1;
    }
    else
    f++;
    if(n==8)
    return 0;
    if(g==128)
    {
        terms[n-8]=-terms[n-8];
        g=1;
    }
    else
    g++;
    if(n==9)
    return 0;
}

