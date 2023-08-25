#include<stdio.h>

int main(){
int n;
    scanf("%d", &n);
    for(int i=0;i<n*2-1;i++){
        for(int j=0;j<n*2-1;j++){
            if((j<i&&i<n)||(j<n*2-2-i&&i>n-1))  printf("%d ",n-j);
            if((j>=i&&j<=n*2-2-i)||(j>=n*2-2-i&&j<=i)){
                if(i>n-1)
                        printf("%d ",i-n+2);
                else
                        printf("%d ",n-i);
            }
            if(j>n*2-2-i&&j>i)printf("%d ",j-n+2);
        }
        printf("\n");
    }
    return 0;
}