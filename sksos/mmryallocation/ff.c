#include<stdio.h>
#include<unistd.h>
void main()
{
int i,pno,bs[90],bno,ps[90],alloct[90],j;
printf("FIRST IN FIRST OUT\n");
printf("\t\t\n enter the no of blocks\n");
scanf("%d",&bno);
printf("enter the size of each blocks \n");
for(i=0;i<bno;i++)
	{
	 printf("ENTER SIZE OF BLOCK%d\t",i+1);
	 scanf("%d",&bs[i]);
	}
printf("enter the no of processes\n");
scanf("%d",&pno);
printf("enter the size of each processes\n");
for(i=0;i<pno;i++)
	{
	 printf("ENTER SIZE OF P%d\t",i+1);
	 scanf("%d",&ps[i]);
	 alloct[i]=-1;
	}
//ALLOCATION>>>>ALLOCATION
for(i=0;i<pno;i++)
{
 for(j=0;j<bno;j++)
	{
	  if(bs[j]>=ps[i])
		{
		alloct[i]=j;//process i was allocated into jth block;
		bs[j]=bs[j]-ps[i];
		 break;
		}
	 
	}
}
printf("ALLOCATED STRUCTURE\n\n");
printf("processno\t\t processsize \t\t block allocated\n");
for(i=0;i<pno;i++)
	{
	 printf("\t%d\t\t%d\t",i+1,ps[i]);
	  if(alloct[i]!=-1)
		{
		 printf("\t%d\t\n",alloct[i]+1);
		}
	  else
		{
		 printf("\t\t NOT ALLOCATED TO ANY BLOCK\n");
		}
	}
}
