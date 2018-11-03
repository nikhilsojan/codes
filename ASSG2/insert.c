#include<stdio.h>

 void insort(int a[])
{
	long key,i,j;
	for(j=1;j<5;++j)
	{
	 key=a[j];
	 i=j-1;
	 while(i>=0&&a[i]>key)
	{
	 a[i+1]=a[i];
	  i=i-1;
	}
	a[i+1]=key;
	}
}


int main()
{
	//long int len,i,c=0;
	//scanf("%ld",&len);
	int i;
	 int a[]={1,5,2,6,9};

	//for(i=0;i<5;i++)
        //scanf("%ld",&a[i]);

       
        insort(a);
        for(i=0;i<5;i++)
            printf("%d ",a[i]);
return 0;
}

