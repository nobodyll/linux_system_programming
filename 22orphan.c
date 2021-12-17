#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();
    if (pid == 0) {
        while (1) {
            printf("i am child, my parent pid = %d\n", getppid());
            sleep(1);
        }
    }
    else if (pid > 0) {
        printf("I am parent, my pid is = %d\n", getpid());
        sleep(9);
        printf("---------------parent going to die-------------\n");
    }
    else {
        perror("fork");
        exit(1);
    }

    return 0;
}