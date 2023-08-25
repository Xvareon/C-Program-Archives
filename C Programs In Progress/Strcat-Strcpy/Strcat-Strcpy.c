/** C Program that uses strcat and strcpy**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 31

int main(){
	
	char FName[MAX];
	char MName[MAX];
	char LName[MAX];
	char Name[MAX];
	char Name0[MAX];
	
	printf("Enter your first name(%d):",MAX-1);
	gets(FName);
	printf("Enter your middle name(%d):",MAX-1);
	gets(MName);
	printf("Enter your last name(%d):",MAX-1);
	gets(LName);
	
	strcat(Name," ");
	strcat(Name,FName);
	strcat(Name," ");
	strcat(Name,MName);
	strcat(Name," ");
	strcat(Name,LName);
	strcpy(Name0,Name);
	
	printf("\nHey there, %s %s %s!",FName,MName,LName);
	printf("\nHello there, %s!",Name);
	printf("\nHi there, %s!",Name0);
	
}