#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
//#include <process.h>//

#define MAXa 100 //MAX DATABASE ACCOUNTS
#define MAXd 3000 //MAX DATE
#define MAXacn 16 //MAX ACCOUNT NUMBER
#define MAXp 7 //MAX PIN
#define MAXc 30 //MAX CHARACTERS

///GLOBAL VARIABLES
char TPin[MAXp];
int last=0,flag=0,c,xd=0;
int MaxDep=100000,MaxWid=20000,MB=500,HoldAmt;

///STRUCTURE VARIABLES
struct Acc{//Account Bundled Information
    int AccNo[MAXacn];
    char AccNa[MAXc];
    int Bal;
    char Pin[MAXp];
    int flagarr;
    char TrancDate[MAXd][MAXc];
    int TrancType[MAXd];
    int TrancAmt[MAXd];
};struct Acc acc[MAXa];

///MAIN FUNCTIONS
void clean();
int menu();
void enrollment();
void randacn();
void transaction();
int locate();
void tpin();
int trancmenu();
void deposit();
void withdraw();
void balance();
void setpin();
void pin();
void disp();
void ddate();
void rdate();
void receipt();
void wait();

///FILE HANDLING FUNCTIONS
void upload();
void download();
void uploadfd();
void downloadfd();
void insertcard();
void removecard();
void gotoxy();

///DESIGN FUNCTIONS
void design();
void transborder();
void moon();
void border();
void namedes();
void end();
void history();

///DRIVER FUNCTION
int main(){
    srand(time(NULL));
    last=0;
    flag=0;
    xd=0;
    download();
    clean();
    while(1){
        switch(menu()){
            case 1: system("cls");enrollment();uploadfd();upload();getch();break;
            case 2: system("cls");transaction();getch();break;
            case 3: system("cls");uploadfd();upload();exit(0);break;
            case 4: system("cls");disp();getch();break;
            default: gotoxy(16,20);printf("Invalid Input!");getch();system("cls");break;
        }
    }
}

///TRASH VALUE SWEEPER
void clean(){
    if(strcmp(acc[1].Pin,"")==0){
        last=0;
    }
}

///ATM HOME MENU
int menu(){
    system("cls");
    printf("\033[0m");
    border();design();
    printf("\033[0m");
    gotoxy(25,30);printf("[1] Enrollment");
    gotoxy(27,30);printf("[2] Transaction");
    gotoxy(25,70);printf("[3] Exit");
    gotoxy(27,70);printf("[4] Debug Accounts");
    gotoxy(29,45);printf("Enter your choice [1-4]: ");scanf("%d",&c);
    return (c);
}

///ACCOUNT CREATION FUNCTION
void enrollment(){
    border();
    gotoxy(25,20);printf("[ ENROLLMENT ]");
    insertcard();
    downloadfd();
    if(flag==0){
        printf("\033[0m");border();
        last++;gotoxy(8,30);flag=last;printf("Debug last,flag: %d,%d",last,flag);
        gotoxy(12,40);printf("Generated Account Number: ");gotoxy(12,70);randacn();
        gotoxy(14,40);printf("Enter Account Name: ");scanf(" %[^\n]",acc[flag].AccNa);
        acc[flag].Bal=500;//Starting balance. Subject to change due to ATM types
        gotoxy(19,14);printf("Starting and Maintaining Balance: PHP %d.00. For more details, consult the bank.",acc[flag].Bal);getch();
        setpin();
        acc[flag].flagarr=flag;
    }
    else{
        printf("\033[0m");border();
        gotoxy(8,30);printf("Debug last,flag: %d,%d",last,flag);
        gotoxy(14,50);printf("YOU ALREADY HAVE AN ACCOUNT!");
    }
}

///ACCOUNT NUMBER RANDOMIZER
void randacn(){
    int i;
    acc[flag].AccNo[0]=8;acc[flag].AccNo[1]=7;acc[flag].AccNo[2]=0;acc[flag].AccNo[3]=0;//'8700' IS THIS BANK'S SIGNATURE FIRST FOUR NUMBERS
    for(i=0;i<4;i++){
        printf("%d",acc[flag].AccNo[i]);
    }printf(" ");
    for(i=4;i<MAXacn;i++){
        acc[flag].AccNo[i]=rand()%10;
        if(i==7 || i==11 || i==15)
            printf("%d ",acc[flag].AccNo[i]);
        else
            printf("%d",acc[flag].AccNo[i]);
    }
}

