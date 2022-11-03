// Ejemplo Rombo
#include <stdio.h>


int altura, i, j, k;
int main()
{
	printf("Altura: "); 
	scanf_s("%d", &altura);

	for (i = 1; i <= altura; ++i)
	{
		for (k = altura - i + 1; k >= 1; --k) 
			printf(" ");
		printf("*"); 
		for (j = 1; j <= 2 * i - 1 - 2; ++j)
			printf(" ");
		if (i>1) printf("*");
		printf("\n");
	}

	for (i = altura - 1; i>0; --i)
	{
		for (k = altura - i + 1; k >= 1; --k)
			printf(" ");
		printf("*"); 
		for (j = 1; j <= 2 * i - 1 - 2; ++j) 
			printf(" ");
		if (i>1) printf("*");
		printf("\n");
	}
	
	return 0;
}
