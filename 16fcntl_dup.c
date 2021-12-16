#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, const char ** argv) {
    int fd1 = open(argv[1], O_RDWR);
    printf("fd1 = %d\n", fd1);

    int newfd = fcntl(fd1, F_DUPFD, 0);
    printf("newfd = %d\n", newfd);

    int newfd2 = fcntl(fd1, F_DUPFD, 9);
    printf("newfd2 = %d\n", newfd2);

    int ret = write(newfd2, "hello world", 5);
    printf("ret = %d", ret);
    close(fd1);

    return 0;
}