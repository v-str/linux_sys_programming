#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGS O_RDWR
#define FILENAME "lorem_ipsum"

int fileopen(const char * name){
	int fd;
	if((fd = open(name, FLAGS)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	} 
	return fd;
}

void fileread(int fd, off_t trunc_len){

	if (ftruncate(fd, trunc_len) == -1) {
		perror("truncate");
		exit(EXIT_FAILURE);
	}

	char buf[trunc_len];
	
	if (read(fd, buf, trunc_len) == -1){
		perror("read");
		exit(EXIT_FAILURE);
	}

	printf("truncated to %ld length:\n%s\n", trunc_len, buf);
}

int main(){

	int fd = fileopen(FILENAME);

	int trunc[10] = { 614, 512, 256, 128, 64, 32, 16, 8, 4, 2};

	for (int i = 0; i < 10; i++){	
		lseek(fd, 0, SEEK_SET);
		fileread(fd, (off_t) trunc[i]);
	}


	return 0;
}
