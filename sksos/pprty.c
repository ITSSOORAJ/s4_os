#include<stdio.h>
#include<stdlib.h>
void main()
{
int bt[90],wt[90],tat[90],p[90],pr[90];
int sum=0,add=0;
int n,i,j;
//int awt,atat;
printf("enter the no of processses \n");
scanf("%d",&n);
printf("enter the processid and burst time and priority \n");
for(i=0;i<n;i++)
        {
         //printf("processid & BURST TIME :\t\n",i) ;
         scanf("%d%d%d",&p[i],&bt[i],&pr[i]);
        }
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
	{
	 if(pr[i]>pr[j])
		{
		 int temp= bt[i];
		 bt[i]=bt[j];
		 bt[j]=temp;
			
	         temp = pr[i];
		  pr[i]=pr[j];
		  pr[j]=pr[i];
			
		int temp1=p[i];
		    p[i]=p[j];
		    p[j]=temp1;
	
		}

}	}
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
printf("PROCESS \t\t BURSTTIME \t\t PRIORITY \t\t WAITINGTIME \t\t TURNTIME \t\t\n");
for(i=0;i<n;i++)
{
printf("    p%d \t\t %d \t\t\t\t %d \t\t\t\t %d \t\t\t\t %d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
}
float awt=(float)sum/n;
printf("AVERAGE WAITING TIMR %f",awt);
float atat=(float)add/n;
printf("AVERAGE TURN AROUND TIME %f",atat);

}
