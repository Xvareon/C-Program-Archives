#include <stdio.h>

int main()
{
    int i,n;

    printf("Enter nth fibonacci sequence: ");
    scanf("%d", &n);

    int f[n];
    f[0]=0;
    f[1]=1;
    
    printf("%d ", f[1]);
   
    for (i=2;i<=n;i++)
    {
        f[i] = f[i-2] + f[i-1];
        printf("%d ", f[i]);
    }
      

    return 0;
}