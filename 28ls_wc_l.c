#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int main(int argc, char * argv[]) {
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe error");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0) {
        // sleep(1);
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);
        close(fd[1]);
    }
    else if (pid > 0) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
        close(fd[0]);
    }
    else {
        perror("fork error");
        exit(1);
    }

    return 0;
}

