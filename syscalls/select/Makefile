name := app

sources := $(wildcard *.c)
includes := $(wildcard *.h)

default: $(sources)
	gcc -g -o $(name) $^ $(includes)

clean:
	rm -rf $(name)
