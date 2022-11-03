#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

	srand (time(NULL)); //Generamos nueva semilla aleatoria para obtener valor
	printf("Valor aleatorio generado %d",rand()%100);
	
	
	return 0;
}