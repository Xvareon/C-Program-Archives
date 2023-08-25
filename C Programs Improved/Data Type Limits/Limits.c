/**C Program that prints the data type limits**/

#include<limits.h>
#include<stdio.h>

int main(){
    printf("int max :%d\n",INT_MAX);
    printf("long long int max : %lld\n",LLONG_MAX);
    printf("unsigned long long max : %llu\n",ULLONG_MAX);
    printf("long long min : %lld\n",LLONG_MIN);
    printf("char max: %llu\n",CHAR_MAX);
    printf("char min: %llu\n",CHAR_MIN);
}
