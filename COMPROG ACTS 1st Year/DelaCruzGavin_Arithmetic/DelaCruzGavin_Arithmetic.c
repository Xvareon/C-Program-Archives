#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define Maxu 12 //MAX USERS
#define Maxc 40 //MAX CHARACTERS
#define MAXq 5 //MAX QUESTIONS

///GLOBAL VARIABLES
char U[Maxu][Maxc],P[Maxu][Maxc];
float TacArr[Maxu],QcArr[Maxu],OPArr[Maxu];
float ScArr[Maxu][4];
int d,last,flag;
char currentuser[Maxc],currentpassword[Maxc];
float Tac=0,Qcounter=0,OPcounter=0;

///FUNCTIONS
void gotoxy(int x,int y);
int menu();
int menu2();
void operation();
void board(float b,float c);
void login();
void leaderboard();
void instructions();
void makempty();
void upload();
void download();
int checkfull();
int locateu();
int locatep(int x);
void del(int x);
void clean();

///DRIVER FUNCTION
int main(){
    int i;
    system("cls");
    makempty();
    download();
    gotoxy(0,50);printf("debug last:%d\n Press any key to continue",last);
    getch();
    clean();
    login();
    srand(time(NULL));

    while(1){
        switch(menu()){
        case 1 : system("cls");operation();getch();break;//addition
        case 2 : system("cls");operation();getch();break;//subtraction
        case 3 : system("cls");operation();getch();break;//multiplication
        case 4 : system("cls");operation();getch();break;//division
        case 5 : system("cls");leaderboard();getch();break;
        case 6 : system("cls");clean();upload();getch();login();break;
        default: gotoxy(25,30);printf("INVALID INPUT");getch();break;
        }
    }
}

///SIGN-IN INTERFACE
void login(){
    int i,z,p,pin=4;
    Tac=0,Qcounter=0,OPcounter=0;
    system("cls");
    if(checkfull()){
        gotoxy(15,50);printf("[ MEMORY FULL ]");
        gotoxy(17,49);printf("%cTHE WEAK PERISH%c",'"','"');
        gotoxy(20,25);printf("[ Deleting Rank %d's Data, Press any key to continue, EXIT to Cancel ]",Maxu);
        getch();
        gotoxy(25,45);printf("[ Successfully Deleted ]");
        last--;
        getch();
        system("cls");
        login();
    }
    else{
    gotoxy(2,30);printf("Input number corresponding to your choice (1-6): ");
        switch(menu2()){
            case 1:gotoxy(18,30);printf("Enter Name: ");scanf(" %[^\n]",currentuser);z=locateu();
            gotoxy(20,30);printf("Enter Password: ");scanf(" %[^\n]",currentpassword);p=locatep(z);
            if((z<0)||(p<0)){
                gotoxy(22,30);printf("Invalid Credentials!");
                getch();
                system("cls");
                login();
            }
            else{
                gotoxy(22,30);printf("There is a user!");
                flag=z;
                OPcounter=OPArr[flag];Tac=TacArr[flag]*OPArr[flag];Qcounter=QcArr[flag];
                getch();
            }break;
            case 2:gotoxy(18,30);printf("Enter New Name: ");scanf(" %[^\n]",currentuser);z=locateu();
            if(z>=0){
                gotoxy(20,30);printf("Sorry, this name is already taken");
                getch();
                system("cls");
                login();
            }
            else{
                gotoxy(20,30);printf("Enter Your Password: ");scanf(" %[^\n]",currentpassword);
                system("cls");
                last++;
                flag=last;
                for(i=0;i<4;i++){
                    ScArr[flag][i]=0;
                }
                for (i=0;i<Maxc;i++){
                    U[flag][i]=currentuser[i];
                    P[flag][i]=currentpassword[i];
                }
            }break;
            case 3:system("cls");instructions();getch();system("cls");login();break;
            case 4:system("cls");leaderboard();getch();system("cls");login();break;
            case 5:gotoxy(18,30);printf("Enter Dev Pin: ");scanf("%d",&pin);
                if(pin==8700){
                    gotoxy(20,30);printf("Reset Confirmed");makempty();clean();upload();getch();system("cls");login();
                }
                else{
                    gotoxy(20,30);printf("Access Denied!");getch();system("cls");login();
                }break;
            case 6:gotoxy(18,30);printf("Exit");getch();system("cls");exit(0);break;
            default:gotoxy(18,30);printf("Invalid Input!");getch();system("cls");login();break;
        }
    }
}

///GAME MENU
int menu(){
    int op;

    system("cls");
    gotoxy(4,50);printf("User:");
    gotoxy(4,57);printf("%s",currentuser);
    gotoxy(6,50);printf("Questions:");
    gotoxy(6,62);printf("%.0f",Qcounter);
    gotoxy(8,50);printf("Score:");
    gotoxy(8,57);printf("%.2f%%",TacArr[flag]);
        gotoxy(4,10);printf("GAME MENU");
        gotoxy(6,10);printf("[1] Addition");
        gotoxy(7,10);printf("[2] Subtraction");
        gotoxy(8,10);printf("[3] Multiplication");
        gotoxy(9,10);printf("[4] Division");
        gotoxy(10,10);printf("[5] Current Rank");
        gotoxy(11,10);printf("[6] Logout, Save and Return to menu");
        gotoxy(13,10);printf("Select(1-6)");
    scanf("%d",&op);
    d=op;
    return(op);
}

