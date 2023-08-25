#include <stdio.h>

int main()
{

int numF[100],disF[100],sizeF=0,numberF,meterF,xF,resF,baseF;

//input 0 to end input stage
printf ("Input Odometer Reading\n");
do {
scanf ("%d",&numberF);
numF[sizeF]=numberF;
sizeF++;
} while (numberF!=0);

for (xF=0;xF<sizeF-1;xF++)
{
disF[xF]=numF[xF];
baseF=0;
meterF=0;
while (numF[xF]>0)
{
   int expF=1;
   resF=numF[xF]%10;
   if (resF>4)
      { resF-=1;}
   if (baseF>0)
      { for (int yF=1;yF<=baseF;yF++)
         {expF*=9;}
        resF*=expF;}
   meterF=meterF+resF;
   numF[xF]=numF[xF]/10;

   baseF++;
}
printf ("%d;%d\n",disF[xF],meterF);

}

  return 0; 
}