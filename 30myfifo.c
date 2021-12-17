#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char * argv[]) {

    int ret = mkfifo("mytestfifo", 0664);
    if (ret == -1) {
        perror("mkfifo error");
        exit(1);
    }

    return 0;
}