///TRANSACTION MENU
void transaction(){
    int b;
    gotoxy(25,20);printf("[ TRANSACTION ]");
    insertcard();
    downloadfd();
    //b=1;
    b=locate();
    if(b==0){
        border();
        gotoxy(8,30);printf("Debug last,flag: %d,%d",last,flag);
        gotoxy(14,30);printf("THIS ACCOUNT IS NOT REGISTERED IN THIS BANK!");
        getch();system("cls");main();//
    }
    ree:
    gotoxy(2,20);border();design();
    printf("\033[0m");
    gotoxy(25,20);printf("[ TRANSACTION ]");gotoxy(27,50);printf("Enter 6-digit Pin: " );tpin();system("cls");
    if(strcmp(TPin,acc[flag].Pin)==0){
        re:
        gotoxy(2,50);printf("Debug Flag: %d",flag);
        switch(trancmenu()){
            case 1:system("cls");deposit();rdate();uploadfd();upload();getch();wait();receipt();system("cls");goto re;break;
            case 2:system("cls");withdraw();rdate();uploadfd();upload();getch();wait();receipt();system("cls");goto re;break;
            case 3:system("cls");balance();getch();system("cls");goto re;break;
            case 4:system("cls");setpin();HoldAmt=0;rdate();uploadfd();upload();getch();receipt();system("cls");goto re;break;
            case 5:system("cls");ddate();getch();system("cls");goto re;break;
            case 6:system("cls");uploadfd();upload();removecard();end();main();break;
            default:system("cls");transaction();break;
        }
    }
    else{
        border();
        gotoxy(14,40);printf("Pins do not match! Try again!");getch();system("cls");goto ree;
    }
}

///ACCOUNT VERIFIER
int locate(){
    int i;
    for(i=1;i<=last;i++){
        if(flag==acc[i].flagarr){
            return i;
        }
    }
    return 0;
}

///PIN MATCH CHECKER
void tpin(){
    char a;
    int d=0;
    if(flag==0){
        system("cls");
        gotoxy(20,26);printf("AUTHENTICATION ERROR!");
        getch();system("cls");
        transaction();
    }
    else{
        do{
        re:
            TPin[d]=getch();
            if(TPin[d]=='\b'){
                if(d<=0)
                d++;
                else
                    printf("\b \b");
                d--;
            }
            else if(isdigit(TPin[d])){
                printf("*");
                d++;
            }
        }while(d!=6);
        a=getch();
        if(a=='\b'){
            d=5;printf("\b \b");goto re;
        }
        TPin[d]='\0';
    }
}

///USER ACCOUNT MENU
int trancmenu(){
    transborder();
    printf("\033[0m");
    gotoxy(7,40);printf("[1] Deposit");
    gotoxy(14,40);printf("[2] Withdraw");
    gotoxy(21,40);printf("[3] Balance Inquiry");
    gotoxy(7,90);printf("[4] Change PIN");
    gotoxy(14,90);printf("[5] Transaction History");
    gotoxy(21,90);printf("[6] Exit");
    gotoxy(28,40);printf("Would you like another transaction? ");scanf("%d",&c);
    return (c);
}

///DEPOSIT FUNCTION
void deposit(){
    int dep;
    printf("\033[0;31m");
    moon();namedes();
    printf("\033[0;36m");
    gotoxy(25,45);printf("Current Balance: PHP %d.00",acc[flag].Bal);
    gotoxy(27,40);printf("Enter Amount you want to deposit: PHP ");scanf("%d",&dep);
    HoldAmt=dep;
    if(dep>MaxDep){
        gotoxy(29,20);printf("Maximum deposit is PHP %d.00! Please consult the bank for assistance.",MaxDep);getch();system("cls");deposit();
    }
    else{
        if(dep%20==0 || dep%50==0 || dep%100==70 || dep%100==90){
            acc[flag].Bal+=dep;
            gotoxy(25,45);printf("Current Balance: PHP %d.00",acc[flag].Bal);
        }
        else{
            system("cls");
            gotoxy(15,32);printf("You can only deposit 20, 50, 100, 200, 500 & 1000 peso bills");getch();system("cls");deposit();
        }
    }
}

