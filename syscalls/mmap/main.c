#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {

	long pagesize_l = sysconf(_SC_PAGESIZE);
	int pagesize_i = getpagesize();

	printf("page sz: %ld\n", pagesize_l);

	int fd = open("lorem_ipsum", O_RDONLY);

	if ( fd == -1 ){
		perror("open");
		return 1;
	}

	struct stat stbuf;

	if ( stat("lorem_ipsum", &stbuf) == -1 ) {
		perror("stat");
		return 1;
	}

	printf("file 'lorem_ipsum' size: %ld bytes\n", stbuf.st_size);

	void * ptr = mmap(NULL, stbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	close(fd);

	printf("your mmap:\n%s", (char*)ptr);

	return 0;
}
