#include <stdio.h>
#include<stdlib.h>

long int m[20][20];
int s[20][20];
int p[20],i,j,n;

void print_optimal(int i,int j)
{
if (i == j)
printf(" A%d ",i);
else
   {
      printf("( ");
      print_optimal(i, s[i][j]);
      print_optimal(s[i][j] + 1, j);
      printf(" )");
   }
}

void matmultiply()
{
long int q;
int k;
for(i=n;i>0;i--)
 {
   for(j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}


void main()
{
int k;
printf("Enter the no. of elements: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
{
 m[i][i]=0;
 m[i][j]=999999999;
 s[i][j]=0;
}
printf("\nThe randomly generated dimensions are: \n");
for(k=0;k<=n;k++)
{
 printf("P%d: ",k);
 int upper=46,lower=15;
 
 p[k]=(rand() % (upper-lower+1))+lower ;
 printf("%d\n",p[k]);

 //scanf("%d",&p[k]);
}
matmultiply();
printf("\nCost Matrix M:\n");
for(i=1;i<=n;i++)
 for(j=i;j<=n;j++)
  printf("m[%d][%d]: %ld\n",i,j,m[i][j]);

printf("\nMatrix S:\n");
for(i=1;i<=n;i++)
 for(j=i;j<=n;j++)
  printf("s[%d][%d]: %ld\n",i,j,s[i][j]);

i=1,j=n;
printf("\nMultiplication Sequence : ");
print_optimal(i,j);
printf("\nMinimum number of multiplications is : %d ", m[1][n]);

}