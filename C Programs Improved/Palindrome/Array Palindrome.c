#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

void pa(char let[],int L);

int main()
{
    int Le, c;
	char arr[100];
	scanf("%s",arr);
    Le = strlen(arr);
    pa(arr,Le);

    printf("\n\nDo you want to loop?\n\nYes -->1\n\nNo -->2\n\n");
    scanf("%d",&c);
    switch(c){
    case 1:system("cls");main();break;
    default:return 0;break;
    }

}

void pa(char let[],int L){

    int i, j;
    int flag=0;

	for (i=0;i<L;i++)
	let[i] = toupper(let[i]);

	for (i=L-1; i>=0; i--)
	{
		printf("%c", let[i]);
	}
	for (i=0,j=L-1; i<L,j>=0; i++,j--)
	{
		if (let[i]==let[j])
		flag++;
	}


	if (flag==L)
	printf("\n\nPalindrome\n\n");
	else
	printf("\n\nNot a Palindrome\n\n");
}
