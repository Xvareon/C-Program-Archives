/*Submitted by: Malunes,Kayshia Princess
                Orquillo,Jhonella Jazmine
                Tario,Marielle Louise

"SMALLEST DIFFERENCE"                            */
#include <stdio.h>

static int g[2];
static int p[11];
static int limit;

void swap(int *y,int *z){
    int x=*y;
      *y=*z;
      *z=x;
}

void per(int *arr,int st,int q,int r,int l){
    int i=0,v=0,b=0,res;
    int n[5]={1,10,100,1000,10000};
    if(l==2){
        res=arr[0]-arr[1];
        goto alt;
    }
    if(st==l){
        for(int j=0;j<q;j++){
            v+=arr[j]*n[q-1-j]; //v=v+arr[j]*n[q-1-j];
        }
        for(int j=0;j<r;j++){
            b+=arr[j+(l%2!=0?r+1:r)]*n[r-1-j]; //b=b+arr[j+(l%2!=0?r+1:r)]*n[r-1-j];
        }


        if(v>n[q-1] && b>n[r-1]){
            for(int k=0;k<l;k++){
                printf("%d ",arr[k]);
            }
            printf("%d-%d ",v,b);
            res=v-b;
            alt:
            if(res<0){
                res=-res;
            }
            printf(" = %d",res);
            g[0]=res;
            if(limit==0){
                g[1]=g[0];
            }
            if(g[0]<g[1]){
                g[1]=g[0];
            }
            limit++;
            printf("\n");
        }
    } else {
        for(i=st;i<l;i++){
            swap(arr+st,arr+i); //swap array values...
            per(arr,st+1,q,r,l); //permutation
            swap(arr+st,arr+i); //swap array +1 index values...
            }
        for(i=st+r+1;i<l;i++){    //2nd pair permutation...
            swap(arr+st,arr+i);
            per(arr,st+r,q,r,l);
            swap(arr+st,arr+i);
            }
    }
}

int main(){
    int l;

    for(int i=0;i<11;i++){
        p[i]=-1; //initialize all array elements to -1, since zero is part of the input...
    }

    printf("\nEnter the digits you want to get the smallest absolute difference:  \n(Enter x to submit)\n");
    for(int i=0;i<11;i++){
        scanf("%xd",&p[i]); //input loop, breaks when scanned "x" (%xd)...
    }

    for(l=0;p[l]!=-1;l++); //counts # of input...
    //printf("\n%d",l);
    int r,q=l;
    if(q%2==0){ //creating pair digits...
        q/=2;
        r=q;
    } else {
        r=q/2;
        q-=r;
    }
    per(p,0,q,r,l); //function call...
    printf("\n%d",g[1]); //smallest difference
    return 0;
}
