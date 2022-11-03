
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Globales
int g_restantes=15;


void Jugada(){
  int aux=0;
  do{
    printf("\n Elija un número 1,2 o 3:  ");
    scanf("%d", &aux);
    printf("\n");
    if(aux != 1 && aux != 2 && aux != 3){printf("Error de selección\n");}
  }while(aux != 1 && aux != 2 && aux != 3);
    // printf("hola\n");
  g_restantes-=aux;
}


void PintaLineas(){
  for(int i=1;i<=g_restantes;i++){
	printf(" | ");
  }
  printf(" (%d) \n", g_restantes);
}

void CompruebaFinal(){
  if(g_restantes<=0){
    printf("\n No quedan objetos, has perdido\n");
  }else{
    printf("\n Siguiente turno\n");
  }
}



int main(){

  do{
    Jugada();
    PintaLineas();
    CompruebaFinal();
  }while(g_restantes>0);

  return 0;
}
