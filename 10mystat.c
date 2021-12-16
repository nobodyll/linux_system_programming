#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int main(int argc, const char * argv[]) {
    struct stat sbuf;
    int ret = stat(argv[1], &sbuf);
    if (ret == -1) {
        perror("stat error");
        exit(1);
    }
    printf("file size :%ld\n", sbuf.st_size);
    printf("file mode :%d\n", sbuf.st_mode);
    return 0;
}