#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int  main(int argc, const char ** argv) {
    int fd = open("ps.out", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    dup2(fd, STDOUT_FILENO);
    execlp("ps", "ps", "aux", NULL);
    perror("execlp error");
    close(fd);
    return 0;
}