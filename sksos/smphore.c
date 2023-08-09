#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
//#include<unistd.h>

#define BUFFERSIZE 5
#define NUM_ITEMS 10

int buffer[BUFFERSIZE];
int in=0;
int out=0;
int i;

sem_t emptyslots;
sem_t fullslots;

pthread_mutex_t mutex;



void*producer (void*pno)
{
int item;
for(i=0;i<NUM_ITEMS;i++)
	{
	 item=rand();
	 sem_wait(&emptyslots);
	 pthread_mutex_lock(&mutex);
	    buffer[in]=item;
	   printf("producer %d :inserts %d at %d",((int)pno),item,in);
		in=in+1%BUFFERSIZE;
	 pthread_mutex_unlock(&mutex);
	 sem_post(&fullslots);
	//pthread_exit(NULL);
	}
	pthread_exit(NULL);
}
void*consumer (void*cno)
{
int item;
for(i=0;i<NUM_ITEMS;i++)
	{
	 sem_wait(&fullslots);
	 pthread_mutex_lock(&mutex);
		item=buffer[out];

	pthread_mutex_unlock(&mutex);
	sem_post(&emptyslots);	
	}
	pthread_exit(NULL);
}




int main()
{
pthread_t producerthread[5],consumerthread[5];
sem_init(&emptyslots,0,BUFFERSIZE);
sem_init(&fullslots,0,0);
pthread_mutex_init(&mutex,NULL);
int a[5]={1,2,3,4,5};
for(i=0;i<5;i++)
{
pthread_create(&producerthread[i],NULL,(void* )producer,(void*)&a[i]);
}

for(i=0;i<5;i++)
{
pthread_create(&consumerthread[i],NULL,(void*)consumer,(void*)&a[i]);
}
for(i=0;i<5;i++)
{
pthread_join(producerthread[i],NULL);
}
for(i=0;i<5;i++)
{
pthread_join(consumerthread[i],NULL);
}
sem_destroy(&emptyslots);
sem_destroy(&fullslots);
pthread_mutex_destroy(&mutex);
return 0;
}

