

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//Globales

int g_intentos_t,g_puntuacion;
bool g_victoria=false;


void MuestraIntentos(){
  printf(" Indique intentos totales:\n  ");
  scanf("%d", &g_intentos_t);
}


void Comprobaciones(int valor, int correcto, int contador){
  if(valor<1 || valor>100){printf(" Intento desperdiciado\n");}
  if(valor>correcto){printf(" Demasiado alto\n");}
  if(valor<correcto){printf(" Demasiado bajo\n");}
  if(valor==correcto){
    g_puntuacion = (g_intentos_t-contador)*1000;
    printf(" Acertado");
  }
}


void Juego(){
  int l_correcto=(rand()%99 + 1), l_valor, l_contador=1;
  printf("\n Comencemos\t");
  do{
    printf("%d\n", l_correcto);
    printf("\n Intento: %d\n", l_contador);
    printf(" Numero: ");
    scanf("%d", &l_valor);
    Comprobaciones(l_valor,l_correcto,l_contador);
    l_contador++;
  }while(l_contador <= g_intentos_t || l_valor!=l_correcto);
}


void Resultado(){
  switch (g_victoria) {
    case 0: printf("\n Intentos maximos superados.\n Partida perdida\n");break;
    case 1: printf(" Victoria\n Puntuacion: %d", g_puntuacion);break;
  }
}


int main(int argc, char **argv) {

  MuestraIntentos();
  Juego();
  Resultado();

  return 0;
}
