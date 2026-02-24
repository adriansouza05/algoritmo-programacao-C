#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int potencia(int base, int expoente){
	if(expoente == 0)
		return 1;
	return base * potencia(base, expoente - 1);
}

int main(){
	int base_numero, expoente_numero;
	
	printf("Informe um numero: ");
	scanf("%d", &base_numero);
	
	printf("Informe um expoente: ");
	scanf("%d", &expoente_numero);
	
	printf("O resultado da potencia eh = %d", potencia(base_numero, expoente_numero));
	
	return 0;
}