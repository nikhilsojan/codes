#include<stdio.h>

void max(long a[],long i,long len)
	{
	long largest=i;

	 long l=2*i+1;
	 long r=2*i+2;
	
	 if(l<len&&a[l]>=a[i])
	    largest=l;
	if(r<len&&a[r]>=a[largest])
	   largest=r;
	   
	if(largest!=i)
	   {
	    a[i]=a[i]+a[largest];
	    a[largest]=a[i]-a[largest];
	    a[i]=a[i]-a[largest];
		
	 max(a,largest,len); //also works without this but include the other commented portion and comment the line above that
	  }
	}
	    

void build(long a[], long l)
	{
	long i=(l-1)/2; 
	for(;i>=0;--i)  
	 max(a,i,l);
	}


void heapsort(long a[],long l,long k)
{
	build(a,l);
long var,temp;
	long i;
	for(i=l-1;k>0;i--,k--)
	{temp=a[0];
	a[0]=a[i];
	a[i]=temp;
	 l--;
	
	max(a,0,l);
//	build(a,l);
if(i!=l-1&&var==a[i])
k++;
var =a[i];
	}
 printf("%ld",a[i+1]);
}	  
void main()
{	
	long l;

	scanf("%ld",&l);
	
	
	long c[l];
	long i;
	for(i=0;i<l;++i)
	scanf("%ld",&c[i]);

	long k;
	scanf("%ld",&k);

	heapsort(c,l,k);
 //       printf("%ld",c[0]);

}

