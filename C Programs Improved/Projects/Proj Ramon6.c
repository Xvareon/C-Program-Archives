#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void Swapping (int *y,int *z);
void Permute (int *MainArraySub,int st,int SubHalfSizeplus,int SubHalfSizeminus,int ArrSizeSub);

static int smallest[2];

int main()
{
    int ArraySize, SizeHalfplus, SizeHalfminus, i;

    printf("Input the number of unique integers to be entered: ");
    scanf("%d", &ArraySize);

    int MainArray[ArraySize];

    system("cls");

    printf("Enter %d unique integers:\n", ArraySize);
    for(int i=0;i<ArraySize;i++)
    {
        scanf("%d",&MainArray[i]);
    }

    //Determining if the ArraySize is odd or even
    if(ArraySize==2)
    {
        SizeHalfplus = 1;
        SizeHalfminus = 1;
    }
    else if(ArraySize==3)
    {
        SizeHalfplus = 2;
        SizeHalfminus = 1;
    }
    else if(ArraySize%2==0)
    {
        SizeHalfplus = ArraySize/2;
        SizeHalfminus = SizeHalfplus;
    }
    else
    {
        SizeHalfminus = ArraySize/2;
        SizeHalfplus = ArraySize-SizeHalfminus;
    }

    system("cls");


    Permute(MainArray,0,SizeHalfplus,SizeHalfminus,ArraySize);

    printf("Among the permutations of ");
    for(i=0; i<ArraySize; i++)
        {
            if(i<ArraySize-1)
                printf("%d, ", MainArray[i]);
            else if(i==ArraySize-1)
                printf("and %d ", MainArray[i]);
        }

    printf("the smallest difference is : %d\n",smallest[1]);

    return 0;
}//End of Main Function


//Swap Function
void Swapping (int *first,int *second)
{
    int temp;

    temp=*first;
    *first=*second;
    *second=temp;

}//End of Swap Function


//Permute Function
void Permute (int *MainArraySub,int permNum,int SubHalfSizeplus,int SubHalfSizeminus,int ArrSizeSub)
{
    static int limit;
    int i=0,Num1=0,Num2=0,small, j;
    int n[5]={1,10,100,1000,10000};


    if(permNum==ArrSizeSub)
    {
        //Dividing the Main Array into 2 and converting it to a single variable
            for(j=0;j<SubHalfSizeplus;j++)
            {
                Num1+=MainArraySub[j]*n[SubHalfSizeplus-1-j];
            }
            for(j=0;j<SubHalfSizeminus;j++)
            {
                Num2+=MainArraySub[j+(SubHalfSizeplus)]*n[SubHalfSizeminus-1-j];
            }

        //Determining the Smallest Difference
        if (ArrSizeSub==2)
        {
            small=abs(Num1-Num2);
            smallest[0]=small;

             if(limit==0)
            {
                smallest[1]=smallest[0];
            }
            if(smallest[0]<smallest[1])
            {
                smallest[1]=smallest[0];
            }
        }
        else if(ArrSizeSub==3)
        {
            if(MainArraySub[0]==0)
            {
                small=abs((Num1*10)-Num2);
                if(limit==0)
                {
                    smallest[1]=smallest[0];
                }
            }
            else
            {
                small=abs(Num1-Num2);
                smallest[0]=small;
                if(limit==0)
                {
                    smallest[1]=smallest[0];
                }
                if(smallest[0]<smallest[1])
                {
                    smallest[1]=smallest[0];
                }
                limit++;
            }
        }
        else if(Num1>n[SubHalfSizeplus-1] && Num2>n[SubHalfSizeminus-1])
        {
            small = abs(Num1-Num2);

            smallest[0]=small;

            //Determining the smallest among the differences
            if(limit==0)
            {
                smallest[1]=smallest[0];
            }
            if(smallest[0]<smallest[1])
            {
                smallest[1]=smallest[0];
            }

            limit++;
        }
    }//End of IF
    else
    {
        for(i=permNum;i<ArrSizeSub;i++)
            {
                Swapping(MainArraySub+permNum, MainArraySub+i);
                Permute(MainArraySub, permNum+1, SubHalfSizeplus, SubHalfSizeminus, ArrSizeSub);
                Swapping(MainArraySub+permNum, MainArraySub+i);
            }

        for(i=permNum+SubHalfSizeminus+1;i<ArrSizeSub;i++)
            {
                Swapping(MainArraySub+permNum, MainArraySub+i);
                Permute(MainArraySub, permNum+SubHalfSizeminus, SubHalfSizeplus, SubHalfSizeminus, ArrSizeSub);
                Swapping(MainArraySub+permNum, MainArraySub+i);
            }
    }//End of else


}//End of Permute Function
