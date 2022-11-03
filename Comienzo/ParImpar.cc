

//pedir un numero y escribir si el numero escrito es par o impar

#include <stdio.h>

int valor;

int main(){

	printf("\n Introduzca valor a evaluar: ");
	scanf("%d",&valor);

	if(valor%2==0){
		printf("\n %d es un numero par\n",valor);
	}else if(valor%2!=0){
		printf("\n %d es un numero impar\n",valor);
	}	
		
	return 0;
}