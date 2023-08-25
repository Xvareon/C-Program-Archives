/**C Program that displays the average values in an array without the greatest and least values**/

#include <stdio.h>
#define SIZE 5

void sort(int input[]);
void disp(int input[]);

int main(){
    int i,input[SIZE];

   //array
   for(i=0;i<SIZE;i++){
   	printf("Index[%d]: ",i);
   	scanf(" %d",&input[i]);
   }printf("\n");

    sort(input);
    disp(input);
    return 0;
}

void sort(int input[]){
    int i,j,hold;

    //sort
    for(i=0;i<SIZE-1;i++){
        for(j=i+1;j<SIZE;j++){
            if(input[i]>input[j]){
                hold=input[i];
                input[i]=input[j];
                input[j]=hold;
            }
        }
    }
}

void disp(int input[]){
    int i;
    float sum,ave;

    //display
    printf("Sorted array: ");
    for(i=0;i<SIZE;i++){
        printf("%d ",input[i]);
    }
    //display the array without smallest and greatest
    printf("\n\nWithout smallest and greatest: ");
    for(i=1;i<(SIZE-1);i++){
        sum+=input[i];
        printf("%d ",input[i]);
    }
    //return average value except for the smallest and greatest
    ave=sum/(SIZE-2);
    printf("\n\nSum: %.2f",sum);
    printf("\nAverage: %.2f",ave);
}
