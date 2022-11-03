/* implementar programa en c que pregunte 5 valores enteros y una vez hecho,
se borre la pantalla y se escriban los 5 valores que el usuario a introducido*/


#include <stdio.h>
#include <stdlib.h>


int numeros[4];


void AceptarDatos(){
  for(int i=0;i<5;i++){
    printf("\n Introduzca valor %d:  ", i+1);
    scanf("%d", &numeros[i]);
  }
}

void MuestraDatos(){
  printf("\n");
  for(int i=0;i<5;i++){
    printf(" El valor %d es %d \n", i+1,numeros[i]);
  }
}

int main(){

  AceptarDatos();
  system("cls");
  MuestraDatos();

  return 0;
}
