#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include<string.h>

int n,distance[10000],queue[10000],key[1000],ctr=0,front=0,sum=0,rear=-1;
int f=0,mar[10000];

struct list
{
int data;
int h;
int wt;
struct list *next;
}*a[10000];

typedef struct list *ls;

ls create()
{
ls temp=(ls)malloc(sizeof(ls));
temp->next=NULL;
return temp;
}

/*void min_heapify(int i)
{
    int min=i;
    int left=2*i +1;
    int right=2*i +2;
    if(left<=rear && distance[queue[left]]<distance[queue[min]]) min=left;
    if(right<=rear && distance[queue[right]]<distance[queue[min]]) min=right;
    if(min!=i)
    {
        int temp=queue[i];
        queue[i]=queue[min];
        queue[min]=temp;
        min_heapify(min);
    }
}
*/
int min()
{

int i,k;
   int min = INT_MAX, min_index;
 
   for (int i = 0; i < n; i++)
     if (mar[i]==1&&a[i]->h == 0&&distance[i] < min)
	{        min = distance[i];
		
		k=i;	
	}
	mar[k]=0;
--ctr;

   return k;
}



/*int parent(int i)
{
    if((i%2)==0)
    return (i-2)/2;
    else 
    return (i-1)/2;
}

void enq(int x)
{
    queue[++rear]=x;
    int i=rear;
    while(i>0 && distance[queue[parent(i)]]>distance[queue[i]])
    {
        int temp=queue[parent(i)];
        queue[parent(i)]=queue[i];
        queue[i]=temp;
        i=parent(i);
    }
}
int deq()
{
    int x=queue[0];
    queue[0]=queue[rear];
    rear--;
    min_heapify(0);
    return x;
}
*/
void prim(int v)
{


    int i,x;
   ctr=n;
      //en(v);
      for(i=0;i<n;i++)
	   distance[i]=INT_MAX;
      distance[v]=0;
	mar[v]=1;
	while(ctr!=0)
	   {

	v=min();
	

printf("%d ",v);

	a[v]->h=1;
     	ls t=a[v];
        while(t!=NULL)
       {
        
            if(a[t->data]->h==0)
           {//printf("%d ",t->data);  
            x=t->wt;
		 
	          if(x<distance[t->data])
           	 {
		distance[t->data]=x;
		//printf("%d   ",distance[t->data]);
             	//sum+=distance[t->data];
		//printf("%d ",sum);
		}
	
	
		mar[t->data]=1;	
          }
	
           t=t->next;
	

       }
   
}

}




void main()
{
int i;
int num=0;

int te;
char ch;
ls t;

for(i=0;i<10000;++i)
{a[i]=NULL;
}
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

num=0;
c=0;
for(i=0;i<n;++i)
{
c=0;
t=a[i];
num=0;
while(1)
{
c++;
scanf("%c",&ch);

if(ch==' ')
	{
	t->wt=num;
	num=0;

	t=t->next;
	}
else if(ch=='\n')
	{if(c!=1)
	{t->wt=num;
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


}
for(i=0;i<10000;++i)
{if(a[i]!=NULL)
a[i]->h=0;
mar[i]=0;
}

for(i=0;i<1000;++i)
key[i]=0;
int su=0;
prim(0);
for(i=0;i<n;++i)
su+=distance[i];
printf("%d\n",su);


}

