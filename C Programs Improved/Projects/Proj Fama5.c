#include <stdio.h>


void Schedule (int numF, int teamF);
int main()
{

int N,team_F;

printf ("Enter the number of teams: ");
scanf ("%d",&N);

printf ("Round\t");

team_F=1;
while (team_F<=N){
   printf ("Team%d\t",team_F);
   team_F++;
}

printf ("\n");

Schedule (N,team_F);

return 0;
}
void Schedule (int numF, int teamF)
{
int roundF,firstF,secondF;

if (numF%2==0){
for (roundF=1;roundF<=numF;roundF++){
     printf ("  %d\t",roundF);
    
    
  for (firstF=roundF-1;firstF>=1;firstF--){
    printf ("  %d\t",firstF);}
   for (secondF=numF;secondF>=roundF;secondF--){
    printf ("  %d\t",secondF);}  
  
    printf ("\n");
    }
 }
else 
{
   for (roundF=1;roundF<=numF;roundF++){
     printf ("  %d\t",roundF);
    
    teamF=0;
  for (firstF=roundF-1;firstF>=1;firstF--){
    teamF++;
    if (firstF==teamF)
    {printf (" bye\t");}
    else 
    printf ("  %d\t",firstF);}
   for (secondF=numF;secondF>=roundF;secondF--){
    teamF++;
    if (secondF==teamF)
    {printf (" bye\t");}
    else 
    printf ("  %d\t",secondF);}  
  
    printf ("\n");
    }
}
  
}