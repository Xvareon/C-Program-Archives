#include <stdio.h>

int main(){
	int i,j,n,a=0;
	scanf("%d",&n);
	i=n;
	
	do{
		printf("\n");
		for(j=n;j>i;j--){
			printf("%d ",j);
		}
		for(j=1;j<=2*i-1;j++){
			printf("%d ",i);
		}
		for(j=i+1;j<=n;j++){
			printf("%d ",j);
		}
		switch(a){
			case 0: i--;
			if(i==0){
				a=1;
				i=2;
			}break;
			case 1: i++; break;
			}
	}while(i<=n);
}