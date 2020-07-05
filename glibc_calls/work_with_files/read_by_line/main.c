#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int main() {

	FILE * f = fopen("lorem_ipsum", "r");

	char buf[LINE_MAX];

	printf("LINE_MAN = %d\n", LINE_MAX);

	while (fgets(buf, LINE_MAX, f) != NULL){
		printf("%s", buf);
	}

	return 0;
}
