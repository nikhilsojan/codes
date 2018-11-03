#include<stdio.h>
void main()

{
	long a;
	scanf("%ld",&a);
	long c[a];
	long i;
	
	for(i=0;i<a;++i)
	 scanf("%ld",&c[i]);
	
	long e;
	 scanf("%ld",&e);
	long l=0;
	int flag=-1;
	long u=a;
	long mid;
	while(l<=u)
	{
	 mid =(l+u)/2;
	
	 if(c[mid]==e)
		{printf("%ld",mid);
		 flag=1;
		 return;
		}
  	else if(c[l]<=c[mid])
		{ 
		  if(c[mid]<e)
			{l=mid+1;
			
			}
	          else u=mid-1;
		}
	
	else 
	       {
	   	    if(c[mid]<e)
	    		{
			 if(e>c[u-1])
			  { u=mid-1;
			   
			   }
	   		  else l=mid+1;
			 }
	       	    else
			  u=mid-1;
		}
	
	}   
printf("%d",flag);
	
	}
