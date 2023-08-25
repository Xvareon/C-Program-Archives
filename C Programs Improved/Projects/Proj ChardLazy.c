#include <stdio.h>

int main()
{
    int i,n;

    printf("Enter number of cuts: ");
    scanf("%d", &n);

    int f[n];
    f[0]=1;
    f[1]=2;
    f[2]=4;
    for (i=3;i<=n;i++)
    {
        f[i]=f[i-1]+i;
    }
      printf("Number of pieces:%d",f[n]);

    return 0;
}
