#include<stdio.h>
#include<unistd.h>
void main()
{
int pipefd1[2],pipefd2[2],pid;
int returnstatus1,returnstatus2;
char pipe1writemessage[30]="SOORAJ";
char pipe2writemessage[30]="KUMAR";
char readmessage[49];
returnstatus1=pipe(pipefd1);
if(returnstatus1==-1)
	{
		printf("unable to create pipe \n");
	}
returnstatus2=pipe(pipefd2);
if(returnstatus2==-1)
	{
		printf("unable to create pipe2");
	}
pid=fork();
	if(pid!=0)
		{
		 printf("WORKING ON PARENT\n");
		  close(pipefd1[0]);
		  close(pipefd2[1]);
		 printf("in parent:writing to pipe1>>>>>>>>> WRITED MESSAGE IS %s \n",pipe1writemessage);
		 write(pipefd1[1],pipe1writemessage,sizeof(pipe1writemessage));
		 read(pipefd2[0],readmessage,sizeof(readmessage));
		printf("in parent :reading from pipe2<<<<<<<<< READED MESSAGE IS %s \n",readmessage);
		}
	else
		{
			printf("WORKING ON CHILD \n");
			close(pipefd1[1]);
			close(pipefd2[0]);
			printf("IN CHILD WRITING TO PIPE2 >>>>>>>>> WRITED MESSAGE IS %s \n",pipe2writemessage);
			write(pipefd2[1],pipe2writemessage,sizeof(pipe2writemessage));
			read(pipefd1[0],readmessage,sizeof(readmessage));
			printf("IN CHILD READING FROM PIPE1 <<<<<<< READMEAASAGE IS %s \n",readmessage);
			 return 0;
		}
}

