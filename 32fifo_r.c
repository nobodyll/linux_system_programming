#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char * argv[]) {

    int fd;
    char buf[40];
    if (argc < 2) {
        printf("Ent er like this: ./a.out fifoname\n");
        return -1;
    }
    fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        perror("open error");
    }

    while (1) {
        int len = read(fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
        sleep(1);
    }
    close(fd);
    return 0;
}