#include<stdio.h>
#include<stdlib.h>
void transpose(int *c,int n,int i,int j)
 {
 int temp;
 if(i>n-1)
   {
    return;
   }
 else if(j>n-1)
 {
      transpose(c,n,i+1,0);

 }


  else if(j>i)
   {
     *(c+n*i+j)+=*(c+n*j+i);
     *(c+n*j+i)= *(c+n*i+j)-*(c+n*j+i);
     *(c+n*i+j)-=*(c+n*j+i);
     transpose(c,n,i,j+1);
   }
  else {transpose(c,n,i,++j);
}
}
void spiral(int *c,int n)
  {
   int k,l;
int p=0;int r=0;

while(p<n&&r<n)
{
   for(k=p;k<n-p;++k)
    printf("%d ",*(c+n*p+k));

    for(l=1+r;l<n-r;++l)
    printf("%d ",*(c+n*l+(n-1-r)));

    for(k=n-2-p;k>=p;--k)
    printf("%d ",*(c+n*(n-1-p)+k));

    for(l=n-2-r;l>=1+r;--l)
    printf("%d ",*(c+n*l+r));
++r;++p;
}}
//main function
void main()
{ int *c;
int i,j,n;
scanf("%d",&n);
if(n<0)
{
printf("Not possible\n");
return;
}
c= (int*)malloc(sizeof(int*)*n*n);

for(i=0;i<n;++i)
 for(j=0;j<n;++j)
  scanf("%d",(c+n*i+j));
transpose(c,n,0,0);

/*for(i=0;i<n;++i)
 {printf("\n");
for(j=0;j<n;++j)
  printf("%d ",c[i][j]);
}*/
//printf("\n");
spiral(c,n);
}
