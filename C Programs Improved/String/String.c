#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	char strvar[100];
	int i, c, count, letter=0, number=0, symbol=0, space=0;

	printf("Enter string(max 100): ");

	scanf(" %[^\n]", strvar);
	count = strlen(strvar);
	printf("\nThere are %d characters in the word %s\n", count, strvar);

	for (i=0; i<count; i++)
{
	if ((strvar[i]>='A'||strvar[i]>='a')&&(strvar[i]<='Z'||strvar[i]<='z'))
	{
		letter++;
	}
	else if (strvar[i]>='0'&&strvar[i]<='9')
	{
		number++;
	}
	else //if (strvar[i]>=' '&&strvar[i]<='~')
	{
		symbol++;
	}
}
    for (i=0; i<count; i++){
        if (strvar[i]==' '){
            space++;
        }
    }

	printf("\nThere are %d numbers, %d letters and %d symbols in the string %s", number, letter, symbol, strvar);

	printf("\n\nThere are %d words in the string %s\n\n\n", space+1, strvar);

    printf("\nYes: Type 1\nNo: Type 2\nDo you wish to loop? ");
    scanf("%d", &c);
    switch(c){
        case 1:system("cls");main();break;
        default:return 0;break;
    }
}
