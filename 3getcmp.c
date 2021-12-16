#include <stdlib.h>
#include <stdio.h>
int main() {
    FILE * fp, *fp_out;
    int n = 0;
    fp = fopen("test.c", "r");
    if (fp == NULL) {
        perror("fopen error");
        exit(1);
    }
    fp_out = fopen("test.c.backup", "w");
    if (fp_out == NULL) {
        perror("fopen error");
        exit(1);
    }
    while ((n = fgetc(fp)) != EOF) {
        fputc(n, fp_out);
    }

    fclose(fp);
    fclose(fp_out); 
    return 0;
}
