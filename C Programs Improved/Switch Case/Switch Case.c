#include<stdio.h>
#include<stdlib.h>

void displaymonth (int n);

int main()
{
    int c, no;

    printf("\nCalendar\n");
    printf("\nPlease enter numeric month: ");
    scanf("%d", &no);

    displaymonth(no);
    printf("\n1)Yes\n2)Exit\nDo you want to loop? ");
    scanf("%d", &c);
    if(c==1){
        system("cls");
        main();
    }
    else{
        return 0;
    }
}

void displaymonth (int n)
{
    switch(n){
    case 1:printf("\nThe no.%d represents month of January\n\n", n);break;
    case 2:printf("\nThe no.%d represents month of February\n\n", n);break;
    case 3:printf("\nThe no.%d represents month of March\n\n", n);break;
    case 4:printf("\nThe no.%d represents month of April\n\n", n);break;
    case 5:printf("\nThe no.%d represents month of May\n\n", n);break;
    case 6:printf("\nThe no.%d represents month of June\n\n", n);break;
    case 7:printf("\nThe no.%d represents month of July\n\n", n);break;
    case 8:printf("\nThe no.%d represents month of August\n\n", n);break;
    case 9:printf("\nThe no.%d represents month of September\n\n", n);break;
    case 10:printf("\nThe no.%d represents month of October\n\n", n);break;
    case 11:printf("\nThe no.%d represents month of November\n\n", n);break;
    case 12:printf("\nThe no.%d represents month of December\n\n", n);break;
    default:printf("\nThe no.%d is Invalid\n\n", n);break;
    }
}
