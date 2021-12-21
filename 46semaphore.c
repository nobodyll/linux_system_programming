#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM 5

void * producer(void *arg);
void * consumer(void *arg);

int queue[5];
sem_t black_number, product_number;

int main() {

    pthread_t pid, cid;
    sem_init(&black_number, 0, NUM);
    sem_init(&product_number, 0, 0);

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(cid, NULL);
    pthread_join(pid, NULL);
    sem_destroy(&black_number);
    sem_destroy(&product_number);
    return 0;
}

void * producer(void * arg) {
    int i = 0;
    while (1) {
        sem_wait(&black_number);
        queue[i] = rand() % 1000 + 1;
        printf("-Produce---%d\n", queue[i]);
        sem_post(&product_number);
        i = (i + 1) % NUM;
        sleep(rand() % 1);
    }

}
void * consumer(void * arg) {
    int i = 0;
    while (1) {
        sem_wait(&product_number);
        printf("---------Consumer-----%d\n", queue[i]);
        queue[i] = 0;
        sem_post(&black_number);
        i = (i + 1) % NUM;
        sleep(rand() % 3);
    }
}
