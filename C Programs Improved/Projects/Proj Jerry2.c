#include <stdio.h>
int main()
{
    int num;
    int sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,sum11,sum12,sum13,sum14,sum15;
    printf("ALL IS NOTHING\n");
    printf("Enter a number: ");
    scanf("%d",&num);
    while (num>9)
        {
        printf("Enter another number from 1-9: ");
        scanf("%d",&num);
        }
if (num==1)
    printf("Does not apply");

else if(num==2)
    {
    sum1=(1+2);
    sum2=(1-2);
    if (sum1==0)
        printf("1+2=0");
    if (sum2==0)
        printf ("1-2=0");
    if (sum1!=0 && sum2!=0)
    printf("Does not apply");
    }

else if(num==3)
    {
     sum1=(1+2-3);
     sum2=(1-2+3);
    if (sum1==0)
        printf("1+2-3=0");
    if (sum2==0)
        printf ("1-2+3=0");
    if (sum1!=0&&sum2!=0)
        printf("Does not apply");
    }
else if (num==4)
    {
    sum1=(1+2+3-4);
    sum2=(1+2-3-4);
    sum3=(1-2+3-4);
    sum4=(1+2-3+4);
    sum5=(1-2-3+4);
    if (sum1==0)
        printf("1+2+3-4=0");
    if (sum2==0)
        printf ("1+2-3-4=0");
    if (sum3==0)
        printf ("1-2+3-4=0");
    if (sum4==0)
        printf ("1+2-3+4=0");
    if (sum5==0)
        printf("1-2-3+4=0");
    if (sum1!=0&&sum2!=0&&sum3!=0&&sum4!=0&&sum5!=0)
        printf("Does not apply");
    }
else if(num==5)
{
    sum1=(1+2+3+4-5);
    sum2=(1+2+3-4-5);
    sum3=(1+2-3-4-5);
    sum4=(1-2+3+4+5);
    sum5=(1-2-3+4+5);
    sum6=(1-2-3-4+5);
    sum7=(1+2-3+4-5);
    sum8=(1-2+3-4+5);
    sum9=(1-2+3+4-5);
    sum10=(1+2-3-4+5);
    if(sum1==0)
        printf("1+2+3+4-5=0");
    if(sum2==0)
        printf("1+2+3-4-5=0");
    if(sum3==0)
        printf("1+2-3-4-5=0");
    if(sum4==0)
        printf("1-2+3+4+5=0");
    if(sum5==0)
        printf("1-2-3+4+5=0");
    if (sum6==0)
        printf("1-2-3-4+5=0");
    if (sum7==0)
        printf("1+2-3+4-5=0");
    if (sum8==0)
        printf("1-2+3-4+5=0");
    if (sum9==0)
        printf("1-2+3+4=5=0");
    if (sum10==0)
        printf("1+2-3-4+5=0");
if (sum1!=0 && sum2!=0 && sum3!=0 && sum4!=0 &&sum5!=0 && sum6!=0 && sum7!=0 && sum8!=0 && sum9!=0 && sum10!=0)
    printf ("Does not apply");
}
else if(num==6)
{
    sum1=(1+2+3+4+5-6);
    sum2=(1+2+3+4-5-6);
    sum3=(1+2+3-4-5-6);
    sum4=(1-2+3+4+5+6);
    sum5=(1-2-3+4+5+6);
    sum6=(1-2-3-4+5+6);
    sum7=(1-2-3-4-5+6);
    sum8=(1-2+3-4+5-6);
    sum9=(1+2-3+4-5+6);
    sum10=(1-2+3+4-5-6);
    sum11=(1-2+3-4+5+6);
    if (sum1==0)
        printf("1+2+3+4+5-6=0\n");
    if (sum2==0)
        printf ("1+2+3+4-5-6=0\n");
    if (sum3==0)
        printf ("1+2+3-4-5-6=0\n");
    if (sum4==0)
        printf("1-2+3+4+5+6=0\n");
    if (sum5==0)
        printf("1-2-3+4+5+6=0\n");
    if(sum6==0)
        printf("1-2-3-4+5+6=0\n");
    if(sum7==0)
        printf("1-2-3-4-5+6=0\n");
    if (sum8==0)
        printf("1-2+3-4+5-6=0\n");
    if (sum9==0)
        printf("1+2-3+4-5+6=0\n");
    if (sum10==0)
        printf("1-2+3+4-5-6=0\n");
    if (sum11==0)
        printf ("1-2+3-4+5+6=0\n");
    if (sum1!=0 && sum2!=0&&sum3!=0&&sum4!=0&&sum5!=0&&sum6!=0&&sum7!=0&&sum8!=0&&sum9!=0&&sum10!=0&&sum11!=0)
    printf ("Does not apply");
}
else if(num==7)
{
    sum1=(1+2+3-4+5-6+7);
    sum2=(1-2+3-4+5-6+7);
    sum3=(1+2-3-4+5-6+7);
    sum4=(1-2-3+4-5+6+7);
    sum5=(1+2+3-4+5-6+7);
    sum6=(1-2+3-4-5+6-7);
    sum7=(1-2+3-4+5-6-7);
    sum8=(1+2-3+4-5-6+7);
    sum9=(1+2-3-4+5+6-7);
    sum10=(1-2+3+4-5+6-7);
    sum11=(1-2-3-4-5+6+7);
    if (sum1==0)
        printf("1+2+3-4+5-6+7=0\n");
    if (sum2==0)
        printf("1-2+3-4+5-6+7=0\n");
    if (sum3==0)
        printf("1+2-3-4+5-6+7=0\n");
    if (sum4==0)
        printf("1-2-3+4-5+6+7=0\n");
    if (sum5==0)
        printf("1+2+3-4+5-6+7=0\n");
    if (sum6==0)
        printf("1-2+3-4-5+6-7=0\n");
    if (sum7==0)
        printf("1-2+3-4+5-6-7=0\n");
    if (sum8==0)
        printf("1+2-3+4-5-6+7=0\n");
    if (sum9==0)
        printf("1+2-3-4+5+6-7=0\n");
    if (sum10==0)
        printf("1-2+3+4-5+6-7=0\n");
    if (sum11==0)
        printf("1-2-3-4-5+6+7=0\n");
if (sum1!=0&&sum2!=0&&sum3!=0&&sum4!=0&&sum5!=0&&sum6!=0&&sum7!=0&&sum8!=0&&sum9!=0&sum10!=0&&sum11!=0)
    printf("Does not apply");
}
else if(num==8)
{
    sum1=1+2+3+4+5+6-7-8;
    sum2=1+2+3+4+5-6-7-8;
    sum3=1+2+3+4-5-6-7-8;
    sum4=1+2+3-4-5-6-7-8;
    sum5=1+2-3-4-5-6-7-8;
    sum6=1+2-3+4-5+6-7+8;
    sum7=1-2+3-4+5-6+7-8;
    sum8=1+2-3-4+5-6-7+8;
    sum9=1-2+3+4-5+6+7-8;
    sum10=1+2-3-4-5+6+7+8;
    sum11=1-2+3+4+5-6-7+8;
    sum12=1+2-3+4+5+6-7-8;
    sum13=1-2+3-4-5+6-7+8;
    sum14=1-2-3+4-5+6+7-8;
    sum15=1+2-3-4-5-6+7+8;
    if(sum1==0)
        printf("1+2+3+4+5+6-7-8=0\n");
    if(sum2==0)
        printf("1+2+3+4+5-6-7-8=0\n");
    if(sum3==0)
        printf("1+2+3+4-5-6-7-8=0\n");
    if(sum4==0)
        printf("1+2+3-4-5-6-7-8=0\n");
    if(sum5==0)
        printf("1+2-3-4-5-6-7-8=0\n");
    if (sum6==0)
        printf("1+2-3+4-5+6-7+8=0\n");
    if (sum7==0)
        printf("1-2+3-4+5-6+7-8=0\n");
    if (sum8==0)
        printf("1+2-3-4+5-6-7+8=0\n");
    if (sum9==0)
        printf("1-2+3+4-5+6+7-8=0\n");
    if(sum10==0)
        printf("1+2-3-4-5+6+7+8=0\n");
    if(sum11==0)
        printf("1-2+3+4+5-6-7+8=0\n");
    if (sum12==0)
        printf("1+2-3+4+5+6-7-8=0\n");
    if(sum13==0)
        printf("1-2+3-4-5+6-7+8=0\n");
    if(sum14==0)
        printf("1-2-3+4-5+6+7-8=0\n");
    if(sum15==0)
        printf("1+2-3-4-5-6+7+8=0\n");
    if(sum1!=0&&sum2!=0&&sum3!=0&&sum4!=0&&sum5!=0&&sum6!=0&&sum7!=0&&sum8!=0&&sum9!=0&&sum10!=0&&sum11!=0&&sum12!=0&&sum13!=0&&sum14!=0&&sum15!=0)
    printf("Does not apply");
}
else if (num==9)
   {

sum1=1+2+3+4+5+6+7+8+9;
    if (sum1/2!=0)
        printf("Does not apply");

   }
    return 0;

}
