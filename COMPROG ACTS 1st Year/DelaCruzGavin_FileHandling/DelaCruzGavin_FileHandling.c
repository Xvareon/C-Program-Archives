#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAXs 100 //MAX STUDENTS
#define MAXq 10 //MAX QUIZZES
#define MAXc 30 //MAX CHARACTERS

///GLOBAL VARIABLES
int NoS=0,NoQ=0,sum=0,last;
char Name[MAXs][MAXc];
int Quiz[MAXs][MAXq];
float Ave[MAXs];

///FUNCTIONS
void record();
float ave(int a,int b);
void disp();
int menu();
void makeempty();
int isempty();
int isfull();
void download();
void upload();
void del();
void reset();
void gotoxy(int x,int y);

///DRIVER FUNCTION
int main(){
    makeempty();
    download();
    if(strcmp(Name[0],"")==0){
        makeempty();
    }
    system("cls");

    if(NoQ==0 || NoS==0){
        gotoxy(4,20);printf("Enter the number of students: ");scanf("%d",&NoS);
        gotoxy(8,20);printf("Enter the number of quizzes: ");scanf("%d",&NoQ);
    }

    while(1){
        switch(menu()){
            case 1: system("cls");record();getch();break;
            case 2: system("cls");del();getch();break;
            case 3: system("cls");disp();getch();break;
            case 4: system("cls");upload();exit(0);break;
            case 5: system("cls");reset();break;
            default: gotoxy(20,20);printf("Invalid Input!");getch();break;
        }
    }
}

///TRASH VALUE DISPOSER
void makeempty(){
    last=-1;
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
    gotoxy(12,10);printf("[5] Reset all data");

    gotoxy(14,10);printf("Enter your choice [1-5]: ");scanf("%d",&op);

    return(op);
}

///INSERT FUNCTION
void record(){

    int i;
    system("cls");
    if(isfull()){
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

///DELETE FUNCTION
void del(){
    int i,j,del;
    if(isempty()){
        gotoxy(10,30);printf("Empty File.");
    }
    else{
        disp();
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
            disp();
        }
    }
}

///DISPLAY FUNCTION
void disp(){

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
int isfull(){
    return(last==NoS-1);
}

///RESET FUNCTION
void reset(){
    strcpy(Name[0],"");
    makeempty();
    NoQ=0;NoS=0;
    upload();main();
}

///GOTOXY FUNCTION
void gotoxy(int x,int y){
	printf("\e[%d;%df",x,y);
}

///UPLOAD FUNCTION
void upload(){
    int i,j;
    FILE *fp;
    fp=fopen("DelaCruzGavin_FileHandling.txt","w+");

    for(i=0;i<=last;i++){
        fprintf(fp,"%d\n",NoQ);
        fprintf(fp,"%d\n",NoS);
        fprintf(fp,"%s\n",Name[i]);
        for(j=0;j<NoQ;j++)
        fprintf(fp,"%d\n",Quiz[i][j]);
        fprintf(fp,"%.2f\n",Ave[i]);
    }
    fclose(fp);
}

///DOWNLOAD FUNCTION
void download(){
    int i;
    FILE *fp;
    fp=fopen("DelaCruzGavin_FileHandling.txt","r+");
    if (fp==NULL){
        upload();main();
    }

    while(!feof(fp)){
        last++;
        fscanf(fp,"%d\n",&NoQ);
        fscanf(fp,"%d\n",&NoS);
        fscanf(fp," %[^\n]\n",Name[last]);
        for(i=0;i<NoQ;i++)
        fscanf(fp,"%d\n",&Quiz[last][i]);
        fscanf(fp,"%f\n",&Ave[last]);
    }
    fclose(fp);
}

