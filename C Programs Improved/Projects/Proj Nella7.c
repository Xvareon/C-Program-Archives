#include <stdio.h>
#include <stdlib.h>

int xt(int o);
static int limit=0;

int main(){
    int j, k;

    printf("Enter the digits you want to get the smallest absolute difference:  \n");
    scanf("%9d",&j); //%9d = records the first 9 digits inputted, regardless of # of input

    if(j>0){
        k=xt(j); //k accepts values returned by xt function...
        while(k!=1){
            k=xt(k); //recursion...
            limit++;
            if(limit>10){ //infinity, unhappy num...
               break;
            }
        }
        if(limit<10){
        printf("%d is a Happy Number!",j);
        } else {
            printf("%d is Unhappy Number",j);
        }
    } else { printf("Error"); }
    return 0;
}

int xt(int x){
    int c=0, y, *p;
    p=(int*)calloc(10,sizeof(int)); //allocate size for pointer p, p becomes array...

    for(int j=0;x>0;j++){
        y=x%10; //remainder
        x/=10; //x=x/10;
        p[j]=y; //records y values in j index...
    }

    for(int i=0;i<10;i++){
        c+=(p[i]*p[i]); //c=c+(p[i]*p[i]);
    }
    printf("%d\n",c);
    free(p); //removes all elements in array pointer...
    return c;
}
