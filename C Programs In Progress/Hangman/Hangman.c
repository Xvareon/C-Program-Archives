#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void display_Hangman(int);
void missed_Letters(char [], int);

int main() {

	srand(time(NULL));
	char answer[5] = "yes";

// loop game
while (strcmp(answer, "yes") == 0){	
	system("cls");

	char mysteryWords[][16] = {"break", "cat", "manager", "support", "wonder", "pot", "single", "turtle", "note", "mission"};

	int lives = 6, correct = 0, correctCtr = 0, missed = 0, i = 0, reguessed = 0;
	
	int randIdx = rand() % 10;

	int length = strlen(mysteryWords[randIdx]);

	char missedDisplay[6] = {'\0'};
	
	int letterDisplay[8] = { 0,0,0,0,0,0,0,0 };	

	char guess[16], userGuessed;

	// loop while alive	
	while ( correct < length ) {
	
	// upadte game display
	display_Hangman(lives);
		printf("Missed letters: ");
	
	// update missed letters	
		if (lives < 6)
		missed_Letters(missedDisplay, missed);
		printf("\n");
		
	// display number of letters
		printf("Mystery word: ");
		for( i = 0; i < length; i++) {
		
			if(letterDisplay[i] == 1) {
				printf("%c",mysteryWords[randIdx][i]);				
			} else {
				printf("-");
			}
		}	
		
		printf("\n");
		
	// ask for another key when already entered
	again:

		printf("Guess a letter.\n");
		fgets(guess, 16, stdin);
		
		userGuessed = guess[0];
		reguessed = 0; 
		
		correctCtr = correct;
	
	// check if key is already entered
		for( i = 0; i < length; i++) {
		
			if(letterDisplay[i] == 1) {
				if(mysteryWords[randIdx][i] == userGuessed) {
					reguessed = 1; 
					break;
				} 
				continue;
			}
		
	// check if key is wrong	
			if(letterDisplay[i] == 0) {
				if(missedDisplay[i] == userGuessed) {
					reguessed = 1; 
					break;
				} 
			}
	
	// check is key is right
			if(userGuessed == mysteryWords[randIdx][i] ) {
				letterDisplay[i] = 1;
				correct++;				
			} 
		}	
	
	//update game status
		if( correctCtr == correct && reguessed == 0) {
			lives--;
				missed++;
				missedDisplay[missed-1] = guess[0];
			if (lives == 0) {
				display_Hangman(lives);
				break;
			}
		} else if(reguessed == 1) {
			printf("\nYou have already guessed that letter. Choose again.\n");
			goto again;
		}
	
	} // end while loop

	// display game result
	if (lives == 0) {
		printf("\nSorry you lose, the word is: %s\n",
		mysteryWords[randIdx]);	
	} else  {	
		printf("\nYes! The secret word is \"%s\" You have won!\n",mysteryWords[randIdx]);
	} 
	
	// ask user for anouther round
	printf("Do you want to play again? (yes or no)\n");
	gets(answer);
	
	} 
	
	return 0;
}

void display_Hangman(int choice){
     switch(choice)
     {

     case 0:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   O\n");
	printf("   |  /|\\\n");	
	printf("   |\\ / \\\n");	
	printf("   ===\n");	
	break;
     case 1:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   O\n");
	printf("   |  /|\\\n");	
	printf("   |\\ /\n");	
	printf("   ===\n");	
	break;
     case 2:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   O\n");
	printf("   |  /|\\\n");	
	printf("   |\\\n");	
	printf("   ===\n");	
	break;
     case 3:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   O\n");
	printf("   |  /|\n");	
	printf("   |\\\n");	
	printf("   ===\n");	
	break;
     case 4:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   O\n");
	printf("   |   |\n");	
	printf("   |\\\n");	
	printf("   ===\n");		
	break;
     case 5:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   O\n");
	printf("   |\n");	
	printf("   |\\\n");	
	printf("   ===\n");		
	break;
     case 6:
         system("cls");
	printf("H A N G M A N\n");
	printf("   +---+\n");
	printf("   |   \n");
	printf("   |\n");	
	printf("   |\\\n");	
	printf("   ===\n");		
	break;
      } //end of switch-case
      return;
 }

void missed_Letters(char missed[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%c ", missed[i]);
}

