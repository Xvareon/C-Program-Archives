    ``#include<stdio.h>
#include<stdlib.h>

int main ()

{
    int a,b,c,d,n;

    while(n>=1)
    {
    printf("Enter the number : ");
    scanf("%d",&n);
    if(n%2!=0)
    {
    printf("Round\t");
    for(a=1;a<=n;a++)
        {
        printf("Team %d \t",a);
        }
    printf("\n");

        for(b=1;b<=n;b++)
        {
        a=0;
        printf("%d\t",b);
        for(c=b-1;c>=1;c--)
            {
           a++;
            if(c==a){
                printf("Bye\t");}
            else{
                printf("%d\t",c);}
            }

      for(d=n;d>=b;d--)
            {
            a++;
            if(d==a){
                printf("Bye\t");}
            else
                {printf("%d\t",d);}
            }
            printf("\n");

        }
    }

    else
        {

        printf("Round\t");
        for(a=1;a<=n;a++)
            {
                printf("Team %d \t",a);
            }
        printf("\n");

        for(b=1;b<=n;b++)
            {
                printf("%d\t",b);
        for(c=b-1;c>=1;c--)
            {
                printf("%d\t",c);
            }


        for(d=n;d>=b;d--)
            {
                printf("%d\t",d);
            }
            printf("\n");


            }

        }

    }
        system("cls");
        printf("Invalid");
}
