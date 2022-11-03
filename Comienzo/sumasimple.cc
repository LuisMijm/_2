

#include <stdio.h>


int g_valor_1, g_valor_2, g_valor_3;


int main(){
	
	printf(" Primera variable \t \n ");
	scanf("%d", &g_valor_1);
	
	printf(" Segunda variable \t \n ");
	scanf("%d", &g_valor_2);
	
	printf(" tercera variable \t \n ");
	scanf("%d", &g_valor_3);
	
	printf(" La suma de las variables %d, %d y %d es: %d \n", g_valor_1, g_valor_2, g_valor_3,g_valor_1+g_valor_2+g_valor_3);
	
	return 0;
}

