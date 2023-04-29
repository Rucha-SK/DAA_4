#include<stdio.h>
#include<math.h>
int x[30],count;
int place(int k,int i) {
	for (int j=1;j<k;j++) {
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		   return 0;
	}
	return 1;
}
void print_sol(int n) {
	int i,j;
	printf("\n\nSolution %d:\n",count);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if(x[i]==j)
			    printf("Q\t"); else
			    printf("*\t");
		}
		printf("\n");
	}
}
void queen(int k,int n) {
	

    for(int i=1;i<=n;i++){
        //printf("place %d,%d==%d\n",k,i,place(k,i));
        if(place(k,i)==1){
            x[k]=i;
            if(k==n){
                count++;
                printf("solution %d: ",count);
                for(int a=1;a<=n;a++){
                    printf("%d ",x[a]);
                }
                printf("\n");
            }
            else{
                queen(k+1,n);
            }
        }
    }

}
void main() {
	int i,n;
    count=0;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
    // for(int i=1;i<=n;i++)
	queen(1,n);
	printf("\nTotal solutions=%d",count);
}