#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "truncreader.h"

#define FILENAME "lorem_ipsum"

int main(){

	int fd = fileopen(FILENAME);

	int trunc[10] = { 614, 512, 256, 128, 64, 32, 16, 8, 4, 2};

	for (int i = 0; i < 10; i++){	
		lseek(fd, 0, SEEK_SET);
		fileread(fd, (off_t) trunc[i]);
	}

	return 0;
}
