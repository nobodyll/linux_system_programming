#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main() {
    pid_t pid, wpid;
    int i;
    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }

    if (i == 5) {

        // while ((wpid = waitpid(-1, NULL, 0))) {
        //     printf("wait child pid = %d\n", wpid);
        // }

        while ((wpid = waitpid(-1, NULL, WNOHANG)) != -1) {
            if (wpid > 0) {
                printf("wait child %d\n", wpid);
            }
            else if (wpid == 0) {
                sleep(1);
                continue;
            }
        }

    }
    else {
        sleep(i);
        printf("I'm %dth child, pid = %d\n", i + 1, getpid());
    }

    return 0;
}