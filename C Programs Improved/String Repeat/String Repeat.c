/**C program that counts repeated characters**/

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>  
#define MAX 20

int main(){  

    char string[MAX];  
    int count;  
    
      printf("Enter a string: ");
      scanf(" %[^\n]",string);
    printf("\nDuplicate characters in a given string: \n");  
    //Counts each character present in the string  
    for(int i=0;i<strlen(string);i++){  
        count=1;  
        for(int j=i+1;j<strlen(string);j++){  
            if((string[i]==string[j]) && (string[i] != ' ')){  
                count++;  
                //Set string[j] to 0 to avoid printing visited character
                string[j]='0';  
            }  
        }  
        //A character is considered as duplicate if count is greater than 1  
        if(count>1&&string[i]!='0')  
            printf("%c\n", string[i]);  
    }  
    return 0;  
    
}  