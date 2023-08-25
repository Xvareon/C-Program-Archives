/**BASIC MODULAR**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 50

int arr[MAX];
int flag=0,choice;

int menu();
void Fill();
void Display();
void Sort();
void Query();
void Delete();
void upload();
void download();

int main(){

    flag=0;
    download();
    if(arr[1]==-1){
        printf("Debug: Cleaning trash...\n");
        flag=0;
        getch();
    }
    else{
        printf("Debug: No trash to see here!\n");
        getch();
    }

    system("cls");
    while(1){
        switch(menu()){
            case 1 : system("cls");Fill();getch();system("cls");break;
            case 2 : system("cls");Display();getch();system("cls");break;
            case 3 : system("cls");Sort();getch();system("cls");break;
            case 4 : system("cls");Query();getch();system("cls");break;
            case 5 : system("cls");Delete();getch();system("cls");break;
            case 6 : system("cls");printf("FILE SAVED SUCCESSFULLY\n\n");upload();exit(0);break;
            default: printf("\n\nINVALID INPUT");getch();break;
        }
    }

}

int menu(){

    printf("MENU\n\n");
    printf("[1] Fill array\n");
    printf("[2] Display array\n");
    printf("[3] Sort array\n");
    printf("[4] Query Content of array\n");
    printf("[5] Delete element in the array\n");
    printf("[6] Terminate the program and save progress\n\n");
    printf("Enter Choice: ");scanf(" %d",&choice);
    return (choice);

}

void Fill(){

    if(flag<MAX){
        flag++;
        printf("Enter integer for index [%d]: ",flag);
        scanf(" %d",&arr[flag]);
    }
    else{
        printf("You have already reached %d integers, the limit!",MAX);
    }

}

void Display(){
    system("cls");
    int i;
    printf("The current integers in the record are:\n\n");
    for(i=1;i<=flag;i++){
        printf("[%d] %d\n",i,arr[i]);
    }

}

void Sort(){

    int i,j,temp;
    for (i=1;i<=flag-1;i++){
        for (j=i+1;j<=flag;j++){
            if (arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nArray Sorted");

}

void Query(){

    printf("\nDi ko gets kaya placeholder muna");
    printf("\nCurrent number of integers: %d",flag);

}

void Delete(){

    int i,del;
    Display();
    printf("\nEnter index you want to delete: ");scanf(" %d",&del);
    if(del<1 || del>flag){
        printf("\nInvalid Input!");
    }
    else{
        for(i=del;i<=flag;i++){
            arr[i]=arr[i+1];
        }
        flag--;
        Display();
    }

}

void upload(){

    int i,j;
    FILE *fp;
    fp=fopen("Integers.txt","w+");
    for(i=1;i<=flag;i++){
        fprintf(fp," %d\n",arr[i]);
    }
    fclose(fp);

}

void download(){

    FILE *fp;
    fp=fopen("Integers.txt","r+");
    if(fp==NULL){
        arr[1]=-1;upload();main();
    }
    while(!feof(fp)){
        flag++;
        fscanf(fp," %d\n",&arr[flag]);
    }
    fclose(fp);

}


