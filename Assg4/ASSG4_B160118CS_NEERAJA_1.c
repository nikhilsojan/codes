#include<stdio.h>
#include<stdlib.h>
long hash[10000];
char ch;
char ch2;
long m;

struct Node{
int data;
struct Node *next;
};
typedef struct Node *node;
node p[1000];

void HashTable(long m)
{
int i;
if(ch=='d')
{
for(i=0;i<m;++i)
{
p[i]=NULL;
}
}

else
{
for(i=0;i<m;++i)
{
hash[i]=-1;
}
}
}

long prime(long m)
{

while(1)
{
m--;
int f=0;
int i=m/2;
for(;i>1;i--)
{
if(m%i==0)
{f=1;
break;
}
}
if(f==0)
return m;

}
}
void insert(long k)
{
long l,i;

if(ch=='a')
{
i=0;

l=(k%m+i)%m;

while((i<m)&&(hash[l]!=-1)&&(hash[l]!=-2))
{
++i;
l=(k%m+i)%m;
}

if(i==m) 
{
printf("NILL");
}
else
hash[l]=k;
}

if(ch=='b')
{
i=0;

l=(k%m+i*i)%m;

while((i<m)&&(hash[l]!=-1)&&(hash[l]!=-2))
{
++i;
l=(k%m+i*i)%m;
}

if(i==m) 
{
printf("NIL");
}
else
hash[l]=k;
}


if(ch=='c')
{
i=0;
long t;
long j;
t=prime(m);
long w=k%m;
j=t-(k%t);

l=(w+(i*j))%m;

while((i<m)&&(hash[l]!=-1)&&(hash[l]!=-2))
{
++i;
l=(w+(i*j))%m;
}

if(i==m) 
{
printf("NIL");
}
else
hash[l]=k;
}

if(ch=='d')
{
l=k%m;
node t1=p[l];

node temp=(node)malloc(sizeof(node));
temp->data=k;

temp->next=NULL;

if(t1==NULL)
p[l]=temp;
else
{
while(t1->next!=NULL)
t1=t1->next;

t1->next=temp;

}
}
}


void search(long k)
{
int l,i;

if(ch=='a')
{
i=0;
l=(k%m+i)%m;

while((i<m)&&(hash[l]!=k)&&hash[l]!=-1)
{
++i;
l=(k%m+i)%m;
}
if(hash[l]==k)
printf("1\n");
else
printf("-1\n");
}

if(ch=='b')
{
i=0;
l=(k%m+i*i)%m;

while((i<m)&&(hash[l]!=k)&&hash[l]!=-1)
{
++i;
l=(k%m+i*i)%m;
}
if(hash[l]==k)
printf("1\n");
else
printf("-1\n");
}


if(ch=='c')
{
long t=prime(m);
i=0;
long j=t-(k%t);
long w=k%m;
l=(w+(i*j))%m;

while((i<m)&&(hash[l]!=k)&&hash[l]!=-1)
{
 

++i;

l=(w+(i*j))%m;
}
if(hash[l]==k)
printf("1\n");
else
printf("-1\n");
}
if(ch=='d')
{
l=k%m;

node t1=p[l];
if(t1!=NULL)
{
while(t1->data!=k&&t1->next!=NULL)
t1=t1->next;

if(t1->data==k)
printf("1\n");
else
printf("-1\n");
} 
else
printf("-1\n");
}

}




void del(long k)
{
int l,i;
if(ch=='a')
{
 i=0;
l=(k%m+i)%m;
while((i<m)&&(hash[l]!=k))
{
++i;
l=(k%m+i)%m;
}
if(hash[l]==k)
hash[l]=-2;
else
printf("error\n");
}

if(ch=='b')
{
 i=0;
l=(k%m+i*i)%m;
while((i<m)&&(hash[l]!=k))
{
++i;
l=(k%m+i*i)%m;
}
if(hash[l]==k)
hash[l]=-2;
else
printf("error\n");
}

if(ch=='c')
{
long t=prime(m);
 i=0;
long j=t-(k%t);
long w=k%m;
l=(w+(i*j))%m;
while((i<m)&&(hash[l]!=k))
{
t=prime(m);
++i;
l=(w+(i*j))%m;
}
if(hash[l]==k)
hash[l]=-2;
else
printf("error\n");
}
if(ch=='d')
{
l=k%m;

node t1=p[l];
if(t1!=NULL)
{

if(t1->next==NULL)
p[l]=NULL;
else
{
while((t1->next)->data!=k&&(t1->next)->next!=NULL)
t1=t1->next;

if((t1->next)->data==k&&(t1->next)->next!=NULL)
(t1->next)=(t1->next)->next;

if((t1->next)->data==k&&(t1->next)->next==NULL)
t1->next=NULL;

}
}
}

}


void print()
{
int i=0;
if(ch=='d')
{
node t;
for(i=0;i<m;++i)
{
printf("%d",i);
t=p[i];
if(t==NULL)
printf("()\n");
else
{
printf("(");

while(t!=NULL)
{
printf("%d",t->data);
if(t->next==NULL)
break;
else
printf(" ");

t=t->next;
}
printf(")\n");

}

}
}
else
{
for(i=0;i<m;++i)
{
if(hash[i]==-1||hash[i]==-2)
printf("%d()\n",i);

else
printf("%d(%ld)\n",i,hash[i]);

}
}
} 




void main()
{

long int k;
scanf("%c",&ch);
long t;

scanf("%ld",&m);

HashTable(m);

while(1)
{
scanf("%c",&ch2);


if(ch2=='t')
  return ;

else if(ch2=='s')
{
scanf("%ld",&k);
search(k);
}


else if(ch2=='i')
{
scanf("%ld",&k);
insert(k);
}



else if(ch2=='d')
{
scanf("%ld",&k);
del(k);
}



else if(ch2=='p')
print();

}
}





