#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char buf[10];
    int n = 0;

    n = read(STDIN_FILENO, buf, 10);
    if (n < 0) {
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
    return 0;
}