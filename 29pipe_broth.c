#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <wait.h>

int main(int argc, char * argv[]) {
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe error");
        exit(1);
    }

    int i = 0;
    pid_t pid = 0;
    for (i = 0; i < 2; i++) {
        pid =  fork();
        if (pid == -1) {
            perror("error");
            exit(1);
        }
        if (pid == 0) {
            break;
        }
    }

    if (i == 2) {
        // close(fd[0]);
        close(fd[1]);
        wait(NULL);
        wait(NULL);
    }
    else if (i == 0) {      //兄进程
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
        close(fd[0]);
    }
    else if (i == 1) {      //弟进程
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);
        close(fd[1]);
    }
    else {
        perror("fork error");
        exit(1);
    }

    return 0;
}

