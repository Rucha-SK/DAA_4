#include<stdio.h>
#include<string.h>

int sphits=0;
int validhits=0;

void Rabin(char T[],char P[],int q){
int m = strlen(P);
  int n = strlen(T);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h) % q;

  for (i = 0; i < m; i++) {
    p = ( p + P[i]) % q;
    t = ( t + T[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
        sphits++;
      for (j = 0; j < m; j++) {
        if (T[i + j] != P[j])
          break;
      }

      if (j == m)
      {
        validhits++;
        if(validhits==1)
          printf("Pattern is found at position:  %d ", i + 1);
          else{
            printf(", %d ", i + 1);
          }
      }
        
    }

    if (i < n - m) {
      t = ( (t - T[i] * h) + T[i + m]) % q;

      if (t < 0)
      {
         t = (t + q);

        
      }
       
    }
  }
}


int main(){
int q=13;
//char T[]="my name is rucha";
//char P[]="rucha";
char T[20],P[20];
printf("Enter text string\n");
scanf("%[^\n]%*c",T);
printf("Enter pattern string to be found\n");
scanf("%[^\n]%*c",P);
Rabin(T,P,q);
printf("\nValid hits are: %d",validhits);
printf("\nSpurious hits are: %d",sphits-validhits);
return 0;
}