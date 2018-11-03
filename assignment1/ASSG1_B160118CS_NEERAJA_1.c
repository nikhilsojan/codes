#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
int c,k;
long l;
//printf("Input:\t1.Encryption\n\t2.Decrytion\n");
//printf("Enter your choice: \n");
scanf("%d",&c);
if(c!=1&&c!=2)
{printf("invalid ouput");
return 0;
}

//printf("\nEnter string length: ");
scanf("%ld",&l);
if(l<0)
{printf("not possible");
return 0;
}
char *s=(char*)malloc(sizeof(char*)*l);
//printf("\nEnter string: ");
scanf(" %[^\n]s",s);

//printf("Enter K: \n");

scanf(" %d",&k);
k%=26;
if(k<0)
{printf("invalid input");
return 0;
}
int i=0;
if(c==1)
{
for(i=0;i<l;++i)
        {if(isupper(s[i]))
              {
		int b= s[i]+k;
		if((b>90)&&(b<=116))
		s[i]=b-26;
		else
		s[i]=b;
 
              }
       
	if(islower(s[i]))
        	{   
		int b=s[i]+k;
		if((b>122)&&(b<=147))
		s[i]=b-26;
		else
		s[i]=b;
	  }
	}	
	
}
else  if(c==2)
{
for(i=0;i<l;++i)
        {if(isupper(s[i]))
              { 
                int b= s[i]-k;
                if((b>=39)&&(b<65))
                s[i]=b+26;
                else
                s[i]=b;
	      }
	if(islower(s[i]))
	{
	int b=s[i]-k;
	if((b>=71)&&(b<97))
	s[i]=b+26;
	else
	s[i]=b;

	
        }
}

}
printf("%s",s);

return 0;
}      


