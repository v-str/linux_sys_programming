#include "func.h"

#include <stdio.h>

static int checkargs(int argc, char *argv[]){
	if (argc > 1){
		return 1;
	}
	return 0;
}

int main(int argc, char * argv[]){

	if (checkargs(argc, argv)) run(argv[1]);

	return 0;
}
