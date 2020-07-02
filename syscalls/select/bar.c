#include "bar.h"

#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

static int g_fd = 0;

const char filename[] = "file.socket";

int fileopen(){
	g_fd = open(filename, O_RDWR, 0666);
	if (g_fd == -1){
		perror("open");
		return -1;
	}

	return 0;
}

void select_read(){
	
	fd_set readset;
	struct timeval t;
	int ret;
	
	FD_ZERO(&readset);
	FD_SET(g_fd, &readset);

	t.tv_sec = 5;
	t.tv_usec = 0;

	if ((ret = select(g_fd + 1, &readset, NULL, NULL, &t)) == -1){
		perror("select");
		goto exit;
	}

	if (!ret) printf("%ld seconds elapsed\n", t.tv_sec);

	if(FD_ISSET(g_fd, &readset)){
	/*let's read if ready*/ 	
		char buf[1024];
		int len;

		len = read(g_fd, buf, 1024);

		if (len == -1){
			perror("read");
			goto exit;
		}

		buf[len] = '\0';

		printf("buf: %s", buf);
	}

exit:
	printf("exit\n");
}

int run() {
	if (fileopen() == -1) return -1;

	select_read();
}
