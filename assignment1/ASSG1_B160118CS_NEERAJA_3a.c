#include<stdio.h>
#include<stdlib.h>
void reverse(char *c,int n,int i)
{
char temp;
 if(n==i)
	printf("%s",c);
else if (i>n)
  	printf("%s",c);
   else

     {

        temp=*(c+i);
        *(c+i)=*(c+n-1);
        *(c+n-1)=temp;
        reverse(c,n-1,i+1);

     }
}

void main()
{
char *str,c;
int i=0,j=1;
str = (char*)malloc(sizeof(char));
while(c!='\n')

{
c= getchar();
str = (char*)realloc(str,j*sizeof(char));
str[i]=c;
i++;j++;
}
str[i]='\0';
reverse(str,i-1,0);



}


