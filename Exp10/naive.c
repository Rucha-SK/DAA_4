#include<stdio.h>
#include<string.h>


void Naive(char* T,char* P){
int n=strlen(T);
int m=strlen(P);
for(int i=0;i<=n-m;i++){
for (int j=0; j<m; j++) {
        
          if(j==m-1){
          printf("Pattern occurs after %d shifts\n",i);
          }
          if (T[i + j] != P[j])
          break;
          
      }
}
}


int main(){

//char T[]="my name is rucha";
//char P[]="rucha";
char T[20],P[20];
printf("Enter text string\n");
scanf("%[^\n]%*c",T);
printf("Enter pattern string to be found\n");
scanf("%s",P);
Naive(T,P);

return 0;
}