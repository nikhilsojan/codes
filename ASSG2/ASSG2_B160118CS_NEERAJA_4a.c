#include<stdio.h>
void main()
{
 long a,b;
 scanf("%ld%ld",&a,&b);
int flag=-1;
 long c[a][b];
 long i,j;
for(i=0;i<a;++i)
 for(j=0;j<b;++j)
   scanf("%ld",&c[i][j]);
 long d;

scanf("%ld",&d);
i=0;
j=b-1;
if(d==c[i][j])
  flag=1;
else if(d>c[i][j])
{ i++;
  while(i+j<(a+b-1))
  { if(d>c[i][j])
    i++;
   if(d<c[i][j])
    j--;
   if(d==c[i][j])
    {flag= 1;break;}
 }  
}
 else
 {j--;
   while(i+j>=0)
   {
    if(d>c[i][j])
      i++;
    if(d<c[i][j])
      j--;
    if(d==c[i][j])
      {flag=1;
	break;
      }
  }
}
printf("%d",flag);
}
