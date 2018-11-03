#include<stdio.h>



long partition(long *a,long p,long r)

{ 
	long x,i,j;
	x=a[r];
	i=p-1;
	
	for(j=p;j<r;j++)
	{
	 if(a[j]<=x)
	  {
	    i++;
	    a[i]=a[i]+a[j];
	    a[j]=a[i]-a[j];
	    a[i]=a[i]-a[j];
	  }
}
	a[i+1]=a[i+1]+a[r];
        a[r]=a[i+1]-a[r];
        a[i+1]=a[i+1]-a[r];
	
return i+1;
}
		
          






long int median(long int *a,long int p,long int r,long int centre)
{
long int k;
k=partition(a,p,r);

if(k==centre)
	return centre;
if(k<centre)
	median(a,k+1,r,centre);
else
	median(a,p,k-1,centre);



}



void quicksort(long *a,long p,long r,int c)
	
{
	long int m,k,centre;
	k=r-p+1;
	if(k%2==0)
	centre=p+(k/2)-1;
	else
	centre=p+(k/2);

	  if(p<r)
		{

		
		m=median(a,p,r,centre);
		
		if(c<2)
		printf("%ld\n",a[m]);
		//t=a[m];
		//a[m]=a[r];
		//a[r]=t;
	       
		
		
		quicksort(a,p,m-1,c+1);
		quicksort(a,m+1,r,c+1);
	  	}
}







void main()
{
long int l;
scanf("%ld",&l);
if (l==0)
return ;
 long int a[l],i;
for(i=0;i<l;++i)
scanf("%ld",&a[i]);


quicksort(a,0,l-1,0);
//printing
for(i=0;i<l;i++)
printf("%ld ",a[i]);

}