///WITHDRAW FUNCTION
void withdraw(){
    int wid;
    printf("\033[0;34m");
    moon();namedes();
    printf("\033[0;36m");
    gotoxy(25,45);printf("Current Balance: PHP %d.00",acc[flag].Bal);
    gotoxy(27,40);printf("Enter Amount you want to withdraw: PHP ");scanf("%d",&wid);
    HoldAmt=wid;
    if(wid>acc[flag].Bal){
        gotoxy(29,40);printf("You don't have enough balance!");getch();system("cls");withdraw();
    }
    else if(wid>MaxWid){
        gotoxy(29,20);printf("Withdrawal limit per transaction is PHP %d.00. Please consult the bank for assistance.",MaxWid);getch();system("cls");withdraw();
    }
    else{
        if(wid%20==0 || wid%50==0 || wid%100==70 || wid%100==90){
            acc[flag].Bal-=wid;
            if(acc[flag].Bal<MB){
                acc[flag].Bal+=wid;
                gotoxy(29,14);printf("Your maintaining balance should not be below PHP %d.00. Please consult the bank for assistance.",MB);getch();system("cls");withdraw();
            }
            else{
                gotoxy(25,45);printf("Current Balance: PHP %d.00",acc[flag].Bal);
            }
        }
        else{
            system("cls");
            gotoxy(15,32);printf("You can only withdraw 20, 50, 100, 200, 500 & 1000 peso bills");getch();system("cls"); withdraw();
        }
    }
}

///BALANCE CHECKER
void balance(){
    printf("\033[0m");
    moon();namedes();
    printf("\033[0;36m");gotoxy(25,45);printf("Current Balance: PHP %d.00",acc[flag].Bal);
}

///SET PIN FUNCTION
void setpin(){
    system("cls");border();design();printf("\033[0m");
    gotoxy(25,30);printf("Enter 6-digit Pin: ");pin();
    gotoxy(27,30);printf("Confirm Pin: ");tpin();
    if(strcmp(acc[flag].Pin,TPin)==0){
        gotoxy(25,70);printf("Pin has been set");
    }
    else{
        gotoxy(25,70);printf("Pins do not match! Try again!");getch();setpin();
    }gotoxy(27,70);printf("debug: %s",acc[flag].Pin);

}

///RECORD PIN FUNCTION
void pin(){
    char a;
    int d=0;
    do{
        re:
        acc[flag].Pin[d]=getch();
        if(acc[flag].Pin[d]=='\b'){
            if(d<=0)
                d++;
            else
                printf("\b \b");
            d--;
        }
        else if(isdigit(acc[flag].Pin[d])){
            printf("*");
            d++;
        }
    }while(d!=6);
    a=getch();
    if(a=='\b'){
        d=5;printf("\b \b");goto re;
    }
    acc[flag].Pin[d]='\0';
}

///DISPLAY FUNCTION
void disp(){
    int i,j;
    printf("debug: %d\n",flag);
    gotoxy(2,2);printf("Account Name:");gotoxy(2,34);printf("Account Number:");gotoxy(2,71);printf("PIN:");gotoxy(2,87);printf("Balance:");
    for(i=1;i<=last;i++){
        gotoxy(2+(i*2),2);printf("[%d] %s",i,acc[i].AccNa);
        gotoxy(2+(i*2),34);
        for(j=0;j<MAXacn;j++){
            printf("%d",acc[i].AccNo[j]);
        }
        gotoxy(2+(i*2),71);printf("%s",acc[i].Pin);
        gotoxy(2+(i*2),87);printf("PHP %d.00",acc[i].Bal);
    }
}

///DISPLAY TRANSACTION HISTORY
void ddate(){
    int i;
    int x=17;
    history();
    printf("\033[0m");
    gotoxy(6,10);printf("Transaction History:\n\n");
    gotoxy(12,15);printf("TRANSACTION");
    gotoxy(12,57);printf("AMOUNT");
    gotoxy(12,94);printf("TIME AND DATE");
    for(i=1;i<=xd;i++){
        switch(acc[flag].TrancType[i]){
            case 1: gotoxy(x,15);printf("%d) Deposit",i);gotoxy(x,55); printf("PHP %d.00",acc[flag].TrancAmt[i]);break;
            case 2: gotoxy(x,15);printf("%d) Withdraw",i); gotoxy(x,55);printf("PHP %d.00",acc[flag].TrancAmt[i]);break;
            case 4: gotoxy(x,15);printf("%d) Change Pin",i);break;
            default: printf("%d) System under maintenance",i);break;
        }
       gotoxy(x,87); printf(" %s\n\n",acc[flag].TrancDate[i]);x+=2;
    }
}

///RECORD SYSTEM DATE AND TIME
void rdate(){
    time_t mytime;
    mytime = time(NULL);
    xd++;
    strcpy(acc[flag].TrancDate[xd],ctime(&mytime));
    acc[flag].TrancType[xd]=c;
    acc[flag].TrancAmt[xd]=HoldAmt;
}

