#include<stdio.h>
long start=1;
long end=1;
int cap;

int cap1;
long array[1000];

////////////////////doubt
void enqueue(long num)
{

if(((end+1)%(cap))==start)
{

printf("-2\n");
return ;

}

array[end]=num;
//printf("%ld",end);
end=(end+1)%(cap);

}

long dequeue()
{
//printf("%ld",end);
if(start==end)
return -1;
else
{
int p=array[start];
start=(start+1)%cap;
return p;

}
}
void print_queue()
{
long i;
if(start==end)
{
printf("-1");
return;
}

if(start>end)
{
for(i=start;i<cap;++i)
printf("%ld ",array[i]);
for(i=0;i<end;++i)
printf("%ld ",array[i]);
printf("\n");

}
else
{

for(i=start;i<end;++i)
printf("%ld ",array[i]);
printf("\n");

}

}







void main()
{

scanf("%d",&cap);
cap1=cap;
cap++;

char ch;
long num,del;

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
	print_queue();
	}
}
return;
}

