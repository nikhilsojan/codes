#include<stdio.h>
#include<stdlib.h>

int c1=0,c2=0,c3=0,c4=0;

struct dis
{
int data;
int rank;
struct dis *par;
};
typedef struct dis *disj;

disj h1[10000];
disj h2[10000];
disj h3[10000];
disj h4[10000];





void makeset(int x)
{
disj m1,m2,m3,m4;
m1=(disj)malloc(sizeof(disj));
m2=(disj)malloc(sizeof(disj));
m3=(disj)malloc(sizeof(disj));
m4=(disj)malloc(sizeof(disj));

	m1->data=x;
	m1->rank=0;
	m1->par=m1;


	m2->data=x;
	m2->rank=0;
	m2->par=m2;


	m3->data=x;
	m3->rank=0;
	m3->par=m3;

	m4->data=x;
	m4->rank=0;
	m4->par=m4;

	printf("%d\n",x);
	h1[x]=m1;
	h2[x]=m2;
	h3[x]=m3;
	h4[x]=m4;
}

disj find1(disj f)
{
	
	while(f->par!=f)	
	{
		f=f->par;
		++c1;
		
	}	
++c1;

	return f;
}

disj find11(disj f)
{
	
	while(f->par!=f)	
	{
		f=f->par;
		++c2;
		
	}	
++c2;

	return f;
}

disj find2(disj x)
{
++c3;
	if(x->par!=x)
		x->par=find2(x->par);
	
	return x->par;
	
}

disj find22(disj x)
{
++c4;
	if(x->par!=x)
		x->par=find22(x->par);
	
	return x->par;
	
}

int union1(disj x,disj y)
{
	disj u1,u2;
	u1=find1(x);
	u2=find1(y);

	if(u1==u2)
		printf("%d ",u1->data);

	else if(u1!=u2)
	{
		u2->par=u1;
		printf("%d ",u1->data);
	}

}

int union3(disj x,disj y)
{
	disj u1,u2;
	u1=find2(x);
	u2=find2(y);

	if(u1==u2)
		printf("%d ",u1->data);

	else if(u1!=u2)
	{
		u2->par=u1;
		printf("%d ",u1->data);
	}

}

void union2(disj x,disj y)
{
	disj u1,u2;
	u1=find11(x);
	u2=find11(y);
	if(u1==u2)
	{  	
		
		printf("%d ",u1->data);
	}
	else if(u1!=u2)
	{
		if(u1->rank>=u2->rank)
		  u2->par=u1;
		else
		  u1->par=u2;
		if(u1->rank==u2->rank)

			u1->rank++;
		
		printf("%d ",(u1->par)->data);
	}
	


}

void union4(disj x,disj y)
{
	disj u1,u2;
	u1=find22(x);
	u2=find22(y);
	if(u1==u2)
	{  	
		
		printf("%d ",u1->data);
	}
	else if(u1!=u2)
	{
		if(u1->rank>=u2->rank)
		  u2->par=u1;
		else
		  u1->par=u2;
		if(u1->rank==u2->rank)

			u1->rank++;
		
		printf("%d ",(u1->par)->data);
	}

}

void main()
{
char ch;
int l1,l2;
while(1)
{
scanf("%c",&ch);

if(ch=='m')
{	
	scanf("%d",&l1);
	makeset(l1);
}
else if(ch=='f')
{	
	scanf("%d",&l1);

	if(h1[l1]==NULL)
	{
		printf("NOT FOUND\n");
	}
	else
	{
		
		disj r=h1[l1];
		r=find1(r);
		printf("%d ",r->data);
		 		

		
		r=h2[l1];
        	r=find11(r);
		printf("%d ",r->data);
				
		
		r=h3[l1];
		r=find2(r);
		printf("%d ",r->data);

		r=h4[l1];
		r=find22(r);
		printf("%d ",r->data);
		
	printf("\n");

			
	}
		
	
}

else if(ch=='u')
{	
	disj k1,k2;	
	scanf("%d",&l1);
	scanf("%d",&l2);
	if(h1[l1]==NULL||h1[l2]==NULL)
	
	printf("ERROR\n");	
	else
	{	
	k1=h1[l1];
	k2=h1[l2];
	union1(k1,k2);
	

	
	k1=h2[l1];
	k2=h2[l2];	
	union2(k1,k2);
	
		
	k1=h3[l1];
	k2=h3[l2];
	union3(k1,k2);
	

	k1=h4[l1];
	k2=h4[l2];
	union4(k1,k2);
	printf("\n");
	}
}
else if(ch=='s')
{printf("%d %d %d %d",c1,c2,c3,c4);
return ;
}
}
}
