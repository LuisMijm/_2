/*generar 1000 numeros aleatorios.
cada uno tiene que estar comprendido entre 1 y 100.
cuando acabe de contar tiene que mostrar la cantidad de vecees que ha
aparecido cada numero y cuales han sido los numeros que mas y
menos han aparecido*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int numeros[100];

void Asignar(){
  for(int i=0;i<=100;i++){
    numeros[i]=0;
  }
}

void GeneraNumeros(){
  for(int i=0;i<1000;i++){
    numeros[rand()%100]++;
  }
}

void MuestraNumeros(){
  int menor=0, mayor=0;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if(numeros[i]<numeros[j]){menor=numeros[i];}
      if(numeros[i]>numeros[j]){mayor=numeros[i];}
    }
    if(i%10==0){printf("\n");}
    printf("[%03d]: %03d  ", i+1,numeros[i]);
  }
  printf("\n Mayor frecuencia de aparicion:  %03d \n",mayor);
  printf(" Menor frecuencia de aparicion:  %03d \n",menor);
}

int main(){

  srand(time(NULL));
  system("cls");
  Asignar();
  GeneraNumeros();
  MuestraNumeros();

}
