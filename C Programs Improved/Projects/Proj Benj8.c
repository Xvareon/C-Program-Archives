#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, len,value;
	float BrkOdometer;
	char OrigOdometer1[10], OrigOdometer2[10];
	while(scanf("%s", OrigOdometer1)== 1 && strcmp(OrigOdometer1, "0")!= 0) // will continue not until OrigOdometer1 = 0.
    {
        // Sample input: OrigOdometer1 = 5, OrigOdometer[0] = '5' or ASCII value = 52.
		strcpy(OrigOdometer2,OrigOdometer1); // transfer the value of OrigOdometer1(5) to OrigOdometer2(becomes 5)
		value = atoi(OrigOdometer2); // convert string to integer to remove leading zero
		len = strlen(OrigOdometer2); // reads and store the length of OrigOdometer2, if input = 5, len = 1
		BrkOdometer = 0; // assigned 0 for reset
		for(i = 0; i < len; i++) // only 1 loop passed since i = 0 < len = 1
		{
			if(OrigOdometer1[i] >= 52 || OrigOdometer1[i] >= '4' ) /* based of ASCII table, '4' has a value of 52,
                if inputted string is OrigOdometer1[0] = 5, it has an ASCII value of 53 */
				OrigOdometer1[i]--; // OrigOdometer1[0] =  53, so 53 - 1, OrigOdometer1[0] = 52
            BrkOdometer += ((int)OrigOdometer1[i]-48)*(float)pow(9,len-i-1); // converting string to real numbers
                    // ((int)52-48)*(float)pow(9,1(since length of 5 is one) - 1 - 0) = 4
                    // BrkOdometer = 4
		}
		printf("%d: %.0f\n",value,BrkOdometer); // value = 5, BrkOdometer = 4
	}
    return 0;
}


