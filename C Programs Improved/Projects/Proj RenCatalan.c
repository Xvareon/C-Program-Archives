#define __USE_MINGW_ANSI_STDIO 1
// * On Windows, format specifiers like "%llu" will not work for 64bit integers. Therefore this definition is utilized to solve that issue. * //
#include <stdio.h>
#include <stdlib.h>

/* The reason why the students opted for unsigned long long int is because it had the capability to display the catalan numbers up to 30
    the other data types could not properly handle the catalan numbers and would break at the 10th or 15th, etc.. */

    unsigned long long int
    binom_Coeff(unsigned int n, unsigned int k)
    {
        unsigned long long int outcome = 1;
        int i;
        /* | C(n, k) = C(n, n-k) | Distinguished property of combinatorics. In this instance, Binomial Coefficient was a concept used to apply the
        recursive formula. */
        if (k > n - k)
            k = n - k;
        /* Getting the value of nCk */
        for (i = 0; i < k; ++i) {
            outcome *= (n - i);
            outcome /= (i + 1);
        }
        return (outcome);
    }
    /* Using the binom_coef program to map out the Catalan numbers: finalization*/

    unsigned long long int
    catal(unsigned long long int n)
    {
        /* Getting the value of 2nCn */
        unsigned long long int c = binom_Coeff(2 * n, n);
        /* returning value of 2nCn/(n+1) */
        return (c / (n+1));
    }
    /*  Main program presented:. */

    int main()
    {
        unsigned int n;
        scanf("%d", &n);
        printf("%llu", catal(n));
        return (0);
    }
