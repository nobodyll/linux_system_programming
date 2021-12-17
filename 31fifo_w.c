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
    int i;
    char buf[4096];
    if (argc < 2) {
        printf("Ent er like this: ./a.out fifoname\n");
        return -1;
    }
    fd = open(argv[1], O_WRONLY);

    if (fd < 0) {
        perror("open error");
    }

    while (1) {
        sprintf(buf, "hello itcast %d\n", i++);
        write(fd, buf, strlen(buf)); 
        sleep(1);
    }
    close(fd);
    return 0;
}