

//Preguntar numeros hasta introudcir el valor 0. Una vez ocurra, escribir el valor maximo y el valor minimo que el usuario a introducido.

#include <stdio.h>



int maximo, minimo, valor;

void Iniciar(){
	
	printf("\n Introduzca un valor ");
	scanf("%d", &valor);
	maximo = valor;
	minimo = valor;
	
}

void Ciclo(){
	
	if(valor!=0){
		do{
			printf("\n Introduzca un valor ");
			scanf("%d", &valor);
			if(valor>maximo){maximo = valor;}
			else if(valor<minimo && valor!=0){minimo = valor;}
		}while(valor!=0);
	}
}

void Pintado(){
	
	printf("\n Los valores maximo y minimo introducidos han sido: %d y %d \n", maximo, minimo);
	
}



int main(){

	Iniciar();
	Ciclo();
	Pintado();
	

return 0;
}