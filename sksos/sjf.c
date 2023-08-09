#include<stdio.h>
#include<stdlib.h>
void main()
{
int bt[90],wt[90],tat[90],p[90];
int sum=0,add=0;
int n,i;
int awt,atat;
printf("enter the no of processses \n");
scanf("%d",&n);
printf("enter the burst time of each processes_>>>>>> \n");
for(i=0;i<n;i++)
        {
         printf("BURST TIME OF P[%d] :\t\n",i);
         scanf("%d",&bt[i]);
        }
for(i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
	{
	 if(bt[i]>bt[j])
		{
		 int temp= bt[i];
		 bt[i]=bt[j];
		 bt[j]=temp;
	 	 
		int temp1=p[i];
		    p[i]=p[j];
		    p[j]=temp1;
	
		}

}	}
printf("after sorting \n");
for(i=0;i<n;i++)
	{
	 printf("burst time of the process p%d :%d\n",p[i],bt[i]);
	}
wt[0]=0;
printf("WAITING TIME OF P[0] : \t%d\n",wt[0]);
for(i=1;i<n;i++)
        {
         wt[i]=wt[i-1]+bt[i-1];
        printf( "WAITING TIME OF P[%d]: \t%d\n",i,wt[i]);
         sum=sum+wt[i];
        }
for(i=0;i<n;i++)
        {
         tat[i]=wt[i]+bt[i];
         add=add+tat[i];
        }
printf("PROCESS \t\t BURSTTIME \t\t WITINGTIME \t\t TURNTIME \t\t\n");
for(i=0;i<n;i++)
{
printf("    p[%d] \t\t %d \t\t\t\t %d \t\t\t\t %d\n",i,bt[i],wt[i],tat[i]);
}
awt=sum/n;
printf("AVERAGE WAITING TIMR %d",awt);
atat=add/n;
printf("AVERAGE TURN AROUND TIME %d",atat);

}