///RECEIPT FUNCTION AND DISPLAY
void receipt(){
    FILE *fp;
        if(fopen("g:\\receipt.txt","w+")){
            fp=fopen("g:\\receipt.txt","w");
        }
        else if(fopen("f:\\receipt.txt","w+")){
            fp=fopen("f:\\receipt.txt","w");
        }
        else if(fopen("e:\\receipt.txt","w+")){
            fp=fopen("e:\\receipt.txt","w");
        }
        else if(fopen("d:\\receipt.txt","w+")){
            fp=fopen("d:\\receipt.txt","w");
        }
        else{
            fp=NULL;
        }

        fprintf(fp,"MOONEY BANK TRANSACTION RECORD\n");
        fprintf(fp,"LOCATION:                 PHILIPPINES\n");
        fprintf(fp,"DATE and TIME:            %s\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n\n",acc[flag].TrancDate[xd]);
        fprintf(fp,"TRANSACTION TYPE:             AMOUNT:\n");
        switch(acc[flag].TrancType[xd]){
            case 1: fprintf(fp,"DEPOSIT:                     PHP %d.00\n__________________________________________________________________",acc[flag].TrancAmt[xd]);break;
            case 2: fprintf(fp,"WITHDRAW:                    PHP %d.00\n__________________________________________________________________",acc[flag].TrancAmt[xd]);break;
            case 4: fprintf(fp,"CHANGE PIN\n__________________________________________________________________");break;
            default: fprintf(fp,"System under maintenance\n__________________________________________________________________");break;
        }

    system("cls");
    border();printf("\033[0m");
    gotoxy(8,43);printf("MOONEY BANK TRANSACTION RECORD");
    gotoxy(13,40);printf("LOCATION:                 PHILIPPINES");
    gotoxy(15,40);printf("DATE and TIME:            %s\n\n",acc[flag].TrancDate[xd]);
    gotoxy(17,40);printf("TRANSACTION TYPE:             AMOUNT:");
    switch(acc[flag].TrancType[xd]){
            case 1: gotoxy(19,40);printf("DEPOSIT:                     PHP %d.00 ",acc[flag].TrancAmt[xd]);break;
            case 2: gotoxy(19,40);printf("WITHDRAW:                    PHP %d.00 ",acc[flag].TrancAmt[xd]);break;
            case 4: gotoxy(19,40);printf("CHANGE PIN ");break;
            default: printf("System under maintenance");break;
    }
        gotoxy(22,40);printf("ENJOY THE CONVENIENCE OF 24/7 BANK.");getch();

    fclose(fp);
}

///SCREEN STALLER
void wait(){
    system("cls");
    border();printf("\033[0m");
    gotoxy(8,43);printf("Processing your transaction please wait...");
    Sleep(2500);
}

///UPLOAD FUNCTION
void upload(){
    int i,j;
    FILE *fp;
    fp=fopen("DelaCruzGavin_ProjectATM.txt","w+");

    for(i=1;i<=last;i++){
        fprintf(fp,"%d\n",acc[i].flagarr);
        fprintf(fp,"%s\n",acc[i].AccNa);
        fprintf(fp,"%d\n",acc[i].Bal);
        for(j=0;j<MAXacn;j++){
            fprintf(fp,"%d ",acc[i].AccNo[j]);
        }
        fprintf(fp,"\n%s\n",acc[i].Pin);
    }
    fclose(fp);
}

///DOWNLOAD FUNCTION
void download(){
    int i;
    FILE *fp;
    fp=fopen("DelaCruzGavin_ProjectATM.txt","r+");
    if(fp==NULL){
        upload();main();
    }

    while(!feof(fp)){
        last++;
        fscanf(fp,"%d\n",&acc[last].flagarr);
        fscanf(fp," %[^\n]\n",acc[last].AccNa);
        fscanf(fp,"%d\n",&acc[last].Bal);
        for(i=0;i<MAXacn;i++){
            fscanf(fp,"%d ",&acc[last].AccNo[i]);
        }
        fscanf(fp," \n%[^\n]\n",acc[last].Pin);
    }
    fclose(fp);
}

