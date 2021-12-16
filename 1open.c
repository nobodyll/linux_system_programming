#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int fd;
	// fd = open("./dict.txt", O_RDONLY);
	fd = open("./dict.cp", O_RDONLY |  O_CREAT, 0644);
	printf("fd = %d, errno = %d:%s\n", fd, errno, strerror(errno));
	close(fd);
	return 0;
}
