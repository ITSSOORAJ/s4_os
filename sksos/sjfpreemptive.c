#include<stdio.h>
#include<unistd.h>
void main()
{
int n,i,pid[90],at[90],bt[90],tat[90],wt[90],rt[90];
printf("enter the no of processses\n");
scanf("%d",&n);
printf("ENTER THE PROCESSS DETAILS \n PID\t|AT\t|BT\t|\n");
for(i=0;i<n;i++)
	{
	 scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
	 rt[i]=bt[i];
	}

printf("PID\t|AT\t|BT\t|TAT\t|WT\t\n");
int time=0,smallest=0,remain=0,ct=0,totaltat=0,totalwt=0;
  for(time=0;remain!=n;time++)
	{
	 for(i=0;i<n;i++)
		{
		  if(at[i]<=time&&rt[i])
			{
			 smallest=i;
			}
		}
	 rt[smallest]--;
		if(rt[smallest]==0)
			{
			 remain++;
			  ct=time+1;
      printf("p%d\t|%d\t|%d\t|%d\t|%d\t|\n",smallest+1,at[smallest],bt[smallest],ct-at[smallest],ct-bt[smallest]-at[smallest]);
			totaltat=totaltat+ct-at[smallest];
			totalwt=totalwt+ct-bt[smallest]-at[smallest];
			}
	}
printf("avg tat is %d",totaltat/n);
printf("avg wt is %d",totalwt/n);
}

