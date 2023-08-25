#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#define Row 26
#define Col 81

///FUNCTIONS
void gotoxy(int x,int y);
void scoreboard(char Name[20],float Score,int Life,int NBomb,float Tries,float Accuracy);
void gamearea(char CellArray[Row][Col]);
void gamelimit(int d);

int main()
{
///VARIABLES
    char Name[30],Hit,CellArray[Row][Col],BombArr[Row][Col];
    int i,j,brow=0,bcol=0,irow=0,icol=0,life,nbomb,difficulty=0,restart=0;
    float score=0,tries=0,accuracy=0;
    srand(time(NULL));
    system("cls");

///INSTRUCTIONS
    gotoxy(0,50);printf("WELCOME TO MINESWEEPER!");
    gotoxy(3,10);printf("General Instructions: Find bombs by entering coordinates to score, life is depleted when you miss.");
    gotoxy(4,30);printf("The game ends when either your life or the no. of bombs reaches 0.");
    gotoxy(6,50);printf("Enter Player Name: ");
    scanf(" %[^\n]",&Name);
    gotoxy(8,40);printf("Choose Difficulty (Type corresponding number): ");
    gotoxy(10,10);printf("--->> 1 [Noob]: YOU choose the number of lives and bombs. (Pfft)");
    gotoxy(12,10);printf("Win Condition: Really Now?");
    gotoxy(14,10);printf("--->> 2 [Standard]: 13 Lives, 1000 bombs. (Feeling Lucky?)");
    gotoxy(16,10);printf("Win Condition: Get atleast 75%c accuracy at the end of the game.", '%');
    gotoxy(18,10);printf("--->> 3 [Survival]: 30 Lives, random number(1-2000) of bombs, You get a life each time you hit a bomb.");
    gotoxy(20,10);printf("Win Condition: Get atleast a score that is half the number of bombs.");
    gotoxy(22,10);printf("--->> 4 [Hellish]: 1 Life, 100 bombs. (Only try this if you are a Sage.)");
    gotoxy(24,10);printf("Win Condition: Get all the bombs. You won't win though.");
    gotoxy(26,10);printf("Enter Number: ");scanf("%d",&difficulty);

///DIFFICULTY
    if(difficulty==1){
        gotoxy(28,50);printf(">>Noob Difficulty Chosen<<");
        gotoxy(35,50);printf("Press Any Key to continue");
        getch();
        system("cls");
        gotoxy(20,45);printf("Don't dig your own grave please.");
        gotoxy(6,50);printf("Enter Number of Lives: ");scanf("%d",&life);
        gotoxy(7,50);printf("Enter Number of Bombs: ");scanf("%d",&nbomb);
    }
    else if(difficulty==2){
        life=13;
        nbomb=1000;
        gotoxy(28,50);printf(">>Standard Difficulty Chosen<<");
    }
    else if(difficulty==3){
        life=30;
        nbomb=rand()%2001;;
        gotoxy(28,50);printf(">>Survival Difficulty Chosen<<");
    }
    else if(difficulty==4){
        life=1;
        nbomb=100;
        gotoxy(28,50);printf(">>Hellish Difficulty Chosen<<");
    }
    else{
        gotoxy(28,30);printf("INVALID INPUT");
        main();
    }
    gotoxy(35,50);printf("Press Any Key to continue");
    getch();
    system("cls");

///HINT TABLE
    for(i=0;i<Row;i++){
        for(j=0;j<Col;j++){
            CellArray[i][j]=' ';
        }
    }
    gotoxy(2,90);printf("Hint Coordinates:");
    for(i=0; i<nbomb; i++){
        brow=rand()%Row;
        bcol=rand()%Col;
        gotoxy(3+i,90);printf("[%d](%d,%d)",i+1,brow,bcol);
        BombArr[brow][bcol]='*';
        CellArray[brow][bcol]='*';
    }
    gamearea(CellArray);
    gamelimit(difficulty);
    printf("\n\t\t\t\t\t\tPress Any Key to continue");
    getch();
    system("cls");

///MAIN GAME INTERFACE
    for(i=0;i<Row;i++){
        for(j=0;j<Col;j++){
            CellArray[i][j]=' ';
        }
    }
    while(life!=0 && nbomb!=0){
        system("cls");
        scoreboard(Name,score,life,nbomb,tries,accuracy);
        gamearea(CellArray);
        gamelimit(difficulty);
        gotoxy(9,90);printf("Enter Row(0-25): ");
        scanf("%d", &irow);
        gotoxy(11,90);printf("Enter Column(0-80): ");
        scanf("%d", &icol);
        tries++;
        Hit=BombArr[irow][icol];
        if(Hit=='*'){
            if(difficulty==3){
                life++;
            }
            gotoxy(13,90);printf(">>>JACKPOT!<<<");
            gotoxy(20,90);printf("Press any key to continue");
            CellArray[irow][icol]='*';
            gamearea(CellArray);
            gamelimit(difficulty);
            score++;
            nbomb--;
            accuracy=(score/tries)*100;
            scoreboard(Name,score,life,nbomb,tries,accuracy);
            BombArr[irow][icol]='.';
        }
        else if(Hit=='.'){
            gotoxy(13,90);printf(">Bomb already found.<");
            gotoxy(20,90);printf("Press any key to continue");
            accuracy=(score/tries)*100;
        }
        else if(Hit=='-'){
            gotoxy(13,90);printf(">Coordinate already entered.<");
            gotoxy(20,90);printf("Press any key to continue");
            accuracy=(score/tries)*100;
        }
        else{
            gotoxy(13,90);printf(">>Found NOTHING!<<");
            gotoxy(20,90);printf("Press any key to continue");
            CellArray[irow][icol]='x';
            gamearea(CellArray);
            gamelimit(difficulty);
            life--;
            accuracy=(score/tries)*100;
            scoreboard(Name,score,life,nbomb,tries,accuracy);
            BombArr[irow][icol]='-';
        }
        getch();
    }

///END GAME SCREEN
    system("cls");
    gotoxy(3,30);printf("GAME OVER! Your final statistics are: ");
    printf("\a");
    gotoxy(6,30);printf("User: %s", Name);
    if(difficulty==1){
        if(nbomb==0){
            gotoxy(5,30);printf("What? were you expecting something?");
        }
        else{
            gotoxy(5,30);printf("How could you even lose to your own rules???");
        }
        gotoxy(7,30);printf("Difficulty: Noob");
    }
    else if(difficulty==2){
        if(accuracy>=75){
            gotoxy(5,30);printf("YOU WIN! The end justifies the means ;) Congratulations!");
        }
        else{
            gotoxy(5,30);printf("YOU LOSE! Nice try, better luck next time!");
        }
        gotoxy(7,30);printf("Difficulty: Standard");
    }
    else if(difficulty==3){
        if(score>=(nbomb/2)){
            gotoxy(5,30);printf("Good memory, luck or cheat---it doesn't matter. Good job, you WON! Cherish it, it won't happen again!");
        }
        else{
            gotoxy(5,30);printf("YOU LOSE! How unfortunate :p.");
        }
        gotoxy(7,30);printf("Difficulty: Survival");
    }
    else if(difficulty==4){
        if(nbomb==0){
            gotoxy(5,30);printf("YOU WIN! Who says cheaters never win? Its still an effort!");
        }
        else{
            gotoxy(5,30);printf("YOU LOSE! You really thought you had a chance?");
        }
        gotoxy(7,30);printf("Difficulty: Hellish");
    }
    gotoxy(8,30);printf("Score: %.0f", score);
    gotoxy(9,30);printf("Tries: %.0f", tries);
    gotoxy(10,30);printf("Accuracy: %.2f%c", accuracy, '%');
    gotoxy(11,30);printf("Lives Left: %d", life);
    gotoxy(12,30);printf("Bombs Left: %d", nbomb);
    gotoxy(14,30);printf("Do you want to play again? (Type corresponding number)");
    gotoxy(15,30);printf("--->> 1 [Yes]");
    gotoxy(16,30);printf("--->> 2 [Nah, I suck at the game]");
    gotoxy(18,30);printf("Enter Number: ");scanf("%d", &restart);

    if(restart==1){
        gotoxy(19,30);printf("Restarting....Press any key to continue");
        getch();
        main();
    }
    else{
        gotoxy(19,30);printf("Press any key to continue");
        getch();
        system("cls");
        gotoxy(10,50);printf("THANK YOU FOR PLAYING!\n\n\n\n\n\n");
        return 0;
    }
}

