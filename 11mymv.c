#include <sys/unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    link(argv[1], argv[2]);
    unlink(argv[1]);
    return 0;
}