///MAIN MENU
int menu2(){
    int ch;
    gotoxy(4,30);printf("[1] Load Save File");
    gotoxy(6,30);printf("[2] New Game");
    gotoxy(8,30);printf("[3] Instructions(Must Read!!!)");
    gotoxy(10,30);printf("[4] Leaderboards");
    gotoxy(12,30);printf("[5] Reset");
    gotoxy(14,30);printf("[6] Exit");
    gotoxy(2,80);scanf("%d",&ch);
    return(ch);
}

///INSTRUCT FUNCTION
void instructions(){
    gotoxy(8,17);printf("Instructions:");
    gotoxy(10,17);printf("- Just get the correct answer to score POINTS.");
    gotoxy(12,17);printf("- For Division, the answer is always a WHOLE NUMBER that is the closest to the exact quotient.");
    gotoxy(14,17);printf("- Don't forget to LOGOUT AND SAVE before you return to the main menu or the progress won't be saved.");
    gotoxy(16,17);printf("- If the number of questions you have stays zero, your account will be automatically DELETED.");
    gotoxy(18,17);printf("- So play ATLEAST a round for your account to be saved.");
    gotoxy(20,17);printf("- Also, rankings are determined by your number of QUESTIONS first, then SCORES.");
    gotoxy(22,17);printf("- Rank 12's data will be automatically deleted if a new player enters, so be sure to stay on TOP!");
    gotoxy(24,17);printf("- Most importantly, have FUN! Goodluck player!");
}

///GOTOXY FUNCTION
void gotoxy(int x,int y){
	printf("\e[%d;%df",x,y);
}

///OPERATION DETERMINER
void operation(){

    int i,a,b,c,ans;
    float ac,sc=0,tr=0;
    char sign;

    for (i=0; i<MAXq; i++){
        a=rand()%100;
        b=rand()%100;

        switch(d){
        case 1:printf("Addition");sign='+';ans=a+b;break;
        case 2:printf("Subtraction");sign='-';ans=a-b;break;
        case 3:printf("Multiplication");sign='*';ans=a*b;break;
        case 4:printf("Division");while(b==0){b=rand()%100;}while(a<b){a=rand()%100;}sign='/';ans=a/b;break;
        default:system("cls");main();break;
        }
        board(sc,tr);

        gotoxy(4,10);printf("[%d] What is %d %c %d? ",i+1,a,sign,b);
		scanf("%d",&c);
		if (c==ans){
			gotoxy(6,10);printf("Correct!");
			if (i==MAXq-1){
                gotoxy(8,10);printf("Press any key to return to menu");
			}
			else{
                gotoxy(8,10);printf("Press any key to proceed to question %d",i+2);
                getch();
                system("cls");
			}
			sc++;
			//
			switch(d){
                case 1:ScArr[flag][d-1]++;break;
                case 2:ScArr[flag][d-1]++;break;
                case 3:ScArr[flag][d-1]++;break;
                case 4:ScArr[flag][d-1]++;break;
                default:system("cls");main();break;
            }
		}
		else{
			gotoxy(6,10);printf("Wrong! The correct answer is %d",ans);
			if (i==MAXq-1){
                gotoxy(8,10);printf("Press any key to return to menu");
			}
			else{
                gotoxy(8,10);printf("Press any key to proceed to question %d",i+2);
                getch();
                system("cls");
			}
		}
		tr++;
		Qcounter++;
		ac=(sc/tr)*100;
    }
        Tac+=ac;
        OPcounter++;
        gotoxy(14,10);printf("debug roundcounter:%.2f",OPcounter);
        board(sc,tr);
        TacArr[flag]=(Tac/OPcounter);
        QcArr[flag]=Qcounter;
        OPArr[flag]=OPcounter;
}

///SCORE INTERFACE
void board(float b,float c){
        float a=0;
        a=(b/c)*100;
        gotoxy(14,60);printf("debug TotalAc: %.2f",Tac);
        gotoxy(2,60);printf("Score: %.0f",b);
        gotoxy(4,60);printf("Tries: %.0f",c);
        gotoxy(6,60);printf("Accuracy: %.2f%c",a,'%');
}

