#include<stdio.h>
#include<stdlib.h>

struct vertex
{
	int key;
	struct vertex *parent;
}*v[10000];

struct edge
{
	int u,v,wt;
	
}ea[100000];
int n,ctr=0,sum=0;
typedef struct vertex *ver;


void makeset(int x)
{	ver ptr=(ver)malloc(sizeof(ver));
	ptr->key=x;
	ptr->parent=ptr;
	v[x]=ptr;
}


void sort()
{	int i,j;
	for(i=0;i<ctr-1;i++)
		for(j=0;j<ctr-1;j++)
			if(ea[j].wt>ea[j+1].wt)
			{
				struct edge temp=ea[j];
				ea[j]=ea[j+1];
				ea[j+1]=temp;
			}

}




ver find(int x)
{	if(v[x]==NULL)
		return NULL;
	ver ptr=v[x];
	while(ptr!=NULL)
	{	if(ptr->parent==ptr)
			return ptr;
		ptr=ptr->parent;
	}
}


void un(int x,int y)
{
	
	if(find(x)==NULL||find(y)==NULL)
		{
		printf("ERROR\n");
		return;		
		}

	if(find(x)==find(y))
		return;
		
	
	find(y)->parent=find(x);
	return;
}

void kruskal()
{	int i;
	for(i=0;i<n;i++)
		makeset(i);
	sort();
	
	for(i=0;i<ctr;i++)
	{
		if(find(ea[i].u)!=find(ea[i].v))
		{	un(ea[i].u,ea[i].v);
			sum+=ea[i].wt;		
		}

	}


}
void ini()
{
int i;
for(i=0;i<n;i++)
	{
		v[i]=NULL;
	}
}

void main()
{	int i=0,x;
	char ch;
	
	
		
	scanf("%d",&n);
	ini();
	ini();
	
	while(i<n)
	{
		scanf("%d",&x);
		ea[ctr].u=i;
		ea[ctr].v=x;
		ch=getchar();
		ctr++;
		if(ch=='\n')
			i++;
	}

	i=0;int j=0;
	while(i<n)
	{
		scanf("%d",&x);
		ea[j].wt=x;
		ch=getchar();
		j++;
		if(ch=='\n')
			i++;
	}
	ini();
	kruskal();
	printf("%d",sum);

}



