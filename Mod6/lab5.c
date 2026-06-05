#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE];
int count = 0;

sem_t empty, full, mutex;

void* producer(void* arg) {
    while (1) {
        sleep(1);

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[count++] = 1;
        printf("Produced, count = %d\n", count);

        sem_post(&mutex);
        sem_post(&full);
    }
}

void* consumer(void* arg) {
    while (1) {
        sleep(2);

        sem_wait(&full);
        sem_wait(&mutex);

        buffer[--count] = 0;
        printf("Consumed, count = %d\n", count);

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main() {
    pthread_t prod, cons;

    sem_init(&empty, 0, SIZE);
    sem_init(&full,  0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}