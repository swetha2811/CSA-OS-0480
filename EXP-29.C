#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;
void *producer(void *arg);
void *consumer(void *arg);
int main() {
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_t producerThreads[NUM_PRODUCERS];
    pthread_t consumerThreads[NUM_CONSUMERS];
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        pthread_create(&producerThreads[i], NULL, producer, NULL);
    }
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        pthread_create(&consumerThreads[i], NULL, consumer, NULL);
    }
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        pthread_join(producerThreads[i], NULL);
    }
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        pthread_join(consumerThreads[i], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}
void *producer(void *arg) {
    int item = 1;
    while (1) {
        sleep(1);
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Produced item %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        item++;
    }
    pthread_exit(NULL);
}
void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        printf("Consumed item %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    pthread_exit(NULL);
}
