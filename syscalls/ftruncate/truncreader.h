#ifndef TRUNCREADER_H
#define TRUNCREADER_H

int fileopen(const char * name);
void fileread(int fd, off_t trunc_len);

#endif // TRUNCREADER_H
