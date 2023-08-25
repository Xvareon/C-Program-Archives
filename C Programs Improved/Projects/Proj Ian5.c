#include <stdio.h>
#include <stdlib.h>
int main() {
	int Round, Team, z, N, q, mark;
	printf("Input number of teams: ");
	scanf("%d", &N);
	for(Round = 0; Round <= N; Round++){ //if input is 0, will display "Round"; for loop regulates whole program
		if(Round == 0){ //always true; this if statement will print the first line- the labels
			printf("Round\t"); // will always print (technically the label)
			for(Team = 1; Team <= N; Team++){ // input N=0 will not display "Team" bc False: 1<=0, but will display when N<=1
				printf("Team %d\t", Team);// will always print when N>=1; first line, once condition is met, Team 1,2... stops printing
			}
			printf("\n");//next line (where numbers will be printed)
		}
		else{//will run once Round!=0
			printf("%d\t", Round);//prints per line, round increments until for cond is met
			q = (Round - 1) + N;
			mark = 1; //marker for intersection; hence, mark;; can be read under which team?
			for(z = q; z > q-N; z--){ // u is declaring da z with the value of q
				if(z > N){ // will start at round 2; if z is greater than user input; first half
					if(z-N == mark){//intersection (e.g  4==4)
						if(N%2 == 0){ //if input even, --
								printf("%d\t", z - (N/2));
                        }
						else{ //if input odd, print "bye"
						printf("bye\t");
						}
					}
					else{
					printf("%d\t", z-N); //prints the N for this team
					}
				}
				else{ //second half
					if(z == mark){//intersection
						if(N%2 == 0){//if even
								printf("%d\t", z - (N/2));
						}
						else{//if odd
						printf("bye\t");
						}
					}
					else{//z did not meet mark
					printf("%d\t", z);
					}
				}
				mark++;//increments after every team in one line/round
			}
			printf("\n");
		}
	}
}
