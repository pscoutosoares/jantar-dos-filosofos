all: example
example: filosofo.c filosofo.h
	gcc -g -o example filosofo.c filosofo.h
clean:
	rm	example filosofo.h.gch 
test:  example
		./example
