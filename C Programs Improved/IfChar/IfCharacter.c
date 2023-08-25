#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

char charactertype(char code);


int main()
{
	char ch, c;

	printf("\n\nInput Character: ");
	scanf("%c", &ch);

	c = charactertype(ch);
	if (c=='0')
	printf("\nThe character %c is a number.", ch);
	else if(c=='1')
	printf("\nThe character %c is a letter.", ch);
	else
	printf("\nThe character %c is a symbol.", ch);

    printf("\n\n\n");
    return 0;
}

char charactertype(char code)
{
	code = toupper(code);
	if (code>='0' && code <='9')
	return '0';

	else if (code>='A' && code <='Z')
	return '1';

	else
	return 's';
}
