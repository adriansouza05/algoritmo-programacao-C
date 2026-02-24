#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcao_fatorial_recursiva(int num)
{
	if (num == 0 || num == 1)
		return 1;
	return num * funcao_fatorial_recursiva(num - 1);
}

int main()
{
	int num;

	printf("Informe um numero para seu fatorial: ");
	scanf("%d", &num);

	if (num < 0)
	{
		printf("Nao ha fatorial para zero ou negativos!");
		return 1;
	}

	printf("\nO fatorial de %d eh = %d\n", num, funcao_fatorial_recursiva(num));

	return 0;
}