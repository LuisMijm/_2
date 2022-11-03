
/* o = izq, p = der, q = arriba*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define posicion(x,y){(cxy.X)= (x);(cxy.Y)= (y);SetConsoleCursorPosition((GetStdHandle(STD_OUTPUT_HANDLE)),(cxy));}

COORD cxy;
const int height = 25, width=80;
int potions=5, boss_type;
int map[width][height+2]={0}, Kposition[2]={width / 2,height},Sposition[2]={width / 2,height+5},
    Bposition[2]={rand()%width,height-rand()%10+2};
char action, boss_char;
bool boss_alive,knight_alive;

//Inicializaciones

void GenerateMap(){ //Procedimiento para rellenar los huecos con muros y power ups.
  for(int i=0;i<height;++i){
    for(int j=0;j<width;++j){
      map[j][i]=rand()%2;
    }
  }
  for(int i=0;i<rand()%5+3;++i){
    map[rand()%width][rand()%height]=2;
  }
  knight_alive=true;
}

void GenerateBoss(){  //Procedimiento para seleccionar el enemigo principal.
  // boss_type=rand()%2;
  boss_type=0;
  boss_alive=false;
  switch (boss_type){
    case 0: boss_char='D'; break;
    case 1: boss_char='G'; break;
    case 2: boss_char=' '; break;
    case 3: boss_char='B'; break;
  }
}


void DrawBlankArround(int x, int y){  // Procedimiento de pintado de espacios
  posicion(x-1,y-1);printf(" ");      // para sustituir asteriscos (visual)
  posicion(x,y-1);  printf(" ");
  posicion(x+1,y-1);printf(" ");
  posicion(x+1,y);  printf(" ");
  posicion(x-1,y);  printf(" ");
  posicion(x-1,y+1);printf(" ");
  posicion(x,y+1);  printf(" ");
  posicion(x+1,y+1);printf(" ");
}

void ClearArround(int x, int y){  //Procedimiento de cambio de valor a
  map[x-1][y-1]=0;                //espacio en el array de mapa
  map[x  ][y-1]=0;
  map[x+1][y-1]=0;
  map[x-1][y  ]=0;
  map[x+1][y  ]=0;
  map[x-1][y+1]=0;
  map[x  ][y+1]=0;
  map[x+1][y+1]=0;

  /*
  for(int i=y-1;i<=y+1;i++){
    for(int j=x-1;j<=x+1){
      map[i][j]=0;posicion(j,i);printf(" ");
    }
  }
  */
  DrawBlankArround(x,y);
}

void PotionUsage(){ //Procedimiento para el uso de la poción.
  ClearArround(Kposition[0],Kposition[1]);
  posicion(width*0.5,height+3);
  potions--;
}

void ShadowMovement(){
  Sposition[0]=Kposition[0];
  Sposition[1]=Kposition[1];
}

void KnightActions(int Knight_x, int Knight_y){
  switch (action){
    case 'o': if(Kposition[0]>0 && 1 != map[Kposition[0]-1][Kposition[1]]){
                ShadowMovement();
                Kposition[0]--;
              };
              break;
    case 'p': if(Kposition[0]<width-1 && 1 != map[Kposition[0]+1][Kposition[1]]){
                ShadowMovement();
                Kposition[0]++;
              };
              break;
    case 'q': if(Kposition[1]>=0 && 1 != map[Kposition[0]][Kposition[1]-1]){
                ShadowMovement();
                Kposition[1]--;
              };
              break;
    case 'a': if(1 != map[Kposition[0]][Kposition[1]+1]){
                ShadowMovement();
                Kposition[1]++;
              };
              break;
    case 32 : if(potions>0){
                PotionUsage();
              };
              break;
  }
}

bool SorroundDetect(int first_x, int first_y, int second_x, int second_y){  //Función para comprobar si dos objetos
  bool aux=false;                                                           //estan a 1 de distancia en una matriz 3x3
  for(int i=first_y-1;i<first_y+2;++i){                                     //Desde el centro de la matriz
    for(int j=first_x-1;j<first_x+2;++j){
      if(second_x==j && second_y==i){aux=true;}
    }
  }
  return aux;
}

// Zona de Bosses
void BossCall(){
  boss_alive=true;
  switch (boss_type) {
    case 0: posicion(0,height+2);printf("The Dragon has appeared");       break;
    case 1: posicion(0,height+2);printf("The Ogre has appeared");         break;
    case 2: posicion(0,height+2);printf("The Shadow Eater has appeared"); break;
    case 3: posicion(0,height+2);printf("The Blob has appeared");         break;
  }
}

