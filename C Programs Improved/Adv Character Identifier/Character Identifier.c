/**C Program that determines whether the input is a character, digit or symbol**/

#include <stdio.h>
#include <ctype.h>

int main(){
	int any;
	printf("Input: ");
	scanf(" %c",&any);

	if(isalpha(any)){
		if(isupper(any)){
			printf("%c is an uppercase letter",any);
		}else{
			printf("%c is a lowercase letter",any);
		}
	}
	else{
		if(isdigit(any)){
			printf("%c is a number",any);
		}else{
			printf("%c is a symbol",any);
		}
	}
	return 0;
}
