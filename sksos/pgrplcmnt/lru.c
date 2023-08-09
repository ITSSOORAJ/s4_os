#include<stdio.h>
#include<stdio.h>
int lru(int time[],int fno)
	{
	 int i,min=time[0],pos=0;
		for(i=0;i<fno;++i)
			{
			 if(time[i]<min)
				{
				 min=time[i];
				 pos=i;
				}
			}
		return pos;
	}
void main()
{

int fno,pno,fm[90],f,p,j,count=0,pg[90];
printf("\t\t\t\t\t\t_______FIFO_____\n");
printf("enter the no of frames");
scanf("%d",&fno);
printf("ENTER THE NO OF PAGES");
scanf("%d",&pno);
printf("ENTER THE NUMBERS CORRESPONDING TO EACH PAGE\n");
for(p=0;p<pno;p++)
        {
         scanf("%d",&pg[p]);
        }
for(int i=0;i<fno;i++)
        {       
          fm[i]=-1;
        }
int flag1;
int flag2,pos;
int time[90],counter=0,fault=0;
printf("\tPAGE NUMBERS\t\t\tFRAME STATUS\n");
/*for(int i=0;i<pno;i++)
	{
	 printf("\n\n%d\t\t\n",pg[i]);
	}*/
for(int i=0;i<pno;i++)
	{
	 int avail=0;
	 printf("\n\t%d",pg[i]);
	flag1=flag2=0;
	 for(int j=0;j<fno;j++)
		{
		 if(fm[j]==pg[i])
			{
			 counter++;
			 flag1=flag2=1;
			 time[j]=counter;
			 avail=1; 
		 	 break;
			}
		}
if(avail==1)
	{
printf("\t\tHIT\t\t");
	}
if(avail==0)
	{

	 if(flag1==0)
		{
		  for(j=0;j<fno;j++)
			{
			 if(fm[j]==-1)
				{
				 //fm[j]=pg[i];
				counter++;
				fault++;
				 fm[j]=pg[i];
				time[j]=counter;
				 flag2=1;
			 	 break;
				}
			}
		}
	if(flag2==0)
		{
		 pos=lru(time,fno);
		  counter++;
		  fault++;
		  fm[pos]=pg[i];
		  time[pos]=counter;
		}	
	printf("\n");
	 for(j=0;j<fno;j++)
		{
		 printf("\t\t\t\t%d",fm[j]);
		}
printf("\n");
}
}
printf("PAGE FAULT::%d",fault);
}
