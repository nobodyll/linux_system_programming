#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int ret;
    pid_t pid;
    pid = fork();
    if (pid > 0) {
        exit(0);
    }
    pid = setsid();
    if (pid == -1) {
        exit(1); 
    }
    ret = chdir("/home/l/");
    if (ret == -1) {
        exit(1);
    }

    umask(0022);
    close(STDIN_FILENO);
    int fd = open("/dev/null", O_RDWR);
    if (fd == -1) {
        exit(1);
    }

    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);

    while(1);


    return 0;
}