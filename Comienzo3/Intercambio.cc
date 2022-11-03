/* dos variables enteras globales siendo numero1 y numero2. Procedimiento
"LeerVariables" que las acepte por teclado. Procedimiento "MuestraVariables",
que las muestre por pantalla */

#include <stdio.h>
#include <stdlib.h>

int numero1, numero2;

void LeerDatos(){
  printf(" Numero 1:  ");
  scanf("%d", &numero1);
  printf(" Numero 2:  ");
  scanf("%d", &numero2);
  printf("\n");
}

void Intercambio(int *primero, int *segundo){
  int aux = *primero;
  *primero = *segundo;
  *segundo = aux;
}

void MuestraVariables(){
  printf(" %d y %d \n", numero1, numero2);
}


int main(){

  LeerDatos();
  MuestraVariables();
  Intercambio(&numero1,&numero2);
  MuestraVariables();


  return 0;
}
