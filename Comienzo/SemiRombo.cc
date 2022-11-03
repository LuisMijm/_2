



#include <stdio.h>
#include <stdlib.h>


int limite;

void AceptarDatos(){
	
	printf("\n Introduzca límite:  ");
	scanf("%d", &limite);
	system("cls");

}

void Superior(){
	
	for(int i=1;i<=limite;i++){
		for(int j=1;j<=i;j++){
			printf("%d",j);
		}
		printf("\n");
	}	
}

void Inferior(){
	for(int i=limite-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			printf("%d",j);
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