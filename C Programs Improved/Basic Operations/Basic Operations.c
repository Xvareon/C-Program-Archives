/**C Program that prints the answer of two numbers for four operations**/

#include <stdio.h>

int main(){
    float n1, n2;

    while(n1!=0 || n2!=0){
        printf("Basic Calculator \n\n\n");
        printf("\n\nEnter first number: ");scanf(" %f",&n1);
        printf("Enter second number: ");scanf(" %f",&n2);
        printf("\nThe sum of %.0f and %.0f is %.0f",n1,n2,(n1+n2));
        printf("\nThe difference of %.0f and %.0f is %.0f",n1,n2,(n1-n2));
        printf("\nThe product of %.0f and %.0f is %.0f", n1,n2,(n1*n2));
        printf("\nThe quotient of %.0f and %.0f is %.2f", n1,n2,(n1/n2));
        getch();
        system("cls");
    }
    printf("\n\nThank You for using the program!\n\n");
	return 0;
}
