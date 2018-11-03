#include<stdio.h>
#include<string.h>
#include<ctype.h>

long array[10000];
char c[10000][100000];
long top=0;
long j=0;
long count=0;

void pusha(long n)
{

top++;
char ch;
array[top]=n;

c[top][count]='\0';
while(count!=0)
{
ch=n%10;
n=n/10;
ch+='0';
c[top][count-1]=ch;
count--;
}
}

void popall(char ch)
{
long top1=top;
char a[1000000];
strcpy(a,c[top]);

strcat(a,"\0");
top1--;
j=strlen(c[top1]);
c[top1][j]=ch;
c[top1][j+1]='\0';

strcat(c[top1],a);

}

void popandchange(long ch)
{
long a=array[top];
top--;
long b=array[top];
if(ch=='+')
array[top]=a+b;
else if(ch=='-')
array[top]=b-a;
else if(ch=='*')
array[top]=b*a;
else if(ch=='/')
array[top]=b/a;
else if(ch=='^')
{
array[top]=1;
while(a!=0)
{
array[top]=array[top]*5;
a--;
}
}
}



void main()
{

long i=0;
char ch;
long n=0;

char ch1='a';
while(1)
{
scanf("%c",&ch);

if(ch!='\n')
{

if(ch==' '&&isdigit(ch1))
{
pusha(n);
n=0;
count=0;
}


else if(ch=='*'||ch=='+'||ch=='-'||ch=='/'||ch=='^')
{
popall(ch);
popandchange(ch);
}


else if(isdigit(ch))
{

ch-='0';
n=n*10+ch;
ch+='0';
count++;
}

ch1=ch;

}
else
break;
}


puts(c[top]);
printf("%ld",array[top]);



}



