#include "filosofo.h"
#include <stdio.h>
#include <stdlib.h>

//inicializa uma estrura de mesa, onde um de seus valores é o ponteiro para o primeiro filósofo.
mesa * InicializarMesa(){
	mesa *novo = (mesa *) malloc(sizeof(mesa));
	novo->primeiro = NULL;

	return novo;
}

//Preenche a mesa com os 5 filosofos de modo que estão conectados entre si de forma duplamente encadedada.
void OcuparMesa(mesa *vazia){
	filosofo *fil_tmp;
	int i = 2;
	garfo *garfo_esq;
	
	//Cria o primeiro filosofo da mesa com index 1
	vazia->primeiro = CriarFilosofo(NULL,NULL,1);
	fil_tmp = vazia->primeiro;

	//Executa um laço que cria os demais filosofos e seus garfos.
	
	while(i<6){
		garfo_esq = CriarGarfo(NULL,fil_tmp);
		fil_tmp->garfo_esq = garfo_esq;
		fil_tmp->garfo_esq->fil_esq = CriarFilosofo(NULL,garfo_esq,i);
		fil_tmp = fil_tmp->garfo_esq->fil_esq;
		i++;
	}

	//Fecha o grafo com o nó inícial
	garfo_esq = CriarGarfo(vazia->primeiro,fil_tmp);
	fil_tmp->garfo_esq = garfo_esq;
	vazia->primeiro->garfo_dir = garfo_esq;
}

//Cria um nó de filósofo.
filosofo * CriarFilosofo(garfo *esq, garfo *dir, int index){
	filosofo *novo = (filosofo *) malloc(sizeof(filosofo));
	novo->garfo_esq = esq;
	novo->garfo_dir = dir;
	novo->index = index;
	return novo;
}

//Cria uma nó de garfo.
garfo * CriarGarfo(filosofo *esq, filosofo *dir){
	garfo *novo = (garfo *) malloc(sizeof(garfo));
	novo->fil_esq = esq;
	novo->fil_dir = dir;
	novo->usando = 0;
	return novo;
}

//Busca o filosofo pelo seu index
filosofo * BuscarFilosofo(mesa *mesa_cheia, int index_filosofo){
	int i = 0;
	garfo *no_garfo = (garfo *) malloc(sizeof(garfo));
	filosofo *no_fil = (filosofo *) malloc(sizeof(filosofo));
	
	no_fil = mesa_cheia->primeiro;

	while(no_fil->index != index_filosofo){
		no_garfo = no_fil->garfo_esq;
		no_fil = no_garfo->fil_esq;
		i++;
	}
	return no_fil;

}
//Filosofo deseja comer, verifica se os garfos estão disponíveis
void Comer(filosofo *fil){
		int x = 0;
		int randomTime = 1;
		int i;
    printf("Filosofo %d está comendo", fil->index);

    while(x != 1){
        if(fil->garfo_esq->usando == 0 ){
            fil->garfo_esq->usando = 1;
        }
        if(fil->garfo_dir->usando == 0 ){
            fil->garfo_dir->usando = 1;

            //sai do while e entra na região critica
            x = 1;
        }
        else{
            fil->garfo_esq->usando = 0;
        }
        //espera um momento para tentar comer novamente caso falhe
        randomTime = rand() %5 + 1;
        //sleep(randomTime);
				i = 0;
				while(i < randomTime*500){
					i++;
				}
    }
    //região critica
    randomTime = rand() %5 + 1;
    //sleep(randomTime);
		i = 0;
		while(i < randomTime*500){
			i++;
		}
    printf("Filosofo %d comeu", fil->index);
}
void Pensar(filosofo *fil){
	int randomTime = rand() %5 + 1;
	int i = 0;  
	printf("Filosofo %d está pensando", fil->index);
   
		while(i < randomTime*500){
			i++;
		}
    //sleep(randomTime);
}

void rodar_filosofo(filosofo *filosofo_atual){

    Pensar(filosofo_atual);
    Comer(filosofo_atual);
}
