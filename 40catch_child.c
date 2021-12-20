#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
void sys_err(const char * s) {
    perror(s);
    exit(1);
}

// void catch_child(int signo) {
//     pid_t wpid;
//     wpid = wait(NULL);
//     printf("-------catch the child id %d\n", wpid);
//     return ;
// }

void catch_child(int signo) {
    pid_t wpid;
    while ((wpid = wait(NULL)) != -1) { 
        printf("----catch child id %d\n", wpid);
    }
    return ;
}

int main(int argc, char * argv[]) {
    int i = 0;
    pid_t pid;
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK, &set, NULL);

    for (i = 1; i < 10; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
        else if (pid == -1) {
            sys_err("fork error");
        }
    }

    if (i == 10) {
        struct sigaction  act;
        act.sa_handler = catch_child;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        sigaction(SIGCHLD, &act, NULL);
        sigprocmask(SIG_UNBLOCK, &set, NULL);
        printf("i am parent, pid = %d\n", getpid());
        while(1){ }
    }
    else {

        printf("I'm %dth child pid = %d\n", i, getpid());
    }

    return 0;
}