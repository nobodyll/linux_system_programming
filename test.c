#include <fcntl.h>
#include <stdio.h>
int main() {
    int a = O_RDONLY;
    printf("a = %d\n", a);
    int b = O_WRONLY;
    printf("b = %d\n", b);
    int d = O_RDWR;
    printf("d = %d\n", d);
    int c = a | d;
    printf("c = %d\n", c);
    int e = O_APPEND;
    printf("e = %d\n", e);
    return 0;
}