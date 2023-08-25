#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//global variable declarations
int diff, smallestdiff;
int limit, test1, test2;

//function prototypes
void swap(int *x, int *y);
void permute(int *arr, int st, int even, int odd, int size);

//driver code
int main(){
    int i, j, hold, size, even, odd;
    
    //Get main array size
    printf("Smallest Difference Program\n\nEnter array size: ");
    scanf("%d", &size);
    int arr[size];
    
    //Get main array elements
    for (i=0; i<size; i++){
    	printf("Index[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    //Sort elements
    for (i=0; i<size-1; i++)
   {
   	for (j=i+1; j<size; j++)
   	{
   		if (arr[i] > arr[j]) 
   		{
               hold = arr[i];
               arr[i] = arr[j];                 
               arr[j] = hold;               
           }
   	}
   }
   
   //Display elements
    printf("\nInput: ");
    for (i=0; i<size; i++){
    	printf("%d ", arr[i]);
    }
    
    //Split the main array into two
    if (size%2==0){
        even = size/2;
        odd = size/2;
    } 
    else {
        even = size/2;
        odd = size-even;
    }
    
    //Display, split, check, result
    permute(arr,0,even,odd,size);
    printf("\n\nSplit: %d , %d", even, odd);
    printf("\nFormed: %d - %d\n", test1, test2);
    printf("\nOutput: %d", smallestdiff);
    
    return 0;
}

//swap function
void swap(int *x, int *y){
	//Swaps two elements within array
      int temp;
      temp = *x;
      *x = *y;
      *y = temp;
} 

//permute function
void permute(int *arr, int st, int even, int odd, int size){ 

    int i, firsthalf=0, secondhalf=0, res; 
    
    //Multiplier for number positioning
    int n[5]={1,10,100,1000,10000};
    
    if (st==size){
    	
    	//Element permute/swap for sub array 1
        for (i=0; i<odd; i++){
            firsthalf+=arr[i]*n[odd-1-i];
        }
        
        //Element permute/swap for sub array 2
        for (i=0; i<even; i++){      secondhalf+=arr[i+(size%2!=0?even+1:even)]*n[even-1-i];
        }
        
        //Size 2 comparator
         if (size==2){
            res=abs(firsthalf-secondhalf);
            diff=res;
            if (limit==0){
                smallestdiff=diff;
                test1=firsthalf; 
                test2=secondhalf;
            }
         }
         //Size 3 comparator
         else if (size==3){
            if (arr[0]==0){
           res=abs((firsthalf*10)-secondhalf);
           diff=res;
            	if (limit==0){
                smallestdiff=diff;
                test1=firsthalf;
                test2=secondhalf;
            }
           }
            else{
            res=abs(firsthalf-secondhalf);
            diff=res;
            if (limit==0){
                smallestdiff=diff;
                test1=firsthalf;
                test2=secondhalf;
            }
            if (diff<smallestdiff){
                smallestdiff=diff;
                test1=secondhalf; 
                test2=firsthalf;
            } limit++;
           }
         }
         //Size 4 & above comparator
        else if (firsthalf>n[odd-1] && secondhalf>n[even-1]){
            /*for(int j=0; j<size; j++){
                printf("%d ",arr[j]);
            } printf("%d-%d",firsthalf,secondhalf);*/
            res=abs(firsthalf-secondhalf);
            diff=res;
            if (limit==0){
                smallestdiff=diff;
                test1=firsthalf; 
                test2=secondhalf;
            }
            if (diff<smallestdiff){
                smallestdiff=diff;
                test1=secondhalf; 
                test2=firsthalf;
            }
            limit++;
        }
    }
    
    else {//Permutation swapping
        for (i=st; i<size; i++){ 
            swap(arr+st,arr+i);
            permute(arr,st+1,even,odd,size);
            swap(arr+st,arr+i);
            }
        /*for (i=st+odd+1; i<size; i++){ 
            swap(arr+st,arr+i);
            permute(arr,st+odd,even,odd,size);
            swap(arr+st,arr+i);
            }*/
    }
}