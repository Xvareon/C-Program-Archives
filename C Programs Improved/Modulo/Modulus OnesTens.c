#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int Mod(int x);

int main()
{
    int n;
    printf("Please input a number: ");
    scanf("%d",&n);

    Mod(n);

    printf("\n\n");
	return 0;
}

int Mod(int x){

    int i, c, num[4];
    int d[4]={1,10,100,1000};
    char pos[4][10]={"ones", "tens", "hundreds", "thousands"};

    for (i=0; i<4; i++){
        num[i] = x%(d[i]*10)/d[i];
        printf("\nThe %s in this number is %d ", pos[i], num[i]);
    }

    printf("\n\nDo you want to loop?\n\nYes -->1\n\nNo -->2\n\n");
    scanf("%d",&c);
    switch(c){
    case 1:getch();system("cls");main();break;
    default:return 0;break;
    }
}
