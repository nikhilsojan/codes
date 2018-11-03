#include<stdio.h>
#include<stdlib.h>
void simplest(int a,int b)
{	int min;
	int hcf;
	int flag1=0;
	int flag2=0;
	if(a==0)
	{	
	printf("%d/1",a);
	return;
	}
	if(a<0)
   		{a=-1*a;
		flag1=1;}
	
	if(b<0)
		{b=-1*b;
		flag2=1;}
	if(a<b)
	min=a;
	else min=b;
	int i;
	
	for(i=1;i<=min;++i)
	{
	if((a%i==0)&&(b%i==0))
	hcf=i;
	}
	if(flag1==1&&flag2==1)
		printf("%d/%d",a/hcf,b/hcf);
	  else if(flag1==1||flag2==1)
		printf("%d/%d",(-1*a/hcf),b/hcf);
	     else    printf("%d/%d",a/hcf,b/hcf);
}
		

struct ratio{
int x;
int y;
};
void main()
{

int a,b,n;
struct ratio t;
//printf("1. Print a/b form\n"); print a/b
//printf("2. Sum of Rational Numbers\n");
//printf("3. Product of Rational Number\n");
//printf("4. Sort in ascending order\n");
//printf("5. Print in Simplest form\n");
//printf("Choose your option\n");
scanf("%d",&n);
if(n==1)
{
//printf("Enter a and b\n");
scanf("%d",&t.x);
scanf("%d",&t.y);
if(t.y==0)
{printf("not possible");
exit(0);
}
simplest(t.x,t.y);
}
else if(n==2)
	{
	 struct ratio m,n;
	// printf("Enter a and  b");
	 scanf("%d%d",&m.x,&m.y);
	// printf("Enter a and b");
	 scanf("%d%d",&n.x,&n.y);
	if(m.y==0||n.y==0)
	{printf("not possible");
	exit(0);
	}	

	 int a=(m.x*n.y)+(m.y*n.x);
	 int b= n.y*m.y;
	// printf("%d/%d",a,b);
	 simplest(a,b);
	}

	
else if(n==3)
	{
	struct ratio p,q;
	//printf("Enter a and  b");
         scanf("%d%d",&p.x,&p.y);
         //printf("Enter a and b");
         scanf("%d%d",&q.x,&q.y);
	if(p.y==0||q.y==0)
 	{printf("not possible");
	exit(0);
	}

	int a=p.x*q.x;
	int b=p.y*q.y;
        //printf("%d/%d",a,b);
	 simplest(a,b);
	}
else if(n==4)
	{int s;
	
         //printf("Number of rational numbers to be sorted:");
	scanf("%d",&s);
	if(s<0)
	{
	printf("Not Possible");
	return;
	} 
	int l=s;
	  struct ratio *h;
	h=(struct ratio*)malloc(sizeof(struct ratio*)*l);
	while(s!=0)	
	{
	// printf("Enter in the form a b:");
 	 scanf("%d%d",&h[s-1].x,&h[s-1].y);
	if(h[s-1].y==0)
	{printf("not possible");
	exit(0);
	}
	if(h[s-1].x<0&&h[s-1].y<0)
	{
	h[s-1].y*=-1;
	h[s-1].x*=-1;
	}
	if(h[s-1].y<0&&h[s-1].x>=0)
	{
	h[s-1].x*=-1;
	h[s-1].y*=-1;
	}
	s--;
	
	}
	
	
	int i,j;
	
	 struct ratio temp;
	for(i=0;i<l;++i)
	{
	 for(j=1+i;j<l;++j)
	 {
          if((h[i].x*h[j].y)>(h[j].x*h[i].y))
	     {	temp=h[i];
		h[i]=h[j];
		h[j]=temp;
               
	     }
}}

for(i=0;i<l;++i)
{if(l-1==i)
printf("%d/%d",h[i].x,h[i].y);
else
printf("%d/%d ",h[i].x,h[i].y);
}
}


else if(n==5)
{	struct ratio j;
//	printf("Enter a/b");
	scanf("%d%d",&j.x,&j.y);
	simplest(j.x,j.y);
}
else printf("invalid choice");
}	


