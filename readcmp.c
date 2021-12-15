#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char * argv[]) {
    char buf[1];
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        // perror("open argv[1] error");
        printf("xxx error:%d\n", errno);
        char * strerror(int errnum);
        printf("xxx error: %s\n", strerror(errno));
        exit(1);
    }

    int fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0664);
    if (fd2 == -1) {
        perror("open argv[2] error");
        exit(1);
    }
    int n = 0;
    while ((n = read(fd1, buf, 1)) != 0) {
        if (n < 0) {
            perror("read error");
            break;
        }
        write(fd2, buf, n);
    }

    close(fd1);
    close(fd2);
    return 0;
}
