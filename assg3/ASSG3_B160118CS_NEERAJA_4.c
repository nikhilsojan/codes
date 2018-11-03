#include<stdio.h>
long heapsize=0;
long j=1;
long size=10000;
struct heap
{
long val;
long priority;
}pq[10000],temp;


long parent(long i)
{
return i/2;
}

void insert(struct  heap pq[size],long elem,long pr)
{
struct heap temp;
heapsize++;
pq[heapsize].val=elem;
pq[heapsize].priority=pr;
long i=heapsize;
long p;
//printf("%ld ",heapsize);
//printf("%ld ",pq[heapsize].priority);	
while((i>1)&&(pq[p].priority>pq[i].priority))
{
 p=parent(i);
	temp=pq[p];
	pq[p]=pq[i];
	pq[i]=temp;
	i=parent(i);
}
printf("%ld ",heapsize);
printf("%ld ",pq[j++].priority);	

}

void min_heapify(struct heap pq[size],long i)
{

long smallest;
struct heap temp;

//if(i<=heapsize)
//{
	
	if((2*i<=heapsize)&&(pq[2*i].priority<pq[i].priority))
		smallest=2*i;
	else smallest=i;

	if((2*i+1<heapsize)&&(pq[2*i+1].priority<pq[smallest].priority))
		smallest=2*i+1;

printf("%ld",smallest);

	if(smallest!=i)
		{temp=pq[smallest];
		pq[smallest]=pq[i];
		pq[i]=temp;

		min_heapify(pq,smallest);
		}
//}

}

void extract_min(struct heap pq[size])
{
if (heapsize==0)
{
	printf("EMPTY\n");
	return;
}
long x,y;
x=pq[1].val;
y=pq[1].priority;
pq[1]=pq[heapsize];
heapsize--;


printf("%ld ",x);
	printf("(%ld)\n",y);
min_heapify(pq,1);
}

void get_min(struct heap pq[size])
{
	if (heapsize==0)
{
	printf("EMPTY\n");
	return;
}

printf("%ld ",pq[1].val);
printf("(%ld)\n",pq[1].priority);
}


void decrease_priority(struct heap pq[size],long elem,long newpr)

{
	long i;
	for(i=1;i<heapsize;++i)
	{
		if(pq[i].val==elem)
		{
			break;
		}

	}

	pq[i].priority=newpr;
	i=heapsize;
	while((i>1)&&(pq[parent(i)].priority>pq[i].priority))
{
	temp=pq[parent(i)];
	pq[parent(i)]=pq[i];
	pq[i]=temp;
	i=parent(i);
}
}



void main()
{


char ch;
long elem;

long pr,newpr;

while(1)
{
	scanf("%c",&ch);

	
	if(ch=='s')
	return ;

	if(ch=='a')
	{
//	printf("%c",ch);
	scanf("%ld",&elem);
	scanf("%ld",&pr);
	insert(pq,elem,pr);
	
	}

	if(ch=='e')
	{
	extract_min(pq);
	

	}

	if(ch=='g')
	{
	get_min(pq);
	}

	if(ch=='d')
	{
	scanf("%ld",&elem);
	scanf("%ld",&newpr);
	decrease_priority(pq,elem,newpr);
	}
}
}

