#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

	int fd = creat("test.file", 0666);

	if (fd == -1){
		perror("creat");
		exit(EXIT_FAILURE);
	}

	char *buf[] = {
		"Hello, this is new programm for writev syscall.\n",
		"This is very usefull syscall.\n",
		"It can write all buffer by one command.\n"
	};

	struct iovec iov[3];

	for (int i = 0; i < 3; ++i){
		iov[i].iov_base = buf[i];
		iov[i].iov_len = strlen(buf[i]);
	}

	size_t res = writev(fd, iov, 3);

	if (res == -1) {
		perror("writev");
		exit(EXIT_FAILURE);
	} else {
		printf("%lu bytes was wrote to file with %d fd\n", res, fd);
	}
		
	return 0;
}
