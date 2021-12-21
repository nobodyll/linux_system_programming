#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

void* produser(void *);
void* consumer(void *);
struct msg;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_data = PTHREAD_COND_INITIALIZER;

struct msg * head;

int main(int argc, char * argv[]) {
    int ret;
    pthread_t pid, cid;
    srand(time(NULL));

    ret = pthread_create(&pid, NULL, produser, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthreaad_create produser error");
    }

    ret = pthread_create(&cid, NULL, consumer, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthreaad_create produser error");
    }

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}

struct msg {
    int num;
    struct msg * next;
};

void* produser(void * arg) {
    while(1) {
    pthread_mutex_lock(&mutex);
    struct msg * mp = malloc(sizeof(struct msg));
    mp->num = rand() % 1000 + 1;
    printf("----produce %d\n", mp->num);
    mp->next = head;
    head = mp;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&has_data);
    sleep(rand() % 3);
    }
    return NULL;
}

void* consumer(void * arg) {
    while(1) {
    pthread_mutex_lock(&mutex);
    struct msg * mp;
    while (head == NULL) {
        pthread_cond_wait(&has_data, &mutex);
    }
    mp = head;
    head = mp->next;
    printf("--------consumer:%d\n", mp->num);
    pthread_mutex_unlock(&mutex);
    free(mp);
    sleep(rand() % 3);
    }
    return NULL;
}