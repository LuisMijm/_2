
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int map[10][10]={0}, horse[2],
    displacements[8][2]{-2,-1, -2,1, -1,2, 1,2, -2,-1, -2,1, -1,-2, 1,-2};
int counter=1;
bool steady=true;
int x=0,y=0;

int main(){

  for(int i=0;i<8;++i){
    for(int j=0;j<2;++j){
      // if()
      x=0;
      x+=displacements[i][j];

      printf(" %02d ", x);
    }
    printf("\n");
  }

  return 0;
}
