#include<stdio.h>
#include<stdlib.h>

long int par(long a[],long int p,long int r)
{
	long int x=a[r];
        long int i=p-1,j,t;
	
	for(j=p;j<=r-1;j++)
	{	if(a[j]<=x)
			{i++;
 			        t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
         
         }
t=a[i+1];
a[i+1]=a[j];
a[j]=t;

return i+1;}




long int median(long a[],long int p,long int r,long int centre)
{        long s=r-p+1;
	long med;
	if(s<=5)
	{
	 insort(a,p,r)
	 if((s)%2==0)
              centre=p+(s/2)-1;
        else 
           centre=p+(s/2);
	}
	for(i=p;i<=r;i=i+4)
	{
	med=median(a,
	
}

	

void sort(long a[],long int p,long int r,long int c)
{long int q,centre,n;
        //n=r-p+1;
   	if(n%2==0)
             centre=p+(n/2)-1;
        else 
           centre=p+(n/2);

	if(p<r)
	{
		q=median(a,p,r,centre);
                if(c<2)
                {printf("%ld\n",a[q]);}
                sort(a,p,q-1,c+1);
               	sort(a,q+1,r,c+1);
                


	}
}


 void insort(long a[],long p,long q)
{
	long key,i,j;
	for(j=p+1;j<q;++j)
	{
	 key=a[j];
	 i=j-1;
	 while(i>=p&&a[i]>key)
	{
	 a[i+1]=a[i];
	  i=i-1;
	}
	a[i+1]=key;
	}
//if((q-p)%2==0)
//return (q-p)/2+1;
//else 
//return (q-p)/2
}



int main()
{
	long int len,i,c=0;
	scanf("%ld",&len);
	
	//long int a[]={1,5,2,6,9};

	for(i=0;i<len;i++)
        scanf("%ld",&a[i]);

       
   sort(a,0,len-1,c)// doubt......
        for(i=0;i<len;i++)
            printf("%ld ",a[i]);
return 0;
}

