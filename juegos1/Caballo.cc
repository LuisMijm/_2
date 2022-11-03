/*  Juego en el que un caballo (ajedrez) salta aleatoriamente en un tablero de
10x10 (100 posiciones). Contar el numero de saltos hasta que no pueda
saltar mas*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int map[10][10], horse[2],
    disp[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int counter=1;
bool steady=false;


void Init(){
  horse[0]=4;
  horse[1]=4;
  map[horse[0]][horse[1]]=counter;
}

void HorseMovement(int *x,int *y, int disp_x, int disp_y){
  counter++;
  map[*x+disp_x][*y+disp_y]=counter;
  horse[0]+=disp_x;
  horse[1]+=disp_y;
  printf("\n %d %d %d\n",*x,*y,counter);
}

bool Empty(int x, int y){
  return map[x][y]==0;
}

bool Steady(int x, int y){
  for(int i=0;i<8;++i){
      if(Empty(x+disp[i][0],y+disp[i][1])){steady=false;}
  }
  return steady;
}

void Select_and_Move(int x, int y){
  int aux;
  bool end=false;
  if(!Steady(x,y)){
    while(!end){
      aux=rand()%8;
      if(x+disp[aux][0]>0 && x+disp[aux][0]<10 && y+disp[aux][1]>0 &&
          y+disp[aux][1]<10 && Empty(x+disp[aux][0],y+disp[aux][1])){

        HorseMovement(&x,&y,disp[aux][0],disp[aux][1]);
        end=true;
      }
    }
  }
}

void DrawMap(){
  for(int i=0;i<10;++i){
    for(int j=0;j<10;++j){
      printf(" %03d",map[j][i]);
    }
    printf("\n");
  }
}

int main(){

  srand(time(NULL));

  Init();

  while(!steady){
    // system("cls");
    Select_and_Move(horse[0],horse[1]);
    DrawMap();
    printf("\n");
  }
  printf("\n Saltos totales del caballo: %03d\n", counter);

  return 0;
}
