#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, const char * argv[]) {
    pid_t pid;
    pid = fork(); 

    int var = 100;

    if (pid == -1) {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0) {
        var = 100;
        printf("child, var = %d\n", var);
        printf("i'm child, pid = %d, getppid = %d\n", getpid(), getppid());
    }
    else if (pid > 0) {
        var = 280;
        printf("parent, var = %d\n", var);
        printf("i'm parent pid = %d, getppid = %d\n", getpid(), getppid());
    }
    printf("var = %d\n", var);
    return 0;
}