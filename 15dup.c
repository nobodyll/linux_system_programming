#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, const char **argv) {

    int fd = open(argv[1], O_RDWR);
    int newfd= dup(fd);

    printf("newfd = %d", newfd);
    write(newfd, "1234567", 7);
    close(fd); 
    return 0;
}