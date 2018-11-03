#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 struct bst{

int data;
struct bst *left;
struct bst *right;

}*bt;

typedef struct bst *bstt;

bstt insert(struct bst *r,struct bst *p)
{
if(r==NULL)
return p;
else if(p->data>r->data)
{
r->right=insert(r->right,p);
return r;
}
else
{r->left=insert(r->left,p);
return r;
}
}

bstt maxm(bstt r)
{
 if(r==NULL)
return NULL;
if(r->right==NULL)
return r;
else
return maxm(r->right);

}

bstt minm(bstt r)
{
 if(r==NULL)
return NULL;

 
if(r->left==NULL)
return r;
else
return minm(r->left);
}



void inor(bstt bt)
{
if(bt!=NULL)
{
inor(bt->left);
printf("%d ",bt->data);
inor(bt->right);
}
}

void prer(bstt bt)
{
if(bt!=NULL)
{

printf("%d ",bt->data);
prer(bt->left);
prer(bt->right);
}
}

bstt search(bstt p,int elem)
{
if(p==NULL)
return p; 

if(p->data==elem)
return p;
else if(p->data<elem)
return search(p->right,elem);
else 
return search(p->left,elem);
}

void post(bstt bt)
{
if(bt!=NULL)
{

post(bt->left);
post(bt->right);
printf("%d ",bt->data);
}

}

bstt pred(bstt bt,int elem)
{

bstt q=bt;
bstt lr=NULL;
bstt par=bt;

if(par->data<elem)
{
q=par->right;
lr=par;
}
else if(par->data>elem)
q=par->left;
while(q->data!=elem)
{
if(elem<=q->data)
{
par=q;
q=q->left;
}
else
{
lr=q;
par=q;
q=q->right;
}
}
if (q->left==NULL)
return lr;
else
return(maxm(q->left));
}

bstt succ(bstt bt,int elem)
{

bstt q=bt;
bstt ll=NULL;
bstt par=bt;

if(par->data<elem)
{
q=par->right;
}
else if(par->data>elem)
{
q=par->left;
ll=par;
}
while(q->data!=elem)
{
if(elem<q->data)
{
ll=q;
par=q;
q=q->left;
}
else
{
par=q;
q=q->right;
}
}
if(q->right==NULL)
return ll;
else
return (minm(q->right));
}


bstt delete(bstt q,bstt p)
{
bstt r;
bstt x;

if(p->data<q->data)
q->left=delete(q->left,p);
else if(p->data>q->data)
q->right=delete(q->right,p);

else 
{
	if(q->right==NULL)
	{
	r=q->left;
	q->left=NULL;
	return r;
	}
	else if(q->left==NULL)
	{
	r=q->right;
	q->right=NULL;
	return r;
	}

	else
	{
	r=q->right;
	if(r->left==NULL)
	{
	x=q->left;
	q->left=NULL;
	r->left=x;
	return r;
	}
	else
	{
	x=r->left;
	while(x->left!=NULL)
	{
		r=x;
		x=x->left;
	}
	x->left=q->left;
	q->left=NULL;
	r->left=x->right;
	x->right=q->right;
	return x;
}
}
}
}



bstt delt(bstt bt,int elem)
{
bstt q;
bstt p=search(bt,elem);
q=bt;
bt=delete(q,p);
return bt;
}



void main()
{

bstt temp;
int i;
char ch[4];
int elem;

while(1)
{

scanf("%s",ch);


if(strcmp("srch",ch)==0)
{
scanf("%d",&elem);
temp=search(bt,elem);
if(temp!=NULL)
printf("FOUND\n");
else
printf("NOT FOUND\n");
}



 if(strcmp("minm",ch)==0)
{

temp=minm(bt);
if(temp!=NULL)
printf("%d\n",temp->data);
else 
printf("NIL\n");


}

 if(strcmp("maxm",ch)==0)
{
temp=maxm(bt);
if(temp!=NULL)
printf("%d\n",temp->data);
else 
printf("NIL\n");

}




if(strcmp("pred",ch)==0)
{
scanf("%d",&elem);
if(bt==NULL)
printf("NOT FOUND\n");
else
{
temp=minm(bt);
if(elem==temp->data)
printf("NIL\n");
else
{
temp=pred(bt,elem);
if(temp!=NULL)
printf("%d\n",temp->data);
}
}
}

if(strcmp("succ",ch)==0)
{
scanf("%d",&elem);
if(bt==NULL)
printf("NOT FOUND\n");
else
{
temp=maxm(bt);
if(elem==temp->data)
printf("NIL\n");
else
{
temp=succ(bt,elem);
if(temp!=NULL)
printf("%d\n",temp->data);
}
}
}

 if(strcmp("insr",ch)==0)
{
scanf("%d",&elem);

temp=(struct bst*)malloc(sizeof(struct bst));
temp->data=elem;

bt=insert(bt,temp);

}

if(strcmp("inor",ch)==0)
{inor(bt);
printf("\n");
}
 if(strcmp("prer",ch)==0)
{
prer(bt);
printf("\n");
}
if(strcmp("post",ch)==0)
{post(bt);
printf("\n");
}
 if(strcmp("delt",ch)==0)
{scanf("%d",&elem);
if(bt!=NULL)
 
bt=delt(bt,elem);
}
if(strcmp("stop",ch)==0) return ;
}

}
