#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#pragma pack(1)
struct bin {
	int a;
	double b;
	char c;
	float d;
	int f;
};
#pragma pack()

void print_bin(const struct bin * binstr){
	printf("bin->a = %d\n", binstr->a);
	printf("bin->b = %f\n", binstr->b);
	printf("bin->c = %c\n", binstr->c);
	printf("bin->d = %f\n", binstr->d);
	printf("bin->f = %d\n", binstr->f);
}

int main () {

	FILE * f = fopen("bin.text", "w+");

	if (!f) return 1;

	struct bin simple;

	simple.a = 10;
	simple.b = 11.1;
	simple.c = '5';
	simple.d = 1.1;
	simple.f = 100;

	size_t binsz = sizeof(simple);
	printf("sizeof bin struct: %ld\n", binsz);

	size_t ret = fwrite(&simple, binsz, 1, f);
	if (ret == 0) printf("smth wrong!\n");

	fclose(f);

	f = fopen("bin.text", "r");

	sleep(2);

	struct bin res_simple;
	ret = fread(&res_simple, binsz, 1, f);

	if ( ret == binsz ) printf("binary file was read\n");
	else printf("ret = %ld\n", ret);

	print_bin(&res_simple);

	return 0;
}
















