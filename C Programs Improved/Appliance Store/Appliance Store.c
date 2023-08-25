/**C Program that sells appliances(my very first C program!!!)**/

#include <stdio.h>

int main(){
    float n[5]={400,220,35,300,150};
    float sum=0,quan;
    int i;

    printf("This is AB company, We are selling the following items:\n\n");
	printf("Item #1)TV = $400\n");
	printf("Item #2)VCR = $220\n");
	printf("Item #3)Remote Controller = $35\n");
	printf("Item #4)CD Player = $300\n");
	printf("Item #5)Tape Recorder = $150\n\n\n");

	for(i=0;i<5;i++){
        printf("\n\nFor Item #%d, how many would you like to purchase? ", i+1);
        scanf(" %f",&quan);
        printf("bill for Item #%d is $%.2f",i+1,(n[i]*quan));
        sum+=(n[i]*quan);
        printf("\nCurrent subtotal bill is $%.2f",sum);
	}
    printf("\n\nTotal bill for the items is $%.2f\n\n",sum);
	return 0;
}
