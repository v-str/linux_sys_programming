#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "app.journal"
#define MAGIC 2

static int fd_ = -1;
static char process_name_[10];

void process_cmd(char * argv[]){
	strcpy(process_name_, argv[0]);
}

void get_fd(){
	fd_ = open (FILENAME, O_WRONLY | O_APPEND);
	if (fd_ == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("%s opened, fd: %d\n", FILENAME, fd_);
}

void close_fd(){
	close(fd_);
	if (fd_ == -1){
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("%s closed, fd: %d\n", FILENAME, fd_);
}

char * get_random(){
	char * buf = malloc(2);
	int n = rand() % 101;
	sprintf(buf, "%d", n);
	return buf;
}

void write_to_journal(){
	int record_num = 0, counter = 10;
		while(counter){

		char text[100];

		strcpy(text, "process: ");
		strcat(text, process_name_);

		char * buf = get_random();

		strcat(text, " ");
		strcat(text, buf);
		strcat(text, "\n");

		write(fd_, text, strlen(text));

		counter--;
		sleep(MAGIC);
		free(buf);
	}
}

int main(int argc, char * argv[]) {

	/* Intializes random number generator */
	srand(time(0));

	get_fd();
	process_cmd(argv);
	write_to_journal();
	close_fd();

	return 0;
}
