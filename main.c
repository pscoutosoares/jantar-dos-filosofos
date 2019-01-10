#include <stdio.h>
#include <stdlib.h>

#define N_FILOSOFOS 5
#define COMENDO 0
#define PENSANDO 1 
#define FOME 2



typedef struct Filosofo{
	int index;
	int estado;
};

typedef struct Garfo{
	int index;
}

Filosofo mesa[N_FILOSOFOS];

void criar_Filosofos();
void rodar_Filosofo();
void pegar_garfo_esq(int index_filosofo);
void pegar_garfo_esq(int index_filosofo);
