#include <stdio.h>
#include <signal.h>
void sig_catch(int);
int main() {
    signal(SIGINT, sig_catch);
    while(1);

    return 0;
}
void sig_catch(int signo) {
    printf("catch you %d\n", signo);
}