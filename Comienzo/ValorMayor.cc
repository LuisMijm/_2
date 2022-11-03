

//Preguntar dos numeros y decir si son iguales o alguno de ellos es mayor.


#include <stdio.h>

int g_valor1, g_valor2;


int main(){

	printf("\n Intruduzca primer valor: ");
	scanf("%d",&g_valor1);
	printf("\n Introduzca segundo valor: ");
	scanf("%d",&g_valor2);
	
	if(g_valor1>g_valor2){
		printf("\n El valor %d es mayor que el valor %d \n", g_valor1,g_valor2);
	}else if(g_valor1<g_valor2){
		printf("\n El valor %d es mayor que el valor %d \n", g_valor2,g_valor1);
	}else if(g_valor1 == g_valor2){
		printf("\n Ambos valores son igual \n");
	}

	return 0;
}