///SCORE DISPLAY AND BUBBLE SORT
void leaderboard(){
    int i,j,k,temp,hold,temp1;
    char swap[Maxc],swap1[Maxc];
    //sort
    for(i=0;i<last;i++){
        for(j=i+1;j<=last;j++){
            if(TacArr[i]<TacArr[j]){
                temp=QcArr[i];QcArr[i]=QcArr[j];QcArr[j]=temp;
                hold=TacArr[i];TacArr[i]=TacArr[j];TacArr[j]=hold;
                temp1=OPArr[i];OPArr[i]=OPArr[j];OPArr[j]=temp1;
                for(k=0;k<4;k++){
                    temp=ScArr[i][k];ScArr[i][k]=ScArr[j][k];ScArr[j][k]=temp;
                }
                strcpy(swap,U[i]);strcpy(U[i],U[j]);strcpy(U[j],swap);
                strcpy(swap1,P[i]);strcpy(P[i],P[j]);strcpy(P[j],swap1);
            }
            if(QcArr[i]<QcArr[j]){
                temp=QcArr[i];QcArr[i]=QcArr[j];QcArr[j]=temp;
                hold=TacArr[i];TacArr[i]=TacArr[j];TacArr[j]=hold;
                temp1=OPArr[i];OPArr[i]=OPArr[j];OPArr[j]=temp1;
                for(k=0;k<4;k++){
                    temp=ScArr[i][k];ScArr[i][k]=ScArr[j][k];ScArr[j][k]=temp;
                }
                strcpy(swap,U[i]);strcpy(U[i],U[j]);strcpy(U[j],swap);
                strcpy(swap1,P[i]);strcpy(P[i],P[j]);strcpy(P[j],swap1);
            }
        }
    }
    gotoxy(4,10);printf("[User]");
    gotoxy(4,50);printf("[+]");
    gotoxy(4,60);printf("[-]");
    gotoxy(4,70);printf("[*]");
    gotoxy(4,80);printf("[/]");
    gotoxy(4,90);printf("[Questions]");
    gotoxy(4,110);printf("[Score]");
    for(i=0;i<=last;i++){
        gotoxy(i+8,10);printf("[%d] %s",i+1,U[i]);
        for(j=0;j<4;j++){
            gotoxy(i+8,50+(j*10));printf(" %.0f",ScArr[i][j]);
        }
        gotoxy(i+8,90);printf("%.0f",QcArr[i]);
        gotoxy(i+8,110);printf("%.2f%%",TacArr[i]);
    }
}

///RESET STATS FUNCTION
void makempty(){
    int i,j;
    for(i=0;i<Maxu;i++){
        TacArr[i]=0;QcArr[i]=0;OPArr[i]=0;
        for(j=0;j<4;j++){
            ScArr[i][j]=0;
        }
    }
    last=-1;
}

///USER LIMITER
int checkfull(){
   return(last==Maxu-1);
}

///LOCATE USER ACCOUNT USERNAME
int locateu(){
    int i;
    for (i=0;i<=last;i++){
        if (strcmp(currentuser,U[i])==0){
            return i;
        }
    }
    return -1;
}

///LOCATE USER ACCOUNT PASSWORD
int locatep(int x){
        if (strcmp(currentpassword,P[x])==0){
            return x;
        }
    return -1;
}

///DELETE LAST PLACE ACCOUNT IF FULL
void del(int x){
    int i,j;
    for(i=x;i<last;i++){
        for(j=0;j<Maxc;i++){
            U[i][j]=U[i+1][j];
            P[i][j]=P[i+1][j];
        }
        QcArr[i]=QcArr[i+1];
        TacArr[i]=TacArr[i+1];
        OPArr[i]=OPArr[i+1];
        for(j=0;j<4;j++){
            ScArr[i][j]=ScArr[i+1][j];
        }
    }
    last--;
}

///TRASH VALUE SWEEPER
void clean(){
    int i;
    for(i=0;i<=last;i++){
        if(QcArr[i]==0){
            del(i);
        }
    }
}

///UPLOAD FUNCTION
void upload(){
    gotoxy(10,50);printf("[ FILE SAVED ]");
    FILE *fp;
    int i,j;
    fp=fopen("DelaCruzGavin_Arithmetic.txt","w+");
    for(i=0;i<=last;i++){
        fprintf(fp, "%s\n",U[i]);
        fprintf(fp, "%.0f\n",QcArr[i]);
        for(j=0;j<4;j++){
            fprintf(fp, "%.0f\n",ScArr[i][j]);
        }
        fprintf(fp, "%.2f\n",TacArr[i]);
        fprintf(fp, "%.2f\n",OPArr[i]);
        fprintf(fp, "%s\n",P[i]);
    }
    fclose(fp);
}

///DOWNLOAD FUNCTION
void download(){
    FILE *fp;
    int i;
    fp=fopen("DelaCruzGavin_Arithmetic.txt","r+");
    if (fp==NULL){
        upload();main();
    }
    while(!feof(fp)){
        last++;
        fscanf(fp, " %[^\n]\n",U[last]);
        fscanf(fp, "%f\n",&QcArr[last]);
        for(i=0;i<4;i++){
            fscanf(fp, "%f\n",&ScArr[last][i]);
        }
        fscanf(fp, "%f\n",&TacArr[last]);
        fscanf(fp, "%f\n",&OPArr[last]);
        fscanf(fp, " %[^\n]\n",P[last]);
    }
    fclose(fp);
}
