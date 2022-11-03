
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


const int size=7;
int valor1[size]={0,0,1,0,1,0,1}, valor2[size]={0,0,1,1,0,1,1},
    resultado[size]={0,0,0,0,0,0,0}, carry[size]={0,0,0,0,0,0,0};


// void SumaBinaria(){
//   for(int i=size-1;i>=0;i++){
//     if(i>0){
//       if(valor1[i]==1 && valor2[i]==1){
//         resultado[i]=0;
//         carry=1;
//       }
//     }
//   }
// }

void SumaBinaria(){
  for(int i=size-1;i>0;--i){
    resultado[i] = valor1[i]+valor2[i]+carry[i];
    switch (resultado[i]){
      case 2: resultado[i]=0;carry[i-1]=1;break;
      case 3: resultado[i]=1;carry[i-1]=1;break;
    }
  }
}


void MostrarDatos(int numero[size]){
  printf("\n ");
  for(int i=0;i<size;i++){
    printf("%d", numero[i]);
  }
}



int main(){
  system("cls");
  SumaBinaria();
  MostrarDatos(carry);
  MostrarDatos(valor1);
  MostrarDatos(valor2);
  printf("\n");
  MostrarDatos(resultado);


  return 0;
}
