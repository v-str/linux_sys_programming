cflags := -g -Wall

src := $(wildcard *.c)
includes := truncreader.h

default: $(src)
	gcc -o app $^ $(cflags) 
	cp ../lorem_ipsum .

clean:
	rm app lorem_ipsum
