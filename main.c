#include <lpc2103.h>
#include <stdio.h>
#include <stdlib.h>
#include <mutex.h>
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
};

Filosofo mesa[N_FILOSOFOS];

void criar_Filosofos(int n_Filosofos);
void rodar_Filosofo(int index_filosofo);
void tentar_pegar_garfos();
void pegar_garfo_esq(int index_filosofo);
void pegar_garfo_esq(int index_filosofo);
void soltar_garfos(int index_filosofo);
void comer ( int id_filosofo );
void pensar ( int id_filosofo );


void rodar_Filosofo(int index_filosofo){
	int index_filosofo
	printf("Filosofo %d iniciado!\n", index_filosofo);
	while(true){
		pensar(index_filosofo);
		tentar_pegar_garfos(index_filosofo);
		comer(index_filosofo);
		soltar_garfos(index_filosofo);
	}
}

void criar_Filosofos(){
	//index dos filosofos são os números impares do range(1,10)
	int cont_aux = 0;
	for (int i=1; i<=N_FILOSOFOS*2; i++){
		if(i%2!=0){
			Filosofo filosofo;  //criando filosofo
			filosofo.index = i; 
			mesa[cont_aux]=filosofo; //add filosofo no vetor de filosofos criados
			printf("Filosofo %d criado!\n", i);
			cont_aux++
		}
	}

	//iniciando filosofos
	for (int i=1; i<=N_FILOSOFOS; i++){
		//THREAD AQUI
		rodar_Filosofo(mesa[i].index);
	}

}
