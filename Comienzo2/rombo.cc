
/*
rombo con altura introducida por el usuario.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int altura;


void AceptarDatos(){

	printf("\n Introduzca altura:  ");
	scanf("%d", &altura);
	printf("\n\n");
}


/* funcion de mitad lateral izquierda de rombo */

// void Superior(){
//	 for(int i=altura;i>=1;i--){
// 		for(int j=1;j<=i;j++){
// 			printf(" ");
// 		}
// 		for(int j=altura;j>=i;j--){
// 			printf("*");
// 		}
// 		// for(int j=altura;j<=i;i--){
// 		// 	printf("*");
// 		// }
// 		printf("\n");
// 	}
// }
//
// void Inferior(){
// 	for(int i=1;i<=altura-1;i++){
// 		for(int j=0;j<=i;j++){
// 			printf(" ");
// 		}
// 		for(int j=altura;j>i;j--){
// 			printf("*");
// 		}
// 		printf("\n");
// 	}
// }


/* solución rombo completo */

void Superior(){
	for(int i=1;i<=altura;i++){
		for(int j=1;j<=altura+1-i;j++){
			printf(" ");
		}
		for(int j=0;j<2*i-1;j++){
			printf("*");
		}
		printf("\n");
	}
}


void Inferior(){
	for(int i=altura-1;i>0;i--){
		for(int j=altura+1-i;j>=1;j--){
			printf(" ");
		}
		for(int j=1;j<=2*i-1;j++){
			printf("*");
		}
		printf("\n");
	}
}



int main(){

	AceptarDatos();
	Superior();
	Inferior();

	return 0;
}
