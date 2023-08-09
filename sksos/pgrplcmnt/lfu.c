#include<stdio.h>
#include<stdio.h>
void print(int fno,int fm[])
		{
		 int i;
		 for(i=0;i<fno;i++)
			{
			 printf("%d\t",fm[i]);
			 printf("\n");
			}
		}
int main()
{

int fno,pno,fm[90],f,p,j,count=0,pg[90],i,repindex,lescount,k=0,flag;
int count1[10];
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
for(i=0;i<fno;i++)
        {       
          fm[i]=-1;
	printf("%d",i);
        }
printf("PAGEREFFERCE\t\tFRAME STATUS\n");
printf("hell");
for(i=0;i<pno;i++)
	{
		 count1[i]=0;
		printf("%d",i);
	}
for(i=0;i<pno;i++)
	{
	 printf("%d\t\t",pg[i]);
		flag=0;
	 for(j=0;j<fno;f++)
		{
		if(pg[i]==fm[j])
			{
			 flag=1;
		 	 count1[j]++;
			 printf("HIT \n");
			 break;	 
			}
		}
	     if(flag==0 && count<fno)
			{
			  fm[k]=pg[i];
			  count1[k]=1;
			  k=(k+1)%fno;
			 count++;
			 print(fno,fm);
			}
		else if(flag==0)
			{
			  repindex=0;
			  lescount=count1[0];
			   for(j=1;j<fno;j++)
				{
				  if(lescount>count1[j])
					{
					 repindex=j;
					 lescount=count1[j];
					   
					}
				}
				fm[repindex]=pg[i];
				 count1[repindex]=1;
				 count++;
			        print(fno,fm);
			}
		}
return 0;
}
