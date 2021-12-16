#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int  main(int argc, const char ** argv) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0) {
        // execlp("ls", "ls", "-l", "-h", NULL);
        // execlp("date", "date", NULL);
        execl("./test", "./test", "test.c", NULL);
        perror("exec error");
        exit(1);
    }
    else if (pid > 0) {
        sleep(1);
        printf("I'm parent : %d\n", getpid());
    }
    return 0;
}