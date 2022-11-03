


#include <stdio.h>
#include <stdlib.h>



int numero;


void AceptarDatos(){
  printf(" Numero:  ");
  scanf("%d", &numero);
}

float factorial(float x){
  if(x==0){
    return 1;
  }
  else{
    return x*factorial(x-1);
  }
}


int main(){

  AceptarDatos();
  factorial(numero);

  return 0;
}
