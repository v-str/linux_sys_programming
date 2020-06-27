#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "text.txt"

static const int count = 10;

int main(){

	int fd = open(FILENAME, O_RDONLY);
	
	if (fd == -1){
		perror("text.txt");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < count; ++i){
		lseek(fd, 21, SEEK_SET);
		int len = 53;
		char text[len];
		int ret = read(fd, text, len);

		printf("text: %s\n", text);
	}

	return 0;
}
