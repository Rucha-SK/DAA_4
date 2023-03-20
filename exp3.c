#include<stdio.h>
#include<stdlib.h>

int main(){
int a[2][2],b[2][2],c[2][2];
int n=2;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
a[i][j]=rand()%10;
}
}

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
b[i][j]=rand()%10;
}
}

printf("Matrix A is:\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf("%d ",a[i][j]);
}
printf("\n");
}

printf("Matrix B is:\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf("%d ",b[i][j]);
}
printf("\n");
}

int s1=b[0][1] -b[1][1];
int s2=a[0][0] +a[0][1];
int s3=a[1][0] +a[1][1];
int s4=b[1][0]-b[0][0];
int s5=a[0][0]+a[1][1];
int s6=b[0][0]+b[1][1];
int s7=a[0][1]-a[1][1];
int s8=b[1][0]+b[1][1];
int s9=a[0][0]-a[1][0];
int s10=b[0][0]+b[0][1];

int p1=a[0][0]*s1;
int p2=s2*b[1][1];
int p3=s3*b[0][0];
int p4=a[1][1]*s4;
int p5=s5*s6;
int p6=s7*s8;
int p7=s9*s10;

c[0][0]=p4 + p5 - p2 + p6;
c[0][1]=p1+p2;
c[1][0]=p3+p4;
c[1][1]=p5+p1-p3-p7;

printf("Matrix C is:\n");
for(int i=0;i<2;i++){
for(int j=0;j<2;j++){
printf("%d ",c[i][j]);
}
printf("\n");
}

return 0;
}
