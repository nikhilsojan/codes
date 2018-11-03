#include<stdio.h>
#include<stdlib.h>
struct nod
{
long int val;
struct nod *next;
};
 int bb=0;
typedef struct nod *node;
int g=0;

node createnod()
{
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct nod));
	
 // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}

node reverse(node p)
{
if(p->next==NULL||p==NULL)
	return p;
node q,r;
q=p->next;

r=reverse(q);
q->next=p;
p->next=NULL;
return r;
}


node print(node p)
{

while(p->next!=NULL)
{


printf("%ld",p->val);
p=p->next;
}
}

node difference_of_digits(node r1,node r2)
{

int  dif;
node temp;
if(r1!=NULL)
{
if(r1->val!=r2->val)
{
if(g==0)
{
if(r1->val>r2->val)
g=1;
else
{
temp=r1;
r1=r2;
r2=temp;
if(r1->val>r2->val)
g=1;
}
}
}
difference_of_digits(r1->next,r2->next);

if(bb==1)
r1->val-=1;

dif=(r1->val)-(r2->val);


//printf("%d ",dif);
if(dif<0)
{
dif+=10;
bb=1;
}
else bb=0;

r1->val=dif;
r2->val=dif;
}

else return r1;
}


void main()
{
char n1,n2;
int c1,c2;
c1=0;
c2=0;

node p1,p2;
node t1,t2;
p1=(node) malloc((sizeof(struct nod)));
t1=p1;
char c;

while(1)
{
scanf("%c",&n1);

//rem=n1%10;


if(n1=='\n')
break;

n1-='0';
p1->val=n1;



p1->next=createnod();
p1=p1->next;
}




p2=(node)malloc((sizeof(struct nod)));
t2=p2;

while(1)
{
scanf("%c",&n2);

if(n2=='\n')
break;

n2-='0';
p2->val=n2;


p2->next=createnod();
p2=p2->next;

}




int flag=0;

node pri=difference_of_digits(t1,t2);


node pr=print(pri);
}


