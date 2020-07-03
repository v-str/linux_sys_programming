sources := $(wildcard *.c)
includes := $(wildcard *.h)
app := app

default: $(sources)
	gcc -g $^ -o $(app)

clean:
	rm -rf $(app)
	rm -rf *.o


