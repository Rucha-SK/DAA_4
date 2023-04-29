#include<stdio.h>
#define INFINITY 9999

int n;
int adj[100][100];

void dj_algo(int start){
int cost[100][100],distance[100],pred[100];
int visited[100],count,mindistance,nextnode,i,j;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far

//create the cost matrix
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(adj[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=adj[i][j];



//initialize pred[],distance[] and visited[]
for(i=0;i<n;i++)
{
distance[i]=cost[start][i];
pred[i]=start;
visited[i]=0;
}
distance[start]=0;
visited[start]=1;
count=1;
printf("Order of visiting vertices is: %d ",start);
while(count<n-1)
{
mindistance=INFINITY;
//nextnode gives the node at minimum distance
for(i=0;i<n;i++)
if(distance[i]<mindistance && !visited[i])
{
mindistance=distance[i];
nextnode=i;
}
//check if a better path exists through nextnode
printf("%d ",nextnode);//visiting vertex
visited[nextnode]=1;
for(i=0;i<n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i]<distance[i])
{
distance[i]=mindistance+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}

for(int i=0;i<n;i++){
if(visited[i]==0)
{
 printf("%d ",i);// showing visiting vertex
 break;
}

}
printf("\n");
//print the path and distance of each node
for(i=0;i<n;i++)
if(i!=start)
{
printf("\nDistance of node%d=%d",i,distance[i]);
printf("\nPath=%d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=start);
}
}
int main(){

printf("Enter no. of vertices ");
scanf("%d",&n);

printf("\nEnter adjacency matrix\n ");
for(int i=0;i<n;i++){
printf("Vertice %d: ",i);
for(int j=0;j<n;j++){
scanf("%d",&adj[i][j]);
}
printf("\n");
}

printf("\nThe adjacency matrix is:\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf(" %d",adj[i][j]);
}
printf("\n");
}

printf("\nEnter starting vertex");
int start;
scanf("%d",&start);

dj_algo(start);
return 0;
}