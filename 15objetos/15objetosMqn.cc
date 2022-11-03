
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Globales
int g_restantes=15, valor;

void JugadaTrucada(){
  printf("\n Comienza la maquina: elije 2\n\n");
  g_restantes-=2;
}

void JugadaMaquina(){
  printf("\n La maquina elije: %d\n\n", 4-valor);
  g_restantes-=(4-valor);
}

void JugadaJugador(int turno){
  do{
    printf("\n Jugador %d elija un número 1,2 o 3:  ", turno);
    scanf("%d", &valor);
    printf("\n");
    if(valor != 1 && valor != 2 && valor != 3){printf(" Error de selección\n");}
  }while(valor != 1 && valor != 2 && valor != 3);
    // printf("hola\n");
  g_restantes-=valor;
}


void PintaLineas(){
  for(int i=1;i<=g_restantes;i++){
	printf(" | ");
  }
  if(g_restantes<0){g_restantes=0;}
  printf(" (%d) \n", g_restantes);
}

void CompruebaFinal(){
  if(g_restantes<=0){
    printf("\n No quedan objetos, has perdido\n");
  }else{
    printf("\n Siguiente turno\n");
  }
}

void Juego(){

  char selector;
  system("cls");
  printf("\n Seleccione modo solitario (s) o multijugador (m):  ");
  do{
    scanf("%c", &selector);
  }while(selector!='s' && selector!='m');
  system("cls");

  switch (selector) {
    case 's':
      JugadaTrucada();
        PintaLineas();
        do{
          JugadaJugador(1);
          PintaLineas();
          if(g_restantes>0){
            JugadaMaquina();
            PintaLineas();
          }
          CompruebaFinal();
        }while(g_restantes>0);
        break;
    case 'm':
      do{
        JugadaJugador(1);
        PintaLineas();
        CompruebaFinal();
        JugadaJugador(2);
        PintaLineas();
        CompruebaFinal();
      }while(g_restantes>0);
  }

}



int main(){

  Juego();

  return 0;
}
