#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int h[10000];

struct list
{
int data;
struct list *next;
}*a[10000];


int queue[10000],stack[10000],top=0,rear=0,front=0;

typedef struct list *ls;

ls create()
{
ls temp=(ls)malloc(sizeof(ls));
temp->next=NULL;
return temp;
}

void push(int x)
{
stack[top++]=x;
}


int empty()
{
if(top==0)return 1;
return 0;
}

void dfs(int k,int d)
{
stack[top++]=k;
  //push(k);
  h[k]=1;
while(!empty())
  {
    k=stack[--top];
    printf("%d ",k);
    if(k==d) return;
       	ls t=a[k];
      while(t!=NULL )
    {
        if(h[t->data]==0)
       { 
	stack[top++]=t->data;
	        
	//push(t->data);
        h[t->data]=1;
       }
       t=t->next;
    }
  }
}

void enq(int x)
{
    if(rear==0)
    {
        queue[rear]=x;
        queue[front]=x;
        rear++;
    }
    else
    {
        queue[rear++]=x;
    }
}


void bfs(int v,int d)
{
    enq(v);h[v]=1;
     printf("%d ",v);
   while(rear!=front)
  {
    v=queue[front++];
       
	ls t=a[v];

      while(t!=NULL )
    {
        if(h[t->data]==0)
       { 
        enq(t->data);
        printf("%d ",t->data);
        if(t->data==d) return;
        h[t->data]=1;
       }
       t=t->next;
    }
  }
}

void ini()
{
int i;
for(i=0;i<10000;++i)
	h[i]=0;

}


void main()
{
int n,i;
int num=0;

int te;
char ch;
ls t;
for(i=0;i<10000;++i)
h[i]=0;
for(i=0;i<10000;++i)
a[i]=NULL;
char cl;
int c;
scanf("%d",&n);
scanf("%c",&ch);
for(i=0;i<n;++i)
	{
	
	t=(ls)malloc(sizeof(ls));
	a[i]=t;
	num=0;
	c=0;
	while(1)
	{
	c++;
	scanf("%c",&ch);
	
	if(ch==' ')
	{
	t->data=num;
	num=0;
	t->next=create();
	t=t->next;
	}
	else if(ch=='\n')
	{if(c!=1)
	{t->data=num;
	//printf("%d",t->data);
	}
	break;
	}
	else
	{
	te=ch-48;
	num=num*10 +te;
	
	}

	}
if(ch=='\n'&&c==1)
a[i]=NULL;

	}

char s[4];
int start;
int key;
while(1)
{

scanf("%s",s);

if(strcmp(s,"bfs")==0)
{	
	ini();

	scanf("%d",&start);
	scanf("%d",&key);
	bfs(start,key);
	
	rear=0;front=0;
	printf("\n");
}
else if(strcmp(s,"dfs")==0)
{
		ini();

	scanf("%d",&start);
	scanf("%d",&key);
	dfs(start,key);
	top=0;
	printf("\n");
}
else 
return;
}
}
