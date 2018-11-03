#include<stdio.h>
#include<stdlib.h>

void main()
{
FILE *fptr,*fptr2;
char ch1,ch2;
fptr= fopen("in.txt","r");
fptr2=fopen("out.txt","w");

    if (fptr==NULL||fptr2==NULL)

    {

        printf("Cannot open file \n");

        exit(0);

    }
ch2='x';
while(fscanf(fptr,"%c",&ch1)!=EOF)
{
if(ch1=='\t')
ch1=' ';
 if(ch2!=' '||ch1!=' ')
  fprintf(fptr2,"%c",ch1);
 ch2=ch1;
 
}

fclose(fptr);
fclose(fptr2);
}


