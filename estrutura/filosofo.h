
#include <stdio.h>
#include <stdlib.h>


/* Estrutura de filosofos que se conecta com um garfo da esquerda e outro da direita
O filósofo possui um index próprio para facilitar a busca por ele no futuro. */
typedef struct filosofo{
	struct garfo *garfo_esq;
	struct garfo *garfo_dir;
	int index;

}filosofo;

/* A estrutura de garfo é semelhante a de filósofo, mas possui no lugar de um index um inteiro
que destingue se este garfo está sendo utilizado ou não. */
typedef struct garfo{
	filosofo *fil_esq;
	filosofo *fil_dir;

	//Garfo está sendo usado? 1 == True / 0 == False
	int usando;
}garfo;


//Mesa funciona como o inicio da estrutura, ela possui o primeiro nó representado por um filosofo de index 1.
typedef struct mesa{
	filosofo *primeiro;
}mesa;


//inicializa o grafo ciclico representando uma mesa e retorna a estrutura inicializada(alocada)
mesa * InicializarMesa(void);

/* A estrutura de dados utilizada é um grafo ciclico (pode ser visto como uma lista duplamente encadeada ciclica)
de modo que existem dois tipos de nós, garfos e filosofos. Cada filósofo está conectado a dois garfos e, portanto,
dois garfos a dois filosofos. As estruturas podem ser vistas no header do código. */
void OcuparMesa(mesa *vazia);

//cria nós, filosofos e garfos.
filosofo * CriarFilosofo(garfo *esq, garfo *dir, int index);
garfo * CriarGarfo(filosofo *esq, filosofo *dir);

//Busca o filósofo pela sua index
filosofo * BuscarFilosofo(mesa *mesa_cheia, int index_filosofo);

//Filosofo indica intenção de comer e levanta os garfos se disponiveis.
void Comer(filosofo *fil);

//Filosofo começa pensando, sem entrar na região critica
void Pensar(filosofo *fil);

//Escopo em qual o filosofo se encontrará, desde pensar a comer
void rodar_filosofo(filosofo *filosofo_atual);


