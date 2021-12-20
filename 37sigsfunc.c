#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void print_set(sigset_t *pedset);
int main(int argc, char * argv[]) {
    sigset_t set, oldset, pedset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);



    int ret = sigprocmask(SIG_BLOCK, &set, &oldset);
    if (ret == -1) {
        perror("sigprocmask error");
        exit(1);
    }

    while(1) {
        ret = sigpending(&pedset);
        if (ret == -1) {
            perror("sigpending error");
            exit(1);
        }
        print_set(&pedset);
        sleep(1);
    }

    return 0; 
}

void print_set(sigset_t *pedset) {
    for (int i = 1; i < 32; i++) {
        if (sigismember(pedset, i)) { 
            // printf("%d", 1);
            putchar('1');
        }
        else {
            // printf("%d", 0);
            putchar('0');
        }
    }
    printf("\n");
}