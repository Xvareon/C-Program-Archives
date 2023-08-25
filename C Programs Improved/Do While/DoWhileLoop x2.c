/**C Program loop that doubles the number you enter and stop when 0 is entered**/

#include <stdio.h>

int main(){
    int Num;

    do{
        printf("\n\nEnter a number: ");
        scanf(" %d",&Num);
        printf("Doubled number: %d",Num*2);
    }while(Num!=0);
    return 0;
}
