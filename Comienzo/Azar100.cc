

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//printf("Valor aleatorio generado %d",rand()%100);


void Ciclo(){

	int contador = 0, limite = 1 + rand()%100;

	do{
		contador++;
		printf(" %04d ", contador);
		if(contador%10==0){printf("\n");}
	}while(contador<limite);
}

int main(){

  srand(time(NULL));

	Ciclo();



return 0;
}
