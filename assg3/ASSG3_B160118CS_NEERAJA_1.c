#include<stdio.h>
#include<stdlib.h>
struct nod
{
long int val;
struct nod *next;
};

typedef struct nod *node;

node createNode()
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

while(p!=NULL)
{
//if((p==NULL))//||p->next==NULL)

//return p;

printf("%ld ",p->val);
p=p->next;
}
}
/////////////////main

void main()
{
char ch;
long int n;

node p;
p = (node)malloc(sizeof(struct nod));
node p1;

p1=p;
while(1)
{

scanf("%ld",&n);
p->val=n;

scanf("%c",&ch);

if(ch=='\n')
{
break;
}
p->next=createNode();

p=p->next;
}
 
node rev;

node p2=p1;
rev=reverse(p1);

node pri=print(rev);
}


