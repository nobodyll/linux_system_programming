#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main() {
    pid_t pid, wpid, tempid;
    int i;
    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
        else if (pid > 0) {
            if (i == 2) {
                tempid = pid;
                printf("-----pid = %d\n", tempid);
            }
        }
    }

    if (i == 5) {
        sleep(5);
        // wpid = wait(NULL);                                                     //一次wait/waitpid 函数调用，只能回收一个子进程
        // wpid = waitpid(-1, NULL, WNOHANG);                              //回收任意子进程，没有结束的子进程，父进程直接返回零
        // wpid = waitpid(tempid, NULL, 0);                                //指定一个进程回收， 阻塞等待
        printf("i am parent, before waitpid , pid = %d\n", tempid);

        wpid = waitpid(tempid, NULL, WNOHANG);                          //指定一个进程回收，不阻塞
        // wpid = waitpid(tempid, NULL, 0);                                 //指定过一个进程回收，阻塞回收
        if (wpid == -1) {
            perror("waitpid error");
            exit(1);
        }
        printf("I'm parent, wait a child finish : %d\n", wpid);
    }
    else {
        sleep(i);
        printf("I'm %dth child, pid = %d\n", i + 1, getpid());
    }

    return 0;
}