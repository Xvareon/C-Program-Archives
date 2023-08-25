#include <stdio.h>

float smallest(int s, float n[]);


int main()
{
    int i, s;
    printf("Enter number of integers to be compared: ");
	scanf("%d", &s);
	float num[s];
	printf("\nEnter %d integers:\n", s);

    for (i=0;i<s;i++){
        scanf("%f", &num[i]);
    }

	printf("\nThe smallest value in ");
	for (i=0;i<s-1;i++){
        printf("%.0f, ", num[i]);
    }printf("\b\b and %.0f", num[s-1]);

    printf(" is %.0f", smallest(s,num));

    printf("\n\n");
    return 0;
}

float smallest(int s, float n[])
{
    int i, j, sm=n[0], hold;
    for (i=0;i<s;i++){
        for (j=0;j<s;j++){
            if(n[i]<n[j]){
                hold=sm;
                sm=n[i];
            }
            if (sm>hold){
                sm=hold;
            }
        }
    }
    return sm;
}
