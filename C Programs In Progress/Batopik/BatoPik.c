#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int c, ch, ai, md;
	srand(time(NULL));
	printf("What mode do you want to play?\n1)2Player\n2)AI\n");
	scanf("%d", &md);

printf("\n1)Rock\n2)Paper\n3)Scissors");
	printf("\n\nEnter number corresponding to your choice:\n");
	scanf("%d", &ch);
	system("cls");

	if (md==1){
		printf("\nEnter number\n");
		scanf("%d", &ai);
	}
	else{
	ai = rand()%4;
	//printf("AI: %d", ai);
	}

	if (ch==1){
		printf("\nYou chose rock");
		if (ai==ch){
			printf("\nAI chose rock, its a draw");
		}
		else if (ai==2){
			printf("\nAI chose paper, you lose.");
		}
		else if (ai==3){
			printf("\nAI chose scissors, you win.");
		}
	}

	else if (ch==2){
		printf("\nYou chose paper");
		if (ai==ch){
			printf("\nAI chose paper, its a draw");
		}
		else if (ai==1){
			printf("\nAI chose rock, you win.");
		}
		else if (ai==3){
			printf("\nAI chose scissors, you lose.");
		}
	}

	else if (ch==3){
		printf("\nYou chose scissors");
		if (ai==ch){
			printf("\nAI chose scissors, its a draw");
		}
		else if (ai==1){
			printf("\nAI chose rock, you lose.");
		}
		else if (ai==2){
			printf("\nAI chose paper, you win.");
		}
	}
	else{
		printf("\nInvalid choice");
	}

	if (ai==0)
	printf("\nAI made an oopsie, no one won");

	printf("\n\n\n\n1)Yes\n2)No\nDo you wish to play again?(Enter corresponding number)");
	scanf("%d", &c);
	if (c==1){
		system("cls");
		main();
	}
	else
	return 0;
}
