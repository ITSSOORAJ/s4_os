#include<stdio.h>//failure code dont use this////new one is at prtylatest.c
#include<stdlib.h>
void main()
{
int n,bt[80],pr[80],i,j,temp1,temp2,ct[90],tat[90],wt[80],p[90];
int awt,atat,temp;
float sum,add;
printf("enter the no of processes");
scanf("%d",&n);
for(i=0;i<n;i++)
	{
	 printf("enter BURSTTIME of p[%d]:",i);
	 scanf("%d",&bt[i]);
p[i]=i;
	}
for(i=0;i<n;i++)
	{
	 printf("enter the PRIORITY of p[%d]:",i);
	 scanf("%d",&pr[i]);
	}
printf("before sorting on priority\n");
printf(" prcss   bt     pprty \n");
for(i=0;i<n;i++)
	{
	printf("p%d     %d     %d \n",i,bt[i],pr[i]);
	}

for(i=0;i<n;i++)
	{

	for(j=i+1;j<n;j++)
		{
		 if(pr[i]>pr[j])
			{
			 temp1=bt[i];
			  bt[i]=bt[j];
			  bt[j]=temp1;
			  
			 temp2=pr[i];
			 pr[i]=pr[j];
			 pr[j]=temp2;
			 


			temp=p[i];
			 p[i]=p[j];
			p[j]=temp;
			}
		}
	}
ct[0]=bt[0];//based on gant chart 
wt[0]=0;
for(i=1;i<n;i++)
	{
	 ct[i]=bt[i]+ct[i-1];
	}
for(i=0;i<n;i++)
	{
	  tat[i]=ct[i];
	   //wt[i]=tat[i]-bt[i];
	 //sum=sum+tat[i];
	 add=add+tat[i];	
	}
for(i=0;i<n;i++)
	{
	 wt[i]=tat[i]-bt[i];
	 sum=sum+wt[i];
	}
printf("process \t\t BT \t\t  prty \n");
for(i=0;i<n;i++)
	{
	printf(" %d  \t\t %d \t\t %d\n",p[i],bt[i],pr[i]);
	}
/*printf("PRCSS \t\t BT  \t\t CT  \t\t  WT  \t\t TAT \n " );
for(i=0;i<n;i++);
	{
	 printf("%d  \t\t\t  %d \t\t\t  %d   ",i,bt[i],ct[i]);
	}*/
awt=sum/n;
atat=add/n;
printf("AWT is %d \n ATAT is %d \n",awt,atat);
}

