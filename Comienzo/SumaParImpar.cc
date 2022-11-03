
/*
programa en c que pregunte por un valor limite. 
Una vez introducido mostrar la suma de los numeros pares y 
otra suma con los valores impares. 
*/



#include <stdio.h>


int limite, t_pares, t_impares;


void AceptarDatos(){
	
	printf("\n Introduzca valor límite:  ");
	scanf("%d", &limite);
	printf("\n");
}

void Conteo(){
	
	for(int i=0;i<=limite;i++){
		if(i%2==0){
			t_pares+=i;
		}else{
			t_impares+=i;
		}
	}
	
}

void Mostrar(){
	printf("\n La suma de los valores pares es: %d \n", t_pares);
	printf("\n la suma de los valores impares es: %d \n", t_impares);
		
}



int main(){
	
	AceptarDatos();
	Conteo();
	Mostrar();

return 0;
}

