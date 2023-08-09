#include<stdio.h>
#include<unistd.h>
void main()
{
pid_t id=fork();
int a,b,n;
if(id<0)
	{
	 printf("invalid process\n ");
	}
else if(id==0)
	{
	 printf("child process is excecuting \n $child processid =%d \n $parent proccecss id = %d \n",getpid(),getppid());
	 printf("FINd ODD OR EVEN \n");
	 printf("enter the number to be checked \n");
	 scanf("%d",&n);
	 if(n%2==0)
		{
		 printf("given is even \n");
		}
	else
		{
		 printf("given is odd \n");
		}

	}
else
	{
	 wait();
	 printf("parent process is excecuting \n");
	 printf("the parent processs id = %d \n",getpid());
	 printf("enter 2 numbers to check which among them were greater\n  A= \n B= \n");
	scanf("%d%d",&a,&b);
	 if(a>b)
		{
		 printf("A IS LARGEST \n");
		}
	 else
		{
		 printf("B IS LARGEST \n");
		}
	}
}
