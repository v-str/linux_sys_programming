#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES 10
#define FILENAME "file.txt"
#define FILE_COUNT 28
#define UMASK 0640

static int bytes = 0;
static int fd = 0;

void process_cmd(int argc, char *argv[]);

void safe_read();

int main(int argc, char *argv[]) {

  process_cmd(argc, argv);

  fd = open(FILENAME, O_RDWR);
  if (fd == -1) {
    perror(FILENAME);
    return 1;
  } else {
	if (bytes){
	  safe_read();
	} else {
	  printf("usage: %s <bytes count>\n", argv[0]);
	}
  }

  return 0;
}

void process_cmd(int argc, char *argv[]) {
  if (argc > 1) {
	sscanf(argv[1], "%d", &bytes);
  }
}

void safe_read(){
	char buf[bytes];
	int ret = 0;

read_point:
	ret = read(fd, buf, bytes);

	if (ret == -1){
		perror("read");
		if (errno == EINTR) {
			goto read_point;
		}
	}

	buf[bytes-1] = '\0';
	puts(buf);
}


