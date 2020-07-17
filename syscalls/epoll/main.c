#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	int fd = open ("file.txt", O_RDONLY);

	if ( fd == -1 ){
		perror("open");
		return 1;
	}

	int epoll_fd = epoll_create(1); // argument must be greater than zero

	if ( epoll_fd == -1 ){
		perror("epoll_create");
		return 1;
	}

	struct epoll_event ev;
	ev.events = EPOLLIN;

	if ( epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1 ){
		perror("epoll_ctl");
		if ( errno == EPERM ) {
			printf("it is regular file, exit\n");
		}
		return 1;
	}

	printf ("exit\n");

	if ( close(fd) == -1 ){
		perror("mamma mia, 'close' error:");
		return 1;
	}

	return 0;
}
