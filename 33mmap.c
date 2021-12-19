#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/fcntl.h>

int x = 100;

int main() {

    int fd = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0664);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }
    ftruncate(fd, 4);

    // int *p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    int *p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (p == MAP_FAILED){
        perror("mmap error");
        exit(1);
    }
    close(fd);

    *p = 30;
    printf("*p = %d\n", *p);

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        *p = 40;
        x = 10;
        printf("*p = %d, x = %d\n", *p, x);
    }
    else if (pid > 0) {
        sleep(1);
        printf("*p = %d, x = %d\n", *p, x);
        wait(NULL);
        int ret = munmap(p, 4);
        if (ret == -1) {
            perror("munmap error");
            exit(1);
        }
    }
    else {
        perror("fork error");
        exit(1);
    }

    return 0;
}