///UPLOAD INFO TO FLASHDRIVE
void uploadfd(){
    int i;
    FILE *fp;
        if(fopen("g:\\pin.txt","w+")){
            fp=fopen("g:\\pin.txt","w");
        }
        else if(fopen("f:\\pin.txt","w+")){
            fp=fopen("f:\\pin.txt","w");
        }
        else if(fopen("e:\\pin.txt","w+")){
            fp=fopen("e:\\pin.txt","w");
        }
        else if(fopen("d:\\pin.txt","w+")){
            fp=fopen("d:\\pin.txt","w");
        }
        else{
            fp=NULL;
        }
        fprintf(fp,"%d\n",flag);
        fprintf(fp,"%s\n",acc[flag].Pin);
        fprintf(fp,"%d\n",xd);
        for(i=1;i<=xd;i++){
            fprintf(fp,"%s\n",acc[flag].TrancDate[i]);
            fprintf(fp,"%d\n",acc[flag].TrancType[i]);
            fprintf(fp,"%d\n",acc[flag].TrancAmt[i]);
        }
    fclose(fp);
}

///DOWNLOAD INFO FROM FLASHDRIVE
void downloadfd(){
    int i;
    FILE *fp;
        if(fopen("g:\\pin.txt","r+")){
            fp=fopen("g:\\pin.txt","r");
        }
        else if(fopen("f:\\pin.txt","r+")){
            fp=fopen("f:\\pin.txt","r");
        }
        else if(fopen("e:\\pin.txt","r+")){
            fp=fopen("e:\\pin.txt","r");
        }
        else if(fopen("d:\\pin.txt","r+")){
            fp=fopen("d:\\pin.txt","r");
        }
        else{
            fp=NULL;
        }
    if(fp==NULL){
        uploadfd();main();
    }
        fscanf(fp,"%d\n",&flag);
        fscanf(fp," %[^\n]\n",acc[flag].Pin);
        fscanf(fp,"%d\n",&xd);
        for(i=1;i<=xd;i++){
            fscanf(fp," %[^\n]\n",acc[flag].TrancDate[i]);//\n
            fscanf(fp,"%d\n",&acc[flag].TrancType[i]);
            fscanf(fp,"%d\n",&acc[flag].TrancAmt[i]);
        }
    fclose(fp);
}

///INSERT FLASH DRIVE CHECKER
void insertcard(){
    FILE *fp;
    char a;
    design();printf("\033[0m");border();
    gotoxy(28,30);printf("Please Insert Card. Press enter to check card. Press escape to return to menu.\n");
    do{
        a=getch();
        if(a==27){
            system("cls");
            main();
        }
        if(fopen("g:\\pin.txt","r+")){
            fp=fopen("g:\\pin.txt","r");
        }
        else if(fopen("f:\\pin.txt","r+")){
            fp=fopen("f:\\pin.txt","r");
        }
        else if(fopen("e:\\pin.txt","r+")){
            fp=fopen("e:\\pin.txt","r");
        }
        else if(fopen("d:\\pin.txt","r+")){
            fp=fopen("d:\\pin.txt","r");
        }
        else{
            fp=NULL;
        }
    }while(fp==NULL);
    system("cls");
    fclose(fp);
}

///REMOVE FLASH DRIVE CHECKER
void removecard(){
    FILE *fp;
    do{
        border();design();
        gotoxy(25,50);printf("PLEASE REMOVE YOUR CARD.\n");
        Sleep(500);
        if(fopen("g:\\pin.txt","r+")){
            fp=fopen("g:\\pin.txt","r");
        }
        else if(fopen("f:\\pin.txt","r+")){
            fp=fopen("f:\\pin.txt","r");
        }
        else if(fopen("e:\\pin.txt","r+")){
            fp=fopen("e:\\pin.txt","r");
        }
        else if(fopen("d:\\pin.txt","r+")){
            fp=fopen("d:\\pin.txt","r");
        }
        else{
            fp=NULL;
        }
    }while(fp!=NULL);
    system("cls");

}

///GOTOXY FUNCTION
void gotoxy(int x,int y){
	printf("\e[%d;%df",x,y);
}

