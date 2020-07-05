#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int main () {

	FILE * f = fopen("lorem_ipsum", "r");

	if (!f) return 1;

	size_t ret;
	char buf[LINE_MAX];

	while ((ret = fread(buf, 1, LINE_MAX, f)) != 0){
		printf("%s", buf);	
	}

	return 0;
}
















