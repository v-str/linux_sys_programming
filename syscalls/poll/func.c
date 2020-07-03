#include "func.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static int g_fd;

static int openfile(const char * filename){

	if ((g_fd = open(filename, O_RDWR)) == -1) {
		perror("open");
		return -1;
	}

	return 0;
}

void polling(){
	struct pollfd fds[0];
	fds[0].fd = g_fd;
	fds[0].events = POLLIN | POLLWRBAND;

	while(true){
		sleep(2);
		printf("begin of while loop\n");
		int ret = poll(fds, 1, 5);
		printf("ret = %d\n", ret);
		if (ret > 0){
			if (fds[0].revents & POLLIN){
				printf("file is ready to read\n");

				char buf[1024];

				int ret = read(g_fd, buf, 1024);

				if (ret == -1){
					perror("read");
					break;
				} else {
					//buf[1024] = '\0';
					printf("data: %d bytes\n", ret);
					printf("TEXT: %s\n", buf);
				}

				printf("readed\n");

			}
		} else if (ret < 0){
			perror("poll");
			break;
		}
		printf("end of while loop\n");
		printf("ret = %d\n", ret);
	}
}

void run(const char * filename) {
	if(openfile(filename) == 0){
		printf("file opened.\n");

		polling();

		close(g_fd);
		printf("file closed.\n");
	}
}