///BANK LOGO
void design(){
    printf("\033[0;34m");
    gotoxy(3,25);printf ("*                    *      *               *               *     ");gotoxy(14,25);printf("      aaaaaaa    aaaaaaaaaa    *         *          *          * ");
    gotoxy(4,25);printf ("             *       aaaaaaaaaaaaaaaa                        ");gotoxy(15,25);printf("    * aaaaaa a aaaaaa aaaaaa             *      *      *        ");
    gotoxy(5,25);printf ("      *          aaaaaaaaaaaaaaaaaaaaaaaa        *              ");gotoxy(16,25);printf("*      aaaaaaa  aaaaaaa             *          *          *     ");
    gotoxy(6,25);printf ("              aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa          *        ");gotoxy(17,25);printf(" *     aaaaaaaa            *        *   *       a            ");
    gotoxy(7,25);printf ("      *     aaaaaaaaaaaaaaaaa           aaaaaa                ");gotoxy(18,25);printf("        aaaaaaaaaa            *               aa     *      *  ");
    gotoxy(8,25);printf ("  *       aaaaaaaaaaaaaaaa          *       aaaa       *      ");gotoxy(19,25);printf("  *       aaaaaaaaaaaaaaaa         *        aaaa              ");
    gotoxy(9,25);printf ("         aaaaaaaaaaaaa aa      *               aa          *   ");gotoxy(20,25);printf("            aaaaaaaaaaaaaaaaa           aaaaaa        *       ");
    gotoxy(10,25);printf (" *      aaaaaaaa      aa              *          a    *        ");gotoxy(21,25);printf("*     *        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa              *   ");
    gotoxy(11,25);printf ("       aaaaaaa aa aaaa           *           *                  ");gotoxy(22,25);printf("                  aaaaaaaaaaaaaaaaaaaaaaaa          *          ");
    gotoxy(12,25);printf ("  *   aaaaaaaaa     aaa               *         *           ");gotoxy(23,25);printf("     *        *      aaaaaaaaaaaaaaaa       *        *        *   ");
    gotoxy(13,25);printf (" *    aaaaaaaaaaa aaaaaaa       *                          *   ");
    printf ("\033[0;33m");
    gotoxy(10,58);printf(" _  _ ____ ____ _  _ ____ _   _");gotoxy(14,55);printf("|  |) /_  /  O  \\|   ,'.|  ||  .'   / ");
    gotoxy(11,58);printf(" |\\/| |  | |  | |\\ | |___  \\_/  ");gotoxy(15,55);printf("|  .-.  \\|  .-.  ||  |' '  ||  .   '");
    gotoxy(12,58);printf(" |  | |__| |__| | \\| |___   |   ");gotoxy(16,55);printf("|  '--' /|  | |  ||  | `   ||  |\\   \\ ");
    gotoxy(13,55);printf(",-----.    ,---.  ,--.  ,--.,--. ,--. ");gotoxy(17,55);printf("`------' `--' `--'`--'  `--'`--' '--'");
}

///TRANSACTION MENU DESIGN
void transborder(){
    int i,j;
    border();
    printf("\033[0;36m");
    gotoxy(3,5);printf("                       .''.               ");gotoxy(16,5);printf("   cNNXXKKXK0c.                           ");
    gotoxy(4,5);printf("                  .:lxOOd:.               ");gotoxy(17,5);printf("   cNWNXKKKXKc.                           ");
    gotoxy(5,5);printf("              .;okXWWXx;.                 ");gotoxy(18,5);printf("   ;KMWNNXXXNd.                           ");
    gotoxy(6,5);printf("            'lOXWWWNx,.                   ");gotoxy(19,5);printf("   .kWWMWWNWW0,                          ");
    gotoxy(7,5);printf("          'o0XXXNNOc.                     ");gotoxy(20,5);printf("   :XMMMWWWNKl.                           ");
    gotoxy(8,5);printf("        .lKXXNXXXx,.                      ");gotoxy(21,5);printf("    .oNWWWMWXKO;.                         ");
    gotoxy(9,5);printf("       ,kXXNNNNKx'.                      ");gotoxy(22,5);printf("     .dNWNWWNNXO;.                        ");
    gotoxy(10,5);printf("      ;OXXXNNNXx'.                       ");gotoxy(23,5);printf("      .oKNNNWNNN0:.                       ");
    gotoxy(11,5);printf("     ;0XXXXXXNO,.                        ");gotoxy(24,5);printf("        ;OXXNNNNNKc.                      ");
    gotoxy(12,5);printf("    'kXKXKKKXXl.                         ");gotoxy(25,5);printf("         .l0XXNNNNXd'.                    ");
    gotoxy(13,5);printf("    oXXXKKKKNO,.                         ");gotoxy(26,5);printf("           'lOXXXXXKOc.                   ");
    gotoxy(14,5);printf("   ,0NKXXXKXXd.                          ");gotoxy(27,5);printf("             .;dOKXKK0x:.                 ");
    gotoxy(15,5);printf("   :NNKKKKKXKc.                          ");gotoxy(28,5);printf("                .,cdk000xc'.              ");
    gotoxy(29,5);printf("                  ..,:ccc;.             ");
    printf("\033[0;33m");
    for(i=0;i<=30;i++){
        gotoxy(5,i+35);printf("*");gotoxy(10,i+35);printf("*");
        gotoxy(12,i+35);printf("*");gotoxy(17,i+35);printf("*");
        gotoxy(19,i+35);printf("*");gotoxy(24,i+35);printf("*");
        gotoxy(5,i+85);printf("*");gotoxy(10,i+85);printf("*");
        gotoxy(12,i+85);printf("*");gotoxy(17,i+85);printf("*");
        gotoxy(19,i+85);printf("*");gotoxy(24,i+85);printf("*");
    }
    for(j=0;j<=4;j++){
        gotoxy(j+5,35);printf("*");gotoxy(j+5,65);printf("*");
        gotoxy(j+12,35);printf("*");gotoxy(j+12,65);printf("*");
        gotoxy(j+19,35);printf("*");gotoxy(j+19,65);printf("*");
        gotoxy(j+5,85);printf("*");gotoxy(j+5,115);printf("*");
        gotoxy(j+12,85);printf("*");gotoxy(j+12,115);printf("*");
        gotoxy(j+19,85);printf("*");gotoxy(j+19,115);printf("*");
    }
}

