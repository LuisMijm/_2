

#include <stdio.h>


char g_operador;
float g_operando1, g_operando2;



void Seleccion(){
  printf("Seleccione el tipo de operación a realizar (+,-,* o /): ");
  // do{
    scanf("%c",&g_operador);
  // }while(g_operador!='+' || g_operador!='-' || g_operador!='*' ||
          // g_operador!='/');
  printf("Seleccione primer operando\n");
  scanf("%f",&g_operando1);

  do{
	printf("Seleccione segundo operando\n");
    scanf("%f",&g_operando2);
  }while(g_operador=='/' && g_operando2==0);
}

void Operacion(){
  switch(g_operador){
    case '+': printf("El resultado de sumar %f y %f es %f\n",
              g_operando1,g_operando2,g_operando1+g_operando2);break;
    case '-': printf("El resultado de restar %f y %f es %f\n",
              g_operando1,g_operando2,g_operando1-g_operando2);break;
    case '*': printf("El resultado de multiplicar %f y %f es %f\n",
              g_operando1,g_operando2,g_operando1*g_operando2);break;
    case '/': printf("El resultado de dividir %f y %f es %f\n",
              g_operando1,g_operando2,g_operando1/g_operando2);break;
  }
}


int main(){

  Seleccion();
  Operacion();

  return 0;
}
