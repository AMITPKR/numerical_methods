//Gauss jacobi iteration method in c
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
void main()
{
 float a[10][10],b[10],x[10],xn[10],epp=0.00001,sum;
 int i,j,n,flag;
 
 printf("\nEnter number of variables: ");
 scanf("%d",&n);
 printf("\nEnter the coefficients row-wise: ");
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%f",&a[i][j]);
 }
 }
 printf("\nEnter right hand vector: ");
 for(i=0;i<n;i++)
 scanf("%f",&b[i]);
 for(i=0;i<n;i++)
 x[i]=0; //initialize
 
 //checking for row dominance
 flag=0;
 for(i=0;i<n;i++)
 {
 sum=0;
 for(j=0;j<n;j++)
 if(i!=j)
 sum+=fabs(a[i][j]);
 if(sum>fabs(a[i][i]))
 flag=1;
 }
 
 //checking for column dominance
 if(flag==1)
 flag=0;
 for(j=1;j<n;j++)
 {
 sum=0;
 for(i=1;i<n;i++)
 if(i!=j)
 sum+=fabs(a[i][j]);
 if(sum>fabs(a[j][j]))
 flag=1;
 }
 
 if(flag==1)
 {
 printf("The coefficient matrix is not diagonally dominant \n");
 printf("The Gauss-Jacobi method does not converge surely");
 exit(0);
 }
 
 for(i=0;i<n;i++)
 printf(" x[%d] ",i);
 printf("\n");
 
 do
 {
 for(i=0;i<n;i++)
 {
 sum=b[i];
 for(j=0;j<n;j++)
 if(j!=i)
 sum-=a[i][j]*x[j];
 xn[i]=sum/a[i][i];
 }
 for(i=0;i<n;i++)
 printf("%8.5f ",xn[i]);
 printf("\n");
 flag=0; 
 //indicates |x[i]-xn[i]|<epp for all i
 for(i=0;i<n;i++)
 if(fabs(x[i]-xn[i])<epp)
 flag=1;
 if(flag==1)
 for(i=1;i<n;i++)
 x[i]=xn[i]; //reset x[i]	
 
 }while(flag==1);
 
 printf("Solutoin is \n");
 for(i=0;i<n;i++)
 printf("%8.5f ",xn[i]);
}