void DragonBehaviour(int *Boss_x, int *Boss_y){ //Movimiento del dragón.
  switch (rand()%2){
    case 0: //Movimiento vertical
      if(*Boss_y>Kposition[1] /*&& rand()%4==0*/){  *Boss_y--;};
    break;
    case 1: //Movimiento horizontal
      if(*Boss_x<Kposition[0]){ *Boss_x++;}
      if(*Boss_x>Kposition[0]){ *Boss_x--;};
    break;
  }
}

void OgreBehaviour(int *Boss_x, int *Boss_y){ //Movimiento del ogro
  switch(rand()%4){
    case 0: //Movimiento horizontal
      if(*Boss_x<Kposition[0]){
        for(int i=0;i<2;++i){
          ClearArround(*Boss_x,*Boss_y);
          *Boss_x++;
        }
      }
      else if(*Boss_x>Kposition[0]){
        for(int i=0;i<2;++i){
          ClearArround(*Boss_x,*Boss_y);
          *Boss_x--;
        }
      }
    break;
    case 1: //Movimiento Vertical
      if(*Boss_y>Kposition[1]){
        for(int i=0;i<2;++i){
          ClearArround(*Boss_x,*Boss_y);
          *Boss_y--;
        }
      }
    break;
  }
  // if(SorroundDetect(*Boss_x,*Boss_y,Kposition[0],Kposition[1])){knight_alive=false;}
}

void ShadowEaterBehaviour(int *Boss_x, int *Boss_y){ //Movimiento del Come Sombras.

}

void TheBlobBehaviour(int *Boss_x, int *Boss_y){  //Movimiento de la Cosa.

}

void BossBehaviour(){ //Procedimiento principal de los enemigos
  posicion(Bposition[0],Bposition[1]);printf(" ");
  switch (boss_type) {
    case 0: DragonBehaviour(&Bposition[0],&Bposition[1]);      break;
    case 1: OgreBehaviour(&Bposition[0],&Bposition[1]);        break;
    case 2: ShadowEaterBehaviour(&Bposition[0],&Bposition[1]); break;
    case 3: TheBlobBehaviour(&Bposition[0],&Bposition[1]);     break;
  }
}

void Update(int Knight_x, int Knight_y, int Boss_x, int Boss_y){ //Procedimiento principal de actualizaciones/cada bucle de juego.
  action = getch();
  KnightActions(Knight_x,Knight_y);
  if(2==map[Knight_x][Knight_y]){potions++;map[Knight_x][Knight_y]=0;}  //Actualización de los power ups
  if(Knight_y==height/2+1){BossCall();}
  if(boss_alive){BossBehaviour();posicion(Bposition[0],Bposition[1]);printf("%c", boss_char);}
  if(Knight_x==Boss_x && Knight_y==Knight_y && boss_alive){knight_alive=false;}
}

void DrawMap(){ //Procimiento de pintado del mapa de juego.
  // printf("\n");
  for(int i=0;i<height;++i){
    for(int j=0;j<width;++j){
      if(map[j][i]==0){
        printf(" ");
      }else if(map[j][i]==1){
        printf("*");
      }else if(map[j][i]==2){
        printf("+");
      }
    }
    printf("\n");
  }
  posicion(0,height+1);printf("Potions: %d\n", potions);
}

void DrawKnight(){  //Procedimiento de pintado del personje principal.
  posicion(Kposition[0],Kposition[1]);printf("O");
  posicion(Sposition[0],Sposition[1]);printf(" ");
  posicion(0,height+3);
}

void Draw(){  //Procedimiento para las llamadas a dibujado en pantalla(consola)
  DrawMap();
  DrawKnight();
}


int main(){

  srand(time(NULL));

  system("cls");
  GenerateMap();
  GenerateBoss();
  DrawMap();

  do{
    DrawKnight();
    Update(Kposition[0],Kposition[1],Bposition[0],Bposition[1]);
    posicion(0,height+1);printf("Potions: %d\n", potions);

    //Valor de posiciones en torno al caballero y el enemigo.
      // printf("[%d] [%d] [%d]\n", map[Kposition[0]-1][Kposition[1]-1],map[Kposition[0]][Kposition[1]-1],map[Kposition[0]+1][Kposition[1]-1]);
      // printf("[%d]     [%d]\n" , map[Kposition[0]-1][Kposition[1]],map[Kposition[0]+1][Kposition[1]]);
      // printf("[%d] [%d] [%d]\n", map[Kposition[0]-1][Kposition[1]+1],map[Kposition[0]][Kposition[1]+1],map[Kposition[0]+1][Kposition[1]+1]);
      // printf("caballero: %d %d\n",Kposition[0],Kposition[1]);
      // printf("[%d][%d][%d] Enemigo\n", Bposition[0],Bposition[1],boss_alive);

  }while(27!=action && Kposition[1]>=0 && knight_alive);
  posicion(0,height+4);printf("Partida finalizada\n\n");

  return 0;
}
