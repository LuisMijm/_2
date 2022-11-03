/* generar matriz de num aleatorios de 10x10 de valores entre 0 y 9 con una
linea extra que muestre la suma de cada fila y una de cada columna. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size=21;
int numeros[size][size];


void Iniciar(){
  for(int i=0;i<size;++i){
    for(int j=0;j<size;++j){
      numeros[i][j]=0;
    }
  }
}
void GenerarNumeros(){
  for(int i=0;i<size-1;++i){
    for(int j=0;j<size-1;++j){
      numeros[i][j]=rand()%10;
      numeros[i][size-1]+=numeros[i][j];
      numeros[size-1][j]+=numeros[i][j];
      numeros[size-1][size-1]+=numeros[i][size-1]+numeros[size-1][j];
    }
  }
}


void MuestraMatriz(){
  system("cls");
  printf("\n\n Matriz aleatoria\n\n");
  for(int i=0;i<size;++i){
    for(int j=0;j<size;++j){
      printf(" [%03d]", numeros[i][j]);
    }
    printf("\n");
  }
}

int main(){
  srand(time(NULL));

  GenerarNumeros();
  MuestraMatriz();

  return 0;
}
