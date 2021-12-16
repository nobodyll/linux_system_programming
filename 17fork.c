#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) {
    printf("before fork-1-\n"); 
    printf("before fork-2-\n"); 
    printf("before fork-3-\n"); 
    printf("before fork-4-\n"); 

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
    }
    else if (pid == 0) {
        printf("---child is created, pid = %d, parent pid = %d\n", getpid(), getppid());
    }
    else if (pid > 0) {
        printf("---parent process: mychild is %d, my pid = %d, parent pid = %d, \n", pid, getpid(), getppid());
    }

    printf("-------------end of file\n");

    return 0;
}