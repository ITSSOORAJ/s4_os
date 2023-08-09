#include<stdio.h>
#include<unistd.h>
void main()
{
int n,i,j,k,bt[90],prio[90],pid[90],tat[90],wt[90],ct[90];
printf("enter the number of the processes \n");
scanf("%d",&n);
printf("ENTER THE DETAILS REGARDING PROCESSES \n\n");
printf("|PID\t|PRIORITY|BURSTTIME |\n");
for(i=0;i<n;i++)
	{
	 scanf("%d%d%d",&pid[i],&prio[i],&bt[i]);
	}
for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
		{
		 if(prio[i]>prio[j])
			{
			 int temp1=prio[j];
			     prio[j]=prio[i];
			     prio[i]=temp1;
			 int temp2=bt[j];
				bt[j]=bt[i];
				bt[i]=temp2;
			 int temp3=pid[j];
				pid[j]=pid[i];
				pid[i]=temp3;
			}
		}
	}
int add=0,addta=0;
//tat[0]=bt[0];
//wt[0]=0;
for(k=0;k<n;k++)
	{
	//for(j=0;j<i;j++)
		//{
		 //tat[i]=0;
		  if(k==0)
			{
			 tat[k]=bt[k];
			 addta=addta+tat[k];
			}
		  else
			{
		  
		 tat[k]=tat[k-1]+bt[k];
		 addta=addta+tat[k];
		   
		 //tat[i]=tat[i]+bt[j];
		  //addta=addta+tat[i];
			 }
	}
for(i=0;i<n;i++)
{
//for(j=0;j<i;j++)
	
	// wt[i]=0;
	 wt[i]=tat[i]-bt[i];
	 add=add+wt[i];
	//}
}
printf("PID\t|PRIO\t|BRSTTME\t|TAT\t|WT\t|\n");
for(i=0;i<n;i++)
	{
	 printf("%d\t|%d\t|%d\t|%d\t|%d\t|\n\n",pid[i],prio[i],bt[i],tat[i],wt[i]);
	}
printf("tat%d....wt%d",addta,add);
double avt=addta/n;
float avw=add/n;
printf("AVGTAT=%f",avt);
printf("AVGWT=%f",avw);
}

