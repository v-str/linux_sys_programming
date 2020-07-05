#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {

	FILE * f = fopen("lorem_ipsum", "r");

	if (!f) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	fseek(f, 0, SEEK_END);
	size_t fsz = ftell(f);
	rewind(f);

	printf("fsz: %ld b\n", fsz);

	for (size_t i = 0; i < fsz; ++i){
		int ch = fgetc(f);

		if (ch == EOF){
			printf("fgetc: EOF\n");
			break;
		} else {
			printf("%c", (char) ch);
		}
	}

	return 0;
}
