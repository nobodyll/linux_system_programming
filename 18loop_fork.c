#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) {
    int i;
    for (i = 0; i < 5; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            break;
        }
    }
    if (i == 5) {
        sleep(5);
        printf("i am parent\n");
    }
    else {
        sleep(i);
        printf("I am the %dth child.\n", i);
    }
    return 0;
}
   
   
   
   
   
   
   
   