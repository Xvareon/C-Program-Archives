#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

char Name[3][31]={"Mel","GasPar","Bal"};
int locate(char n[31]){
int i;
for (i=0;i<MAX;i++){
    if(strcmp(n,Name[i])==0)
        return(i);
}
return(-1);
}
int main(){
    int i;
    char nam[31];
    printf("Input name: ");
    scanf("%s",nam);
    i = locate(nam);
    if (i<0)
        printf("Not found.");
    else
        printf("%s is at %d",nam,i);

    }