///GOTOXY FUNCTION
void gotoxy(int x,int y){
    printf("\e[%d;%df",x,y);
}

///SCOREBOARD INTERFACE
void scoreboard(char Name[20],float Score,int Life,int NBomb,float Tries,float Accuracy){
    gotoxy(2,90);printf("User: %s", Name);
    gotoxy(3,90);printf("Score: %.0f", Score);
    if(Life==1){
        printf("\a");
        gotoxy(4,99);printf("<<--DANGER!!!!");
    }
    gotoxy(4,90);printf("Life: %d", Life);
    gotoxy(5,90);printf("Tries: %.0f", Tries);
    gotoxy(6,90);printf("Accuracy: %.2f%c", Accuracy, '%');
    gotoxy(7,90);printf("Bombs Left: %d", NBomb);
    gotoxy(15,90);printf("Legend:");
    gotoxy(16,90);printf("* = Hit");
    gotoxy(17,90);printf("x = Miss");
}

///GAME AREA INTERFACE
void gamearea(char CellArray[Row][Col]){
    int i, j;
    for(i=0;i<Row;i++){
        gotoxy(2+i,0);
        for(j=0;j<Col;j++){
            printf("%c", CellArray[i][j]);
        }
        printf("\n");
    }
 }

///GAME BORDERS
void gamelimit(int d){
    int i;
    if(d==1){
      gotoxy(0,90);printf("Difficulty: Noob");
    }
    if(d==2){
      gotoxy(0,90);printf("Difficulty: Standard");
    }
    if(d==3){
      gotoxy(0,90);printf("Difficulty: Survival");
    }
    if(d==4){
      gotoxy(0,90);printf("Difficulty: Hellish");
    }
    for(i=0; i<(Col+2); i++){
        gotoxy((Row+2), i);
        printf("_");
    }
    for(i=0; i<(Row+3); i++){
        gotoxy(i, (Col+2));
        printf("|");
    }
}
