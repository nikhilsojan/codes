#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*
struct node
{
int val;
int wt;
struct node *next;
};*/
int b[10000],distance[10000],n,m;

//typedef struct node *nd;
int a[10000][3];

int bellman(int v)
{
int i,j;

   
   for(i=0;i<n;i++)
   distance[i]=INT_MAX;
distance[v]=0;

for(i=0;i<n-1;++i)
{
	for(i=0;i<m;++i)
	{
	if(distance[a[i][0]]!=INT_MAX&&distance[a[i][1]]>distance[a[i][0]]+a[i][2])
		{
		distance[a[i][1]]=distance[a[i][0]]+a[i][2];
		}
	}
}

for(i=0;i<m;++i)
	{
	if(distance[a[i][0]]!=INT_MAX&&distance[a[i][1]]>distance[a[i][0]]+a[i][2])
		return 1;
	}

return -1;

}


void main()
{



int i,f,t,w;
scanf("%d%d",&n,&m);
for(i=0;i<n;++i)
b[i]=-1;


for(i=0;i<m;++i)
{
scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
if(b[a[i][0]]!=-1)
b[a[i][0]]=a[i][0];

}
t=bellman(0);


printf("%d\n",t);

}


