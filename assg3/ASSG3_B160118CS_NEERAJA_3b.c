#include<stdio.h>
#include<stdlib.h>
struct nod
{
long int val;
struct nod *next;
};

typedef struct nod *node;

 node tail=NULL;
node head=NULL;
node t;
node createNode()
{
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct nod));
	
 // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}


void enqueue(long num)
{
node q=createNode();
q->val=num;
if(tail==NULL)
{
tail=q;
head=q;
}
else
{
tail->next=q;
tail=q;
}
}

long dequeue()
{
node p;
if(head==NULL)

{
return -1;
}
else
{
if(head==tail)
{ p=head;
head=NULL;
tail=NULL;
return p->val;
}

else
{
p=head;
head=p->next;
p->next=NULL;
return p->val;
}
}
}

void print_queue()
{
if(t==NULL)
printf("-1\n");

while(t!=NULL)
{
printf("%ld ",t->val);
t=t->next;
}
printf("\n");

}




void main()
{

node p;


char ch;
long num;
long del;
while(1)
{
	scanf("%c",&ch);

	
	if(ch=='s')
	return ;

	if(ch=='e')
	{
//	printf("%c",ch);
	scanf("%ld",&num);
	
	enqueue(num);
	
	}

	if(ch=='d')
	{del=dequeue();
	printf("%ld\n",del);

	}

	if(ch=='p')
	{
	t=head;
	print_queue();
	}
}
}
