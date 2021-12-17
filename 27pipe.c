#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main() {

    int fd[2];

    char * buf[1024];
    const char * str = "hello world\n";

    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe error");
        exit(1);
    }

    pid_t pid = fork();

    if (pid > 0) {
        close(fd[0]);
        write(fd[1], str, strlen(str));
        close(fd[1]);
        sleep(1);
    }
    else if (pid == 0) {
        close(fd[1]);
        int size = read(fd[0], buf, sizeof(buf));
        close(fd[0]);
        write(STDOUT_FILENO, buf, size);
    }
    else {
        perror("fork error");
        exit(1);
    }

    return 0;
}