#include<stdio.h>
#include<stdlib.h>
long c=0;
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
{        long int k=par(a,p,r);
	if(k==centre)
            return centre;
        if(k>centre)
             median(a,p,k-1,centre);
         else 
             median(a,k+1,r,centre);

}




void sort(long a[],long int p,long int r)
{long int q,centre,n;
        n=r-p+1;
   	if(n%2==0)
             centre=p+(n/2)-1;
        else 
           centre=p+(n/2);

	if(p<r)
	{
		q=median(a,p,r,centre);
                if(c<3)
                {printf("%ld\n",a[q]);c++;}
                sort(a,p,q-1);
               	sort(a,q+1,r);
                


	}
}




int main()
{
	long int len,i;
	scanf("%ld",&len);
	long int a[len];

	for(i=0;i<len;i++)
        	scanf("%ld",&a[i]);

       
        sort(a,0,len-1);
        for(i=0;i<len;i++)
            printf("%ld ",a[i]);
        }

