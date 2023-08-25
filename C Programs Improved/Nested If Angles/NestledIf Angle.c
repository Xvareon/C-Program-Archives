#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//make this flexible, eg. 361 angles and above
int main()
{
    int theta=0;
    while (theta>-1){
    printf("Input an angle. \n");
    scanf("%d",&theta);
    if (theta >= 0 && theta <= 90)
        if (theta == 90)
            printf("+Y-Axis.");
        else if (theta == 0)
            printf("+X-Axis.");
        else
            printf("Quadrant 1.");
    else if (theta > 90 && theta <= 180)
        if (theta == 180)
            printf("-X-Axis.");
        else
            printf("Quadrant 2.");
    else if (theta > 180 && theta <= 270)
        if (theta == 270)
            printf("-Y-Axis.");
        else
            printf("Quadrant 3.");
    else if (theta > 270 && theta <= 360)
        if (theta == 360)
            printf("+X-Axis.");
        else
            printf("Quadrant 4.");
    else
        printf("ERROR Wrong Coordinates.");
    getch();
    system("cls");
    }
    return 0;
}
