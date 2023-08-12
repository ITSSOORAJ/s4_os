//good priority.nonpremptive.arrivaltime
#include<stdio.h>
int main()
{
            int at[10],bt[10],pr[10],p[90];
            int n,i,j,temp,time=0,count,over=0,sum_wait=0,sum_turnaround=0,start;
            float avgwait,avgturn;
            printf("Enter the number of processes\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                        printf("Enter the arrival time & priority & execution time for process %d\n",i+1);
                        scanf("%d%d%d",&at[i],&p[i],&bt[i]);
                        pr[i]=i+1;
            }
            for(i=0;i<n-1;i++)
            {
                        for(j=i+1;j<n;j++)
                        {
                                    if(at[i]>at[j])
                                    {
                                                temp=at[i];
                                                at[i]=at[j];
                                                at[j]=temp;
                                                temp=bt[i];
                                                bt[i]=bt[j];
                                                bt[j]=temp;
						 temp=p[i];
					         p[i]=p[j];
						 p[j]=temp;
                                                temp=pr[i];
                                                pr[i]=pr[j];
                                                pr[j]=temp;     
                                    }
                        
                        }
            }
printf("PROCESS ID\tARRIVAL TIME\tPRIORITY\tBURST TIME\tTURNATIME\tWAITNGTIME\n");
while(over<n)
	{
	  count=0;
	  for(i=over;i<n;i++)
		{
		  if(at[i]<=time)
			{
			  count++;
			}
		   else
			{
			 break;
			}
		}
	  if(count>1)
		{
			for(i=over;i<count+over-1;i++)
				{
			 	 for(j=over+1;j<count+over;j++)
					{
					   if(p[i]>p[j])
                                                            {
                                                                        temp=at[i];
                                                                        at[i]=at[j];
                                                                        at[j]=temp;
									 temp=p[i];
									 p[i]=p[j];
									 p[j]=temp;
                                                                        temp=bt[i];
                                                                        bt[i]=bt[j];
                                                                        bt[j]=temp;
                                                                        temp=pr[i];
                                                                        pr[i]=pr[j];
                                                                        pr[j]=temp;     
                                                            }
					}
				}
		 }
		 time+=bt[over];
		  printf("\t%d\t\t%d\t\t%d\t%d\t\t%d\t\t%d\n",pr[over],at[over],p[over],bt[over],time-at[over],time-at[over]-bt[over]);
		    sum_wait+=time-at[over]-bt[over];


                    sum_turnaround+=time-at[over];
		 over++;
	}
printf("TOTAL TAT:%d\nTOTAL WT:%d \n",sum_turnaround,sum_wait);

}
