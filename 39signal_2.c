#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sig_catch(int signo);
int main() {

    struct sigaction act, oldact;
    act.sa_flags = 0;
    act.sa_handler = sig_catch;

    sigemptyset(&(act.sa_mask));

    int ret = sigaction(SIGINT, &act, &oldact);
    if (ret == -1) {
        perror("sigaction error");
        exit(1);
    }
    ret = sigaction(SIGQUIT, &act, &oldact);
    if (ret == -1) {
        perror("sigaction error");
        exit(1);
    }



    while(1);

    return 0;
}
void sig_catch(int signo) {
    printf("catch you %d\n", signo);
}