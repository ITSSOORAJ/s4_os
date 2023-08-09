#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
int main()
{
int shmid;
char buff[100];
void*shared_mmry;
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("SHMID:%d\n",shmid);
shared_mmry=shmat(shmid,NULL,0);
printf("process attached at %p\n",shared_mmry);
printf("data readed from the shared memmori is : %s",(char *)shared_mmry);
}


