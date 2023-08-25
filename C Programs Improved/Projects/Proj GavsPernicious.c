// function to check prime number 
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int x);
void printPernicious(int n);

int main() 
{ 

   int n; 
   
   printf("Enter number of prime ones: ");
   scanf("%d", &n);
   printf("\n");
   printf("Pernicious numbers: \n");
   printPernicious(n); 

   return 0; 
}

bool isPrime(int x) 
{ 

    if (x < 2) 

        return false; 

    for (int i = 2; i < x; i++) { 

        if (x % i == 0) 

            return false; 

    } 

    return true; 
} 

  
// Prints first n Pernicious numbers 

void printPernicious(int n) 
{ 

    for (int i=1,count=0; count<n; i++) { 

  

        // "__builtin_popcount(i)" count no 

        // of ones in binary representation 

        if (isPrime(__builtin_popcount(i))) { 

            printf("%d ", i); 

              

            count++; 

        } 

    } 
}