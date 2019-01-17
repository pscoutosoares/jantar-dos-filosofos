#include <stdio.h>
#include "filosofo.h"



int main(){
		mesa *nova_mesa = InicializarMesa();
		filosofo *filosofo_1;
    filosofo *filosofo_2;
    filosofo *filosofo_3;
    filosofo *filosofo_4;
    filosofo *filosofo_5;
	
	
    printf("Inicio");
		OcuparMesa(nova_mesa);
    filosofo_1 = BuscarFilosofo(nova_mesa,1);
    filosofo_2 = BuscarFilosofo(nova_mesa,2);
    filosofo_3 = BuscarFilosofo(nova_mesa,3);
    filosofo_4 = BuscarFilosofo(nova_mesa,4);
    filosofo_5 = BuscarFilosofo(nova_mesa,5);
	
    
    while(1){
        rodar_filosofo(filosofo_1);
        rodar_filosofo(filosofo_2);
        rodar_filosofo(filosofo_3);
        rodar_filosofo(filosofo_4);
        rodar_filosofo(filosofo_5);
    }
}