///MOON DESIGN
void moon(){
    gotoxy(4,25);printf("                              ..........                              ");gotoxy(17,25);printf("                  ,dddddxkxxxkxkkkkxkOKKXNNNNXXXXN0;                  ");
    gotoxy(5,25);printf("                         ..;ldkOOOOOOOkxdl:'.                         ");gotoxy(18,25);printf("                   ,xkdoddddxxxxkkkxxxOXNWWNNNXXXO;.                  ");
    gotoxy(6,25);printf("                       .cdOKK00KKK000KKKKKKOxc'                       ");gotoxy(19,25);printf("                    .lxkxxxxkkxxkOkkO0KNWWWWNNNKo.                    ");
    gotoxy(7,25);printf("                     'o0XK00OOOO00OO0KKKKKOxxOOo'                     ");gotoxy(20,25);printf("                      .cx00000kxkO000XXNNNWWN0o,.                     ");
    gotoxy(8,25);printf("                   .:OK00O0000K0Okkkk0KK0KK0kO00Oc.                   ");gotoxy(21,25);printf("                        .,lxOKXKKKKXXXXXK0ko;.                        ");
    gotoxy(9,25);printf("                  .l00OOOOO0000kxxxxddkkkxkO0OkkO0d.                  ");gotoxy(22,25);printf("                            .';:cccccc:;'..                           ");
}

///BORDERS
void border(){
    int i,j;
    for(i=0;i<=117;i++){
        gotoxy(1,i+2);printf("%c",203);gotoxy(118,i+2);printf("%c",202);
    }
    for(j=0;j<=27;j++){
        gotoxy(j+2,2);printf("%c",206);gotoxy(j+2,119);printf("%c",206);
    }
}

///TRANSACTION TEXT DESIGNS
void namedes(){
    border();
    if(c==1){
        printf("\033[0;33m");
        gotoxy(10,22);printf(":::::::::  :::::::::: :::::::::   ::::::::   :::::::: ::::::::::: ::::::::::: ");gotoxy(14,22);printf("+#+    +#+ +#+        +#+        +#+    +#+        +#+    +#+         +#+    ");
        gotoxy(11,22);printf(":+:    :+: :+:        :+:    :+: :+:    :+: :+:    :+:    :+:         :+:     ");gotoxy(15,22);printf("#+#    #+# #+#        #+#        #+#    #+# #+#    #+#    #+#         #+# ");
        gotoxy(12,22);printf("+:+    +:+ +:+        +:+    +:+ +:+    +:+ +:+           +:+         +:+  ");gotoxy(16,22);printf("#########  ########## ###         ########   ######## ###########     ### ");
        gotoxy(13,22);printf("+#+    +:+ +#++:++#   +#++:++#+  +#+    +:+ +#++:++#++    +#+         +#+ ");
    }
    else if(c==2){
        printf("\033[0;33m");
        gotoxy(10,13);printf(":::       ::: ::::::::::: ::::::::::: :::    ::: :::::::::  :::::::::      :::     :::       :::   ");gotoxy(14,13);printf("+#+ +#+#+ +#+     +#+         +#+     +#+    +#+ +#+    +#+ +#+    +#+ +#+     +#+ +#+ +#+#+ +#+   ");
        gotoxy(11,13);printf(":+:       :+:     :+:         :+:     :+:    :+: :+:    :+: :+:    :+:   :+: :+:   :+:       :+:   ");gotoxy(15,13);printf(" #+#+# #+#+#      #+#         #+#     #+#    #+# #+#    #+# #+#    #+# #+#     #+#  #+#+# #+#+#    ");
        gotoxy(12,13);printf("+:+       +:+     +:+         +:+     +:+    +:+ +:+    +:+ +:+    +:+  +:+   +:+  +:+       +:+   ");gotoxy(16,13);printf("  ###   ###   ###########     ###     ###    ### #########  ###    ### ###     ###   ###   ###     ");
        gotoxy(13,13);printf("+#+  +:+  +#+     +#+         +#+     +#++:++#++ +#+    +:+ +#++:++#:  +#++:++#++: +#+  +:+  +#+   ");
    }
    else if(c==3){
        printf("\033[0;33m");
        gotoxy(10,20);printf(":::::::::      :::     :::            :::     ::::    :::  ::::::::  :::::::::: ");gotoxy(14,20);printf("+#+    +#+ +#+     +#+ +#+        +#+     +#+ +#+  +#+#+# +#+        +#+        ");
        gotoxy(11,20);printf(":+:    :+:   :+: :+:   :+:          :+: :+:   :+:+:   :+: :+:    :+: :+:        ");gotoxy(15,20);printf("#+#    #+# #+#     #+# #+#        #+#     #+# #+#   #+#+# #+#    #+# #+#        ");
        gotoxy(12,20);printf("+:+    +:+  +:+   +:+  +:+         +:+   +:+  :+:+:+  +:+ +:+        +:+        ");gotoxy(16,20);printf("#########  ###     ### ########## ###     ### ###    ####  ########  ########## ");
        gotoxy(13,20);printf("+#++:++#+  +#++:++#++: +#+        +#++:++#++: +#+ +:+ +#+ +#+        +#++:++#   ");
    }
}

///END SCREEN DISPLAY
void end(){
    border();
    printf("\033[0;36m");
    gotoxy(5,15);printf("ooooooooooo oooo                               oooo             ooooo  oooo                          ");
    gotoxy(6,15);printf("88  888  88  888ooooo    ooooooo   oo oooooo    888  ooooo        888  88 ooooooo  oooo  oooo        ");
    gotoxy(7,15);printf("    888      888   888   ooooo888   888   888   888o888             888 888     888 888   888        ");
    gotoxy(8,15);printf("    888      888   888 888    888   888   888   8888 88o            888 888     888 888   888        ");
    gotoxy(9,15);printf("   o888o    o888o o888o 88ooo88 8o o888o o888o o888o o888o         o888o  88ooo88    888o88 8o       ");

    gotoxy(11,45);printf("ooooooooooo                          ");gotoxy(18,25);printf("oooooooooo                          oooo        o88                               ");
    gotoxy(12,45);printf(" 888       ooooooo  oo oooooo         ");gotoxy(19,25);printf(" 888    888   ooooooo   oo oooooo    888  ooooo oooo  oo oooooo     oooooooo8     ");
    gotoxy(13,45);printf(" 888ooo8 888     888 888    888       ");gotoxy(20,25);printf(" 888oooo88    ooooo888   888   888   888o888     888   888   888  888    88o      ");
    gotoxy(14,45);printf(" 888     888     888 888              ");gotoxy(21,25);printf(" 888    888 888    888   888   888   8888 88o    888   888   888   888oo888o      ");
    gotoxy(15,45);printf("o888o      88ooo88  o888o            ");gotoxy(22,25);printf(" o888ooo888   88ooo88 8o o888o o888o o888o o888o o888o o888o o888o 888     888    ");
    gotoxy(16,45);printf("                                     ");gotoxy(23,25);printf("                                                                   888ooo888      ");
    Sleep(4000);
}

///TRANSACTION BORDERS
void history(){
    int i,j;
    printf("\033[0;36m");
    for(i=0;i<=20;i++){
        gotoxy(10,i+10);printf("%c",215);gotoxy(14,i+10);printf("%c",215);
        gotoxy(10,i+50);printf("%c",215);gotoxy(14,i+50);printf("%c",215);
        gotoxy(10,i+90);printf("%c",215);gotoxy(14,i+90);printf("%c",215);
    }
    for(j=0;j<=3;j++){
        gotoxy(j+10,10);printf("%c",215);gotoxy(j+10,30);printf("%c",215);
        gotoxy(j+10,50);printf("%c",215);gotoxy(j+10,70);printf("%c",215);
        gotoxy(j+10,90);printf("%c",215);gotoxy(j+10,110);printf("%c",215);
    }
}



