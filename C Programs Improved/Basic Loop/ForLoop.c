/**C Program that repeats a string based on user input**/

#include <stdio.h>

int main(){
    int i,Num;
    char Letter[20];

    printf("Enter word or phrase you want to repeat(20 max chars): ");
    scanf(" %s",Letter);
    printf("\nEnter how many times you want to repeat the word: ");
    scanf(" %d",&Num);
    printf("\n");
    for(i=0;i<Num;i++){
        printf("[%d]%s\n",i+1,Letter);
    }
    return 0;
}
