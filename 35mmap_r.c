#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/mman.h>
typedef struct student {
    int id;
    char name[20];
    int age;
} stu;


int main() {
    int fd;
    stu * mm;
    fd = open("temp", O_RDONLY);
    if (fd == -1) {
        perror("open error");
        exit(1);
    }

    mm = mmap(NULL, sizeof(stu), PROT_READ, MAP_SHARED, fd, 0);
    if (mm == MAP_FAILED) {
        perror("mmap error");
        exit(1);
    }

    while (1) {
        printf("id = %d\t name = %s\t age = %d\t\n", mm->id, mm->name, mm->age);
        sleep(1);
    }
    munmap(mm, sizeof(stu));

}