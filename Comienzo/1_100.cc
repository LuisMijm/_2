
//el usuario solo puede introudcir numeros entre el 1 y el 100.


#include <stdio.h>



int maximo, minimo, valor;


void Iniciar(){

	do{
		printf("\n Introduzca un valor entre 1 y 100:  ");
		scanf("%d", &valor);
		maximo = valor;
		minimo = valor;
		if(valor < 0 || valor > 100){printf("Error de selección");}
	}while(valor < 0 || valor > 100);
}

void Ciclo(){

	if(valor!=0){
		do{
			do{
				printf("\n Introduzca un valor entre 1 y 100:  ");
				scanf("%d", &valor);
				if(valor < 0 || valor > 100){printf("Error de selección");}
			}while(valor < 0 || valor > 100);
			if(valor>maximo){maximo = valor;}
			else if(valor<minimo && valor!=0){minimo = valor;}

		}while(valor!=0);
	}
}

void Pintado(){
	printf("\n Los valores maximo y minimo introducidos han sido: %d y %d \n",
					maximo, minimo);
}



int main(){

	Iniciar();
	Ciclo();
	Pintado();


return 0;
}
