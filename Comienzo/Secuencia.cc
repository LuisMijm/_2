//implementar un programa en c que pregutne al usuario un avlor limite y pregunte
//por pantalla todos los numeros desde el 1 hasta el valor limite



#include <stdio.h>

int limite;


void Iniciar(){
	printf("\n Introduzca valor límite:  ");
	scanf("%d", &limite);
}

void Ciclo(){
	
	int contador=0;
	
	do{
		contador++;
		printf(" %04d ", contador);
		if(contador%10==0){printf("\n");}
	}while(contador<limite);
}


int main(){
	
	Iniciar();
	Ciclo();


return 0;
}