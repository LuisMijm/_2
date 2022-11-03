
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int intento, valor, aciertos, posiciones, c1,c2,c3,c4, v1,v2,v3,v4;
bool acceso;



int GenerarNumeros(int x, int y, int z){
  int aux;
  do{
    aux = rand()%10;
  }while(aux==x || aux==y || aux==z);
  return aux;
}


void Inicializar(){

  c1 = rand()%10;
  c2 = GenerarNumeros(c1,c3,c4);
  c3 = GenerarNumeros(c1,c2,c4);
  c4 = GenerarNumeros(c1,c2,c3);

  // printf("\n %d%d%d%d\n", c1,c2,c3,c4);

  intento = 10;
  acceso = false;
}

void AceptarDatos(){
  printf("\n intento (%d) Numero:  ", intento);
  scanf("%d",&valor);
  // printf("%d\n",valor);
}

void DescomponerValor(){
  int aux;
  v1  = valor/1000;
  aux = valor%1000;
  v2  = aux/100;
  aux = aux%100;
  v3  = aux/10;
  v4  = aux%10;
}

void Comparar(){
 if(v1==c1){posiciones++;}
 if(v2==c2){posiciones++;}
 if(v3==c3){posiciones++;}
 if(v4==c4){posiciones++;}

 if(v1==c1 || v1==c2 || v1==c3 || v1==c4){aciertos++;}
 if(v2==c1 || v2==c2 || v2==c3 || v2==c4){aciertos++;}
 if(v3==c1 || v3==c2 || v3==c3 || v3==c4){aciertos++;}
 if(v4==c1 || v4==c2 || v4==c3 || v4==c4){aciertos++;}

 if(posiciones==4){acceso=true;}
}

void EscribirIntento(){
  printf("\n  %d Aciertos\n",aciertos);
  printf("  %d En posicion\n",posiciones);
  aciertos = 0;
  posiciones = 0;
  intento--;
}

void MostrarResultado(){
  if(acceso){
    printf("\n Numero correcto. Has ganado\n");
  }else if(!acceso){
    printf("\n Numero de aciertos máximo alcanzado. Has perdido\n");
  }
}


int main() {

	srand (time(NULL));

  system("cls");
  Inicializar();


  do{
    AceptarDatos();
    DescomponerValor();
    Comparar();
    EscribirIntento();
  }while(intento>0 && !acceso);

   MostrarResultado();



  return 0;
}
