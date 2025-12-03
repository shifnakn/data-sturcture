#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define INFINITY 9999

int main()
{
int cost[SIZE][SIZE],distance[SIZE],pred[SIZE];
int visited[SIZE],count,mindist,nextnode,i,j;
int startnode,n;

printf("Enter no .of vertices:");
scanf("%d",&n);

printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=INFINITY;
}

printf("\nEnter the starting node:");
scanf("%d",&startnode);

for(i=0;i<n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}

distance[startnode]=0;
visited[startnode]=1;
count=1;

while(count<n-1)
{
mindist=INFINITY;

for(i=0;i<n;i++)
if(distance[i]<mindist&&!visited[i])
{
mindist=distance[i];
nextnode=i;
}

visited[nextnode]=1;

for(i=0;i<n;i++)
if(!visited[i])
if(mindist+cost[nextnode][i]<distance[i])
{
distance[i]=mindist+cost[nextnode][i];
pred[i]=nextnode;
}

count++;
}

for(i=0;i<n;i++)
if(i!=startnode)
{
printf("\nDistance of node%d=%d",i,distance[i]);
printf("\npath=%d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=startnode);
}

}


