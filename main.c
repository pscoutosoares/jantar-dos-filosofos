#include <stdio.h>
#include <stdlib.h>
#include <mutex.h>
#include <pthread.h>
#include <unistd.h>

#define N_FILOSOFOS 5
#define COMENDO 0
#define PENSANDO 1 
#define FOME 2

pthread_t thread_filosofo[N_FILOSOFOS]; //instacias da struct das thread que serao iniciadas

typedef struct Filosofo{
	int index;
	int estado;
};

typedef struct Garfo{
	int index;
};

Filosofo mesa[11];

void criar_Filosofos();
void rodar_Filosofo(int index_filosofo);
//void tentar_pegar_garfos();
//void pegar_garfo_esq(int index_filosofo);
//void pegar_garfo_dir(int index_filosofo);
//void soltar_garfos(int index_filosofo);
void comer ( int id_filosofo );
void pensar ( int id_filosofo );


void *rodar_Filosofo(void *param){
	int * index_filosofo = (int *) (param);
	printf("Filosofo %d iniciado!\n", index_filosofo);
	while(true){
		pensar(index_filosofo);
		//tentar_pegar_garfos(index_filosofo);
		comer(index_filosofo);
		//soltar_garfos(index_filosofo);
	}
}

void criar_Filosofos(){
	//index dos filosofos são os números impares do range(1,10)
	for (int i=1; i<=N_FILOSOFOS*2; i++){
		if(i%2!=0){
			Filosofo filosofo;  //criando filosofo
			filosofo.index = i; 
			mesa[i]=filosofo; //add filosofo no vetor de filosofos criados
			printf("Filosofo %d criado!\n", i);
			cont_aux++
		}
	}

	//iniciando filosofos
	pthread_create( &(thread_filosofo[0]), NULL, rodar_Filosofo, (void *) &(1) );
	pthread_create( &(thread_filosofo[1]), NULL, rodar_Filosofo, (void *) &(3) );
	pthread_create( &(thread_filosofo[2]), NULL, rodar_Filosofo, (void *) &(5) );
	pthread_create( &(thread_filosofo[3]), NULL, rodar_Filosofo, (void *) &(7) );
	pthread_create( &(thread_filosofo[4]), NULL, rodar_Filosofo, (void *) &(9) );

}

void comer(int index_filosofo){
	//passa estado para comendo
	mesa[index_filosofo].estado = COMENDO;
	printf("Filosofo %d está COMENDO!\n", index_filosofo);
	sleep(2);


}

void pensar(int index_filosofo){
	//passa estado para comendo
	mesa[index_filosofo].estado = PENSANDO;
	printf("Filosofo %d está PENSANDO!\n", index_filosofo);
	sleep(2);
}

void main(){
	criar_Filosofos();



}