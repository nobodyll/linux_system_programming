#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
struct stu {
    int id;
    char name[20];
    int age;
};
typedef struct stu stu;

int main(int argc, char * argv[]) {

    int fd = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0664);
    if (fd == -1) {
        perror("open error");
        exit(1);
    }
    ftruncate(fd, sizeof(stu));
    struct stu s = {1, "xiaoming", 20};
    stu *p = (stu *)mmap(NULL, sizeof(stu), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap error");
        exit(1);
    }

    close(fd);
    while (1) {
        memcpy(p, &s, sizeof(stu));
        s.id++;
        sleep(1);
    }
    munmap(p, sizeof(stu));
    
    return 0;
}