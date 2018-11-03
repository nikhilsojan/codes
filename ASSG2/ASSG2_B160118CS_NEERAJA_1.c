#include<stdio.h>
#include<stdlib.h>

#include<limits.h>

int mul(long a,long b)
{

  if(a%b==0)
      return a/b;
 else 
     return (a/b)+1;
}




void merge(long a[],long mid1,long mid2,long p,long q)
{
	
	long b[mid1-p+2];
	long c[mid2-mid1+1];
	long d[q-mid2+1];

long i,j;
	
	for(i=0;i<=mid1-p;++i)
	b[i]=a[i+p];
	for(i=0;i<=mid2-mid1-1;++i)
	c[i]=a[i+mid1+1];
	for(i=0;i<=q-mid2-1;++i)
	d[i]=a[i+mid2+1];
b[mid1-p+1]=INT_MAX;

c[mid2-mid1]=INT_MAX;
d[i]=INT_MAX;
 



	i=0;
        j=0;
	long k=0;
        long l;
	for(l=p;l<=q;++l)
	 {
	  if(b[i]<c[j])
	  {
	   if(b[i]<d[k])
             {a[l]=b[i];
	         i++;}
	      else
		{a[l]=d[k];k++;}
	   }
	   
	  
	else
	    {
	     if(c[j]<d[k])
		
		  {a[l]=c[j];j++;}
		else{a[l]=d[k];k++;}	
		}
	     
	   
	  }
}



void mergesort(long a[],long p,long q)
{
	
	 if(p<q)
	{
	 long mid1=p+mul(q-p+1,3)-1;
	 long mid2=q-mul(q-p+1,3);
	  
	  mergesort(a,p,mid1);
	  mergesort(a,mid1+1,mid2);
	  mergesort(a,mid2+1,q);
        
	merge(a,mid1,mid2,p,q);
	}
}

void main()
{
	FILE *fptr;
	fptr=fopen("in","r");
	if(fptr==NULL)
	{printf("file can't be opened");
	exit(0);
	}
	long a[1000000];
	long n;
	long i=0;
	while(fscanf(fptr,"%ld",&a[i])!=EOF)
	{
		i++;
	}
	n=i-1;
	mergesort(a,0,n);
 fclose(fptr);
fptr=fopen("out","w");
for(i=0;i<=n;++i)
fprintf(fptr,"%ld ",a[i]);
fclose(fptr);

//for(i=0;i<=n;++i)
//printf("%ld ",a[i]);

}
