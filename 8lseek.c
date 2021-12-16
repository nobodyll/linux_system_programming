#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void) {

    int n = 0;
    char msg[] = "It's a test for lseek\n";
    char ch;
    int fd = open("lseek.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open lseek.txt error");
        exit(1);
    }
    write(fd, msg, strlen(msg));

    lseek(fd, 0, SEEK_SET);

    while ((n = read(fd, &ch, 1))) {
        if (n < 0) {
            perror("read error");
        }
        write(STDOUT_FILENO, &ch, n);
    }
    close(fd);
    return 0;
}