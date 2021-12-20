#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *tfn(void *arg) {
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());
    while(1);
    return NULL;
}

void *tfn(void * arg) {

}
int main() {
    pthread_t tid;
    tid = pthread_self();
    printf("main: pid = %d, tid = %lu\n", getpid(), tid);

    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if (ret != 0) {
        perror("pthread_create error");
    }

    while(1);
    return 0;
}