#include <stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include<semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty_slots;
sem_t full_slots;
pthread_mutex_t mutex;

void *producer(void *pno) {
    int item;

    for (int i = 0; i < NUM_ITEMS; i++) {
        item = rand();

        sem_wait(&empty_slots);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("producer  %d : Insert %d at %d\n",((int)pno),buffer[in], in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full_slots);

    pthread_exit(NULL);
    }
}

void *consumer(void *cno) {
    int item;

    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full_slots);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("consumer %d:Removed Item %d from %d\n",((int)cno),item,out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty_slots);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread[5], consumerThread[5];

    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    int a[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
         pthread_create(&producerThread[i], NULL,(void*) producer,(void*) &a[i]);    
    }

    for(int i=0;i<5;i++){
         pthread_create(&consumerThread[i], NULL,(void*)  consumer,(void*) &a[i]);
    }
    for(int i=0;i<5;i++){
    pthread_join(producerThread[i], NULL);
    }
    for(int i=0;i<5;i++){
    pthread_join(consumerThread[i], NULL);
    }

    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    pthread_mutex_destroy(&mutex);

    return 0;
}
