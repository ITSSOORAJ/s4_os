#include<stdio.h>//actuall code;
#include<unistd.h>
void main()
{
int a,i,k,pno,bs[90],bno,ps[90],q[90],no=0,f[90],alloct[90],j,lowest=999,par[90],bar[90],temp=0,frgmnt[90];
printf("FIRST IN FIRST OUT\n");
printf("\t\t\n enter the no of blocks\n");
scanf("%d",&bno);
printf("enter the size of each blocks \n");
for(i=0;i<bno;i++)
        {
         printf("ENTER SIZE OF BLOCK%d\t",i+1);
         scanf("%d",&bs[i]);
	 f[i]=bs[i];
        }
printf("enter the no of processes\n");
scanf("%d",&pno);
printf("enter the size of each processes\n");
for(i=0;i<pno;i++)
        {
         printf("ENTER SIZE OF P%d\t",i+1);
         scanf("%d",&ps[i]);
	}
printf("PROCESSNO\tPROCESSSIZE\tBLOCKNO\tBLOCKSIZE\tFRAGMENTATION\n");
for(i=0;i<pno;i++)
	{
	 for(j=0;j<bno;j++)
		{
		 if(ps[i]<=f[j])
			{
			  a=f[j];
			  no=j;
			 for(k=0;k<bno;k++)
				{
				 if(f[k]>ps[i]&&f[k]<a)
					{
					  a=f[k];
					  no=k;
					}
				}
			}
	
		else	
			{
			 continue;
			}
		}
	f[no]=a-ps[i];
	 q[i]=f[no];
	if(q[i]<=0)
		{
		 printf("%d\t%d\tNOT\tNOT\tNOT\n",i+1,ps[i]);
		}	
	else
		{
		 printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,ps[i],no+1,a,q[i]);
		}

	}

}
