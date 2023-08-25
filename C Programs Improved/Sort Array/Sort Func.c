#include <stdio.h>
  int main() {
        int n, data[100], i, j, temp;

        /* get the number of entries */
        printf("Enter your input for n:");
        scanf("%d", &n);

        /* get the input data */
        for (i = 0; i < n; i++)
                scanf("%d", &data[i]);

        /* sort the given data in ascending order */
        for (i = 0; i < n-1; i++) {
                for (j = i + 1; j < n; j++) {
                        if (data[i] > data[j]) {
                                temp = data[i];
                                data[i] = data[j];
                                data[j] = temp;
                        }
                }
        }

        /* data in ascending order */
        printf("Ascending Order:\n");
        for (i = 0; i < n; i++)
                printf("%d\n", data[i]);

        /* data in descending order */
        printf("\nDescending Order:\n");
        for (i = n-1; i >= 0; i--)
                printf("%d\n", data[i]);

        return 0;
  }