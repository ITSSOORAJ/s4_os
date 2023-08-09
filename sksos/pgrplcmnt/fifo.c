#include<stdio.h>
void main()
{
int fno,pno,fm[90],f,p,j,count=0,avail=0,pg[90];
printf("\t\t\t\t\t\t_______FIFO_____\n");
printf("ENTER THE NO OF PAGES");
scanf("%d",&pno);
printf("ENTER THE NUMBERS CORRESPONDING TO EACH PAGE\n");
for(p=0;p<pno;p++)
	{
	 scanf("%d",&pg[p]);
	}
printf("ENTER THE NO OF FRAMES");
scanf("%d",&fno);
for(int i=0;i<fno;i++)
	{	
	  fm[i]=-1;
	}
j=0;

printf("\tPAGE NUMBERS\t\t\tFRAME STATUS\n");
 for(p=0;p<pno;p++)
	{
	 printf("%d\t\t",pg[p]);
	 avail=0; 
	 for(f=0;f<fno;f++)
			{
		 if(fm[f]==pg[p])
			{
				avail=1;
			}
		}
	  if(avail==1)
		{
		 printf("HIT");
		}
	  if(avail==0)
		{
		   fm[j]=pg[p];
		   j=(j+1)%fno;
		   count++;
	  for(int k=0;k<fno;k++)
		{
		 printf("%d\t",fm[k]);
		}
		}printf("\n");
	}
printf("PAGE FAULT IS %d",count);

}
