all: example
example: main.c filosofo.c filosofo.h 
	gcc -g -o example main.c filosofo.c filosofo.h 
clean:
	rm	example filosofo.h.gch 
test:  example
		./example
