#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *tfn(void * arg) {
    int i = (int)arg;
    // sleep(i);
    printf("---I'm %dth thread: pid = %d, tid = %lu\n", i + 1, getpid(), pthread_self());
    return NULL;
}

int main() {
    int i;
    int ret;
    pthread_t tid;
    for (i = 0; i < 5; i++) {
        ret = pthread_create(&tid, NULL, tfn, (void *)i);
        if (ret != 0) {
            perror("pthread error");
            exit(1);
        }
    }
    // sleep(i);
    printf("I'm main, pid = %d, tid = %lu\n", getpid(), pthread_self());
    while(1);
    return 0;
}
