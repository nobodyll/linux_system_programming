#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
int main() {
    int status;
    pid_t pid, wpid;
    pid = fork();
    if (pid == 0) {
        printf("---child, my pid = %d, going to sleep 3s\n",  getpid());
        sleep(3);
        printf("----child die-\n");
    }
    else if (pid > 0) {
        wpid = wait(&status);
        printf("---parent wait finish, wpid = %d\n", wpid);
        if (wpid == -1) {
            perror("wait error");
            exit(1);
        }
    }
    else {
        perror("fork error");
        exit(1);
    }

    return 0;
}