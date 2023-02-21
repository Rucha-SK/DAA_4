#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int s=0;
int c=0;
int cq=0;
void merge(int arr[],int leftp,int midp,int rightp){
int leftlen=midp-leftp+1;
int rightlen=rightp-midp;

int left[leftlen],right[rightlen];

for(int i=0;i<leftlen;i++){
left[i]=arr[leftp+i];
}
for(int i=0;i<rightlen;i++){
right[i]=arr[midp+1+i];
}

int i=0,j=0,k=leftp;

while(i<leftlen && j<rightlen){
if(left[i]<=right[j]){
arr[k]=left[i];
i++;
}
else{
arr[k]=right[j];
j++;
}
k++;
c++; //count of comaparisons done during merge. One comparison is done per iteration of while loop. 
}

while(i<leftlen){
arr[k]=left[i];
k++;
i++;
}

while(j<rightlen){
arr[k]=right[j];
k++;
j++;
}

}

void mergesort(int arr[],int l,int r){
if(l<r){
int m=l + (r-l)/2;

mergesort(arr,l,m);
mergesort(arr,m+1,r);
merge(arr,l,m,r);
}
}

int partition(int a[],int lb, int ub){
 int Pivot=a[lb];
 int st=lb,end=ub;
 while(st<end){
    while(a[st]<=Pivot){
        st++;
    }
    while(a[end]>Pivot){
        end--;
    }
    if(st<end)
    swap(&a[st],&a[end]);

    cq++;
 }
 swap(&a[end],&a[lb]);

 return end;
}

void Quicksort(int a[],int lb,int ub){
 if(lb<ub){
    int loc=partition(a,lb,ub);
    Quicksort(a,lb,loc-1);
    Quicksort(a,loc+1,ub);
 }
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  s++;
}

int main(){
int arr[100000],arr2[100000];
FILE *fptr;
FILE *sortans;
FILE *timeans;
FILE *sortans2;
FILE *timeans2;
FILE *swapcountq;
FILE *compcountm;
fptr = fopen("lab2.txt","w");
sortans = fopen("lab2sort.txt","w");
timeans = fopen("lab2time.txt","w");
sortans2 = fopen("lab2sort2.txt","w");
timeans2 = fopen("lab2time2.txt","w");
swapcountq = fopen("lab2swapcountq.txt","w");
compcountm = fopen("lab2compcountm.txt","w");

clock_t start, end;
for(int i=0;i<100000;i++){
int x=rand()%10000;
arr[i]=x;
arr2[i]=x;
}

for(int i=0;i<100000;i++){
//printf("%d\n",arr[i]);
fprintf(fptr,"%d\n",arr[i]);
}

int cbefore=0;
int cqbefore=0;
for(int i=1;i<=100;i++){
    start = clock();
mergesort(arr,0,i*1000);
end = clock();
//printf("Array %d after mergesort:\n",i);
double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
printf("Time taken for %d elements to sort using merge sort:%f s  \n",i*1000,time_taken);
printf("no. of comparisons made: %d\n",c-cbefore);
fprintf(compcountm,"%d\n",c-cbefore);
cbefore=c;
fprintf(timeans,"%f\n",time_taken);
fprintf(sortans,"Array %d after mergesort:\n",i);
for(int j=0;j<i*1000;j++){
//printf("%d\n",arr[j]);
fprintf(sortans,"%d\n",arr[j]);
}
}
int sbefore=0;
for(int i=1;i<=100;i++){
    start = clock();
Quicksort(arr2,0,i*1000);
end = clock();
//printf("Array %d after mergesort:\n",i);
double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
printf("Time taken for %d elements to sort using Quick sort:%f s  \n",i*1000,time_taken);
printf("no. of swaps taken: %d\n",s-sbefore);
fprintf(swapcountq,"%d\n",s-sbefore);
//printf("no. of comparisons made: %d\n",cq-cqbefore);
sbefore=s;
cqbefore=cq;
fprintf(timeans2,"%f\n",time_taken);
fprintf(sortans2,"Array %d after Quick sort:\n",i);
for(int j=0;j<i*1000;j++){
//printf("%d\n",arr[j]);
fprintf(sortans2,"%d\n",arr2[j]);
}
}

// printf("Array after mergesort:");
// for(int i=0;i<1000;i++){
// printf("%d\n",arr[i]);
// }

return 0;
}