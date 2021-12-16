#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define MSG_TRY "try again\n"
#define MSG_TIMEOUT "time out\n"

int main(void) {
    char buf[10];
    int fd, n, i;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("open /dev/tty");
        exit(1);
    }
    printf("open /dev/tty ok...%d\n", fd);

    for (i = 0; i < 5; i++) {
        n = read(fd, buf, 10);
        if (n > 0) {
            break;
        }
        else if (errno != EAGAIN) {
            perror("read /dev/tty");
        }
        else {
            sleep(2);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
        }
    }
    if (i == 5) {
        write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
    }
    else {
        write(STDOUT_FILENO, buf, n);
    }
    close(fd);
    return 0;
}
