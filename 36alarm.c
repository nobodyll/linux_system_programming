#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    alarm(1);
    for (int i = 0; ; i++) {
        printf("%d\n", i);
    }
    return 0;
}