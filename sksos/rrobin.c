#include<stdio.h>
#include<unistd.h>
void main()
{
int n,i,counter,bt[90],wt[90],tat[90],at[90],qt,ct=0,rt[i],twt=0,ttat=0,pid[90];
printf("\t\t\t\t\t\t\t\tROUND ROBIN\n");
printf("enter the no of processes\n");
scanf("%d",&n);
counter=n;
printf("enter the details of the processes\n");
printf("\n\nPID\t|AT\t|BT\t\n");
for(i=0;i<n;i++)
	{
	 scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
	 rt[i]=bt[i];
	}
printf("enter the time  quantum \n");
scanf("%d",&qt);
printf("PID\t|AT\t|BT\t|TAT\t|wt\t\n");
for(i=0,ct=0;counter!=0;)
	{
	 if(rt[i]<=qt&&rt[i]>0)
		{
		  ct=ct+rt[i];
		  rt[i]=0;
		  counter--;
		  printf("p%d\t|%d\t|%d\t|%d\t|%d\t|\n",i+1,at[i],bt[i],ct-at[i],ct-at[i]-bt[i]);
		  ttat=ttat+ct-at[i];
		  twt=twt+ct-at[i]-bt[i];
		}
	 else if(rt[i]>0)
		{
		  rt[i]=rt[i]-qt;
		  ct=ct+qt;
		}
	  if(i==n-1)
		{
		  i=0;
		}
	  else if(at[i+1]<=ct)
		{
		  i++;
		}
	   else
		{
		 i=0;
		}
	}
float avgtat=(float)ttat/n;
float  avgwt=twt/n;
printf("avge tat is{%d} %f\n",ttat,avgtat);
printf("avge wt is{%d} %f\n",twt,avgwt);
}
