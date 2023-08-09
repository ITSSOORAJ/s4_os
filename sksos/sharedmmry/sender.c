#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>

int main()
{
void*shared_mmry;
int shmid;
char buff[100];
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("id of the shared memmory is %d\n\n",shmid);
shared_mmry=shmat(shmid,NULL,0);
printf("process attached at %p\n",shared_mmry);
printf("enter some data to write into the shared memory \n");
read(0,buff,10);
strcpy(shared_mmry,buff);
printf("DATA YOU WRITE TO SHARED MEMORY IS %s\n\n",(char *)shared_mmry);
}
