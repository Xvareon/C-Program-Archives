#include <stdio.h>

int S (int n);
int main ()
{
int numF;
printf ("Input integer: ");
scanf ("%d",&numF);

if (S(numF)==1)
{
  printf (",%d is a happy number",numF);
}
else 
{
  printf ("%d belongs to unhappy numbers",numF);
}
return 0;
}
int S (int n)
{
int resF,totalresF,sumF,aF;
aF=n; 

while (n!=1 && n!=4) {
 sumF=0;
  while (n>0){
   resF=n%10;
   totalresF=resF*resF;
   sumF=sumF+totalresF;
   n=n/10;
   }
   n=sumF;
}

if (sumF==1) {
   while (aF!=1) {
 sumF=0;
  while (aF>0){
   resF=aF%10;
   totalresF=resF*resF;
   sumF=sumF+totalresF;
   aF=aF/10;
   }
   aF=sumF;
printf (" %d",sumF);
 }
}

return sumF;
}