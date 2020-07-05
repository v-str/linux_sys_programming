#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define FILENAME "lorem_ipsum"

void fseekwrap(FILE * stream, long offs, int origin){ 
	if ( fseek(stream, 0L, SEEK_END) == -1 ) {
		perror("fseek");
		exit(EXIT_FAILURE);
	}
}

size_t ftellwrap(FILE * stream){
	size_t filesize = ftell(stream);
	if ( filesize == -1 ){
		perror("fseek");
		exit(EXIT_FAILURE);
	}
	return filesize;
}

void freadwrap(FILE * stream, size_t size){
	rewind(stream);
	char text[size];
	size_t res = fread(text, sizeof (char), size, stream);
	printf("text:\n%s", text);
}

int main() {

	FILE * fstream = fopen(FILENAME, "r");
	if ( !fstream ) {
		perror ("fopen");
	} else {
		printf("file opened.\n");
		fseekwrap(fstream, 0L, SEEK_END);
		size_t filesize = ftellwrap(fstream);
		printf("fizesize: %ld\n", filesize);
		freadwrap(fstream, filesize);
		fclose(fstream);
		printf("file closed.\n");
	}

	return 0;
}
