#include <stdio.h>
int *push(int *arr,int size){
	int x;
	for(x = 0; x <= size; x++){
		if(arr[x] == 0){
			int y;
			for(y = x+1; y <= size; y++){
				if(arr[y]!= 0){
					arr[x] = arr[y];
					arr[y] = 0;
					break;
				}
			}
		}
	}
	return arr;
}
int main()
{
    int number, smallest, y;
    printf("Enter the number\n");
    scanf("%d",&number);
    if(number > 0){
        int arr[number];
        int x;
        for(x=0; x <= number; x++){ //fills array with values until x = user given input (e.g number=10, so 1,2,3..,10)
		arr[x] = x; //x is incrementing in loop
        }
        for(x=0; x <= number; x++){ //replaces all even numbers with the value "0"
            if(arr[x] % 2 == 0){ //if the value in array %2 is = to 0
                arr[x] = 0; //then
            }
        }
        push(arr,number);
        y=1;
        while(arr[y] != 0){
            smallest = arr[y];
            if(arr[y] != 0){
                for(x = arr[y]-1;x<= number;x+=smallest){
                    arr[x] = 0;
                }
                push(arr,number);//calls push function
            }
            y++;
        }
        printf("Output : ");
        x=0;
        while(arr[x] != 0){// filters out the zeores in final output
            printf("%d\t",arr[x]);
            x++;
        }
	}
	else{
		printf("input positive numbers only!");
	}
}
