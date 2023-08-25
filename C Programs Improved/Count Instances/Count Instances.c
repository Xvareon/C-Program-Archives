/**C Program that prints numbers based on how many instances it repeated**/

#include <stdio.h>
#define SIZE 5

void count(int locate);

int main(){
    int c;
	printf("Enter number of instances you want to locate: ");
	scanf(" %d",&c);
	count(c);
    printf("\n\n");
	return 0;
}

void count(int locate){
    int i,j,count=0,add=0;
	int n[SIZE];
	int m[SIZE];

	for(i=0;i<SIZE;i++){
		printf("[%d]Enter number: ",(i+1));
		scanf(" %d",&n[i]);
	}printf("\n");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(n[i]==n[j])
                count++;
		}
		if(count==locate){
            add++;
            m[add]=n[i];
		}
		count=0;
	}
	printf("\nThe number%s that repeated %d time%s %s: ",(add!=1)?"s":"",locate,(locate!=1)?"s":"",(add!=1)?"are":"is");
	for(i=1;i<=add;i++){
        printf("%d ",m[i]);
	}
}
