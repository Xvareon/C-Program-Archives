#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAXs 100 //MAX STUDENTS
#define MAXq 10 //MAX QUIZZES
#define MAXc 30 //MAX CHARACTERS

///FUNCTIONS
void record(int NoQ,int NoS);
float ave(int a,int b);
void disp(int NoQ);
int menu();
int isempty();
int isfull(int NoS);
void del(int NoQ);
void gotoxy(int x,int y);
char Name[MAXs][MAXc];
int Quiz[MAXs][MAXq];
float Ave[MAXs];
int last=-1;

///DRIVER FUNCTION
int main(){
    int NoS,NoQ,last=-1;
    system("cls");

    gotoxy(4,20);printf("Enter the number of students: ");scanf("%d",&NoS);
    gotoxy(8,20);printf("Enter the number of quizzes: ");scanf("%d",&NoQ);

    while(1){
        switch(menu()){
            case 1: system("cls");record(NoQ,NoS);getch();break;
            case 2: system("cls");del(NoQ);getch();break;
            case 3: system("cls");disp(NoQ);getch();break;
            case 4: system("cls");exit(0);break;
            default: gotoxy(20,20);printf("Invalid Input!");getch();break;
        }
    }
}

///MAIN MENU
int menu(){
    int op;

    system("cls");
    gotoxy(2,20);printf("MENU");
    gotoxy(4,10);printf("[1] Insert the data of a Student");
    gotoxy(6,10);printf("[2] Delete the data of a Student");
    gotoxy(8,10);printf("[3] Display the data of the Students");
    gotoxy(10,10);printf("[4] Save and Exit");

    gotoxy(14,10);printf("Enter your choice [1-4]: ");scanf("%d",&op);

    return(op);
}

///INSERT MENU
void record(int NoQ,int NoS){

    int sum=0;
    int i;

    system("cls");
    if(isfull(NoS)){
        gotoxy(10,30);printf("RECORD FULL!");
    }
    else{
        last++;
        gotoxy(4,20);printf("Input the name of the student: ");scanf(" %[^\n]",Name[last]);
        for(i=0;i<NoQ;i++){
            gotoxy(8+(i*2),20);printf("Input the score in Quiz %d : ",i+1);scanf("%d",&Quiz[last][i]);
            sum+=Quiz[last][i];
        }
        Ave[last] = ave(sum,NoQ);
        sum=0;
    }
}

///DELETE MENU
void del(int NoQ){
    int i,j,del;
    if(isempty()){
        gotoxy(10,30);printf("Empty File.");
    }
    else{
        disp(NoQ);
        printf("\n\nEnter the row number you want to delete: \t");scanf("%d",&del);
        del-=1;

        if(del>last||del<0){
            printf("\n\t\tINVALID SELECTION!");
        }
        else{
            for(i=del;i<last;i++){
                strcpy(Name[i],Name[i+1]);
                for(j=0;j<NoQ;j++)
                    Quiz[i][j]=Quiz[i+1][j];
                Ave[i]=Ave[i+1];
            }
            last--;
            system("cls");
            disp(NoQ);
        }
    }
}

///DISPLAY MENU
void disp(int NoQ){

    int i,j;
    gotoxy(2,4);printf("Student Name");
    for(i=0;i<NoQ;i++){
        gotoxy(2,30+(i*10));printf("Quiz %d",i+1);
    }
    printf("\t\tAverage");
    printf("\t\tRemarks");

    for(i=0;i<=last;i++){
        gotoxy(4+(i*2),2);printf("[%d] %s",i+1,Name[i]);
        for(j=0;j<NoQ;j++){
            gotoxy(4+(i*2),30+(j*10));printf("%d",Quiz[i][j]);
        }
        printf("\t\t%.2f",Ave[i]);
        if(Ave[i]>=75.0){
            printf("\t\tPassed");
        }
        else{
            printf("\t\tFailed");
        }
    }
}

///AVERAGE FUNCTION
float ave(int a,int b){
    return ((float)a/b);
}

///SIZE LIMITS
int isempty(){
    return(last==-1);
}
int isfull(int NoS){
    return(last==NoS-1);
}

///GOTOXY FUNCTION
void gotoxy(int x,int y){
	printf("\e[%d;%df",x,y);
}

