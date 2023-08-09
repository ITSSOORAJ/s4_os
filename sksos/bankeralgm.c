#include<stdio.h>//this was the last and latest modified one which could able to produce right and real answwer
#include<stdlib.h>
void main()
{
int m,n,alloc[80][80],max[80][80],need[80][80],avail[70],i,j,k,y;
int flag=0;
printf("enter the no of processes \n");
scanf("%d",&n);
printf("enter the no of resources \n");
scanf("%d",&m);
printf("enter the allocation matrix \n");
for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
		{
		 scanf("%d",&alloc[i][j]);
		}
	}
printf("enter the max matrix \n");
for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
		{
		 scanf("%d",&max[i][j]);
		}
	
	}
printf("enter the available matrix \n");
 for(i=0;i<m;i++)
	{
	 scanf("%d",&avail[i]);
	}
for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
		{
		 need[i][j]=max[i][j]-alloc[i][j];
		}
	}
printf("the need matrix \n");
for(i=0;i<n;i++)
	{	
		printf("\n");
	for(j=0;j<m;j++)
		{
		printf("%d\t\t",need[i][j]);
		}
	}
int finish[n],safesequence[n],work[m],ind;
for(i=0;i<n;i++)
	{
	 finish[i]=0;
	}
for(i=0;i<m;i++)
	{
	 work[i]=avail[i];
	}
for(k=0;k<n;k++)
	{
	for(i=0;i<n;i++)
	{
	if(finish[i]==0)
		{
		 flag=0;
		 for(j=0;j<m;j++)
			{
		 if(need[i][j]>work[j])
			{
			 flag=1;
			 break;
			}
		}
		if(flag==0)
		{
		        safesequence[ind]=i;
			ind++;
		for(y=0;y<m;y++)
			{

			  work[y]=work[y]+alloc[i][y];
			   finish[i]=1;
			}
		}
		else
			{
			 j=0;
			}

		}
}
}
printf("safe sequence\n");
for(i=0;i<n;i++)
	{
		printf("P%d->",safesequence[i]);
	}
}
