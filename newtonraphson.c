#include<stdio.h>
#include<math.h>
#define e 0.001
#define f(x) cos(x)-x*x-x
#define df(x) -sin(x)-2*x-1
int main()
{
float x0,x1,f0,f1,df0;
int i=0;
printf("enter the value of x0\n");
scanf("%f",&x0);
do
{
 f0=f(x0);
 df0=df(x0);
 x1=x0-(f0/df0);
 f1=f(x1);
 x0=x1;
 i++;
 printf("no of iteration=%d\t",i);
 printf("root=%f\t",x1);
 printf("value of function =%f\n",f1);
} while (fabs(f1)>e);
return 0;

}