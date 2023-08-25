/*Submitted by: Malunes,Kayshia Princess
                Orquillo,Jhonella Jazmine
                Tario,Marielle Louise

"LUCKY NUMBERS"             */

#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number till which you want to print the lucky series:");
    scanf("%d",&n);

    int num[n], q=1, i;
    for(i=0;i<n;i++){
            num[i]=q;
            q++; //initialize array elements...
    }
printf("Series: \n");
    for(i=0;i<n;i++){
        printf("%d ",num[i]);
    }

    int kth,j,k,x;
    for(i=0;i<n;i++){
        if(i<2){
            kth=num[1];//determines the lucky number
        }
        else{
            kth=num[i];
        }
        for(x=0,j=0,k=0;x<n;x++){
            if((x+1)%kth!=0){ //sieve of erathosthenes alike...
            num[j]=num[x]; //gets the lucky number...
            j++;
            }
            else k++;
        }
        if(k==0)
            i=n; //terminate loop...
            n=j; //number of lucky numbers...
    }
    printf("\n");
    printf("Lucky numbers: \n");
    for(i=0;i<j;i++){
        printf("%d ",num[i]);
    }
    return 0;
}
