#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open error");
        exit(1);
    }
    int size  = lseek(fd, 0, SEEK_SET);
    write(fd, "a", 1);
    printf("%s's size : %d\n", argv[1], size);
    close(fd);
    return 0;
}