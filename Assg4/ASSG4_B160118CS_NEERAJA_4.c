#include<stdio.h>
#include<stdlib.h>
long pre[1000];
long in[1000];
long s;


struct bst{

int data;
struct bst *left;
struct bst *right;

};

long i=0;
typedef struct bst *bstt;
bstt b;

bstt find(long pre[s],long in[s],long h,long k)
{
long t,j;
bstt temp;



if(h>k)
{
return NULL;
}
temp=(bstt)malloc(sizeof(struct bst));
t=pre[i];
temp->data=t;
temp->left=NULL;
temp->right=NULL;

i++; 
if(h==k)
{
return temp;
}
else 
{
for(j=h;j<=k;++j)
{
if(t==in[j])
break;

}

temp->left=find(pre,in,h,j-1);
temp->right=find(pre,in,j+1,k);
    return temp;
}
}  

void print(struct bst *b)
{
if(b==NULL)
{printf(" ( )");
return ;
} 
else
{
printf(" ( %d",b->data);
print(b->left);
print(b->right);

printf(" )");
return ;
}
}


void main()
{
long i;
scanf("%ld",&s);
for(i=0;i<s;++i)
{

scanf("%ld",&pre[i]);
}


for(i=0;i<s;++i)
{
scanf("%ld",&in[i]);
}


b=find(pre,in,0,s-1);
print(b);

}
