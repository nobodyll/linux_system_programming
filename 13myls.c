#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
int main(int argc, const char * argv[]) {

    DIR * dp = opendir(argv[1]);
    if (dp == NULL) {
        perror("open dir error");
        exit(1);
    }

    struct dirent * sdp; 
    while ((sdp = readdir(dp)) != NULL) {
        printf("%s\t\n", sdp->d_name);
    }
    printf("\n");
    closedir(dp);
    return 0;
}