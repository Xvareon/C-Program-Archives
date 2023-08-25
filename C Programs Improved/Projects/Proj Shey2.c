#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
unsigned long long int exponentiation(int base, int exponent){
    if(exponent != 0)
        return (base*exponentiation(base, exponent-1));
    else
        return 1;
}
int main()
{
	int b,i,N;
	scanf("%d\n%d\n%d",&b,&i,&N);
	int y;
	unsigned long long d = 1;
	for(y = 0; y < N; y++){
		d *= 10;
	}
    unsigned long long int x;
    x = exponentiation(exponentiation(b,i),i);
    if(x > d){
    	printf("%llu\t", x);
    	printf("%llu", x%d);
	}
	else{
		unsigned long long duplicate = x;
		int mark = 0;
		while(duplicate < d){
			duplicate *= 10;
			mark++;
		}
		mark--;
		for(y = 0; y < mark; y++){
			printf("0");
		}
		printf("%llu", x);
	}
    return 0;
}
