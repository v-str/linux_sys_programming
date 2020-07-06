#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main() {

	FILE * f = fopen("my_text", "w+");

	if (!f){
		perror("fopen");
		return 1;
	}

lock_file:

	if (ftrylockfile(f) == 0){
		fputs("File steam blocked.\n", f);
		fputs("Now you can write all what you want.\n", f);
		fputs("And you can be confident that another thread NOT\n", f);
		fputs("interrupt your input. That's pretty well.\n", f);

		funlockfile(f);
	} else {
		goto lock_file;
	}

	return 0;
}
