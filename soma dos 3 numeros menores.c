#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int numeros[4] = {0};
	int soma = 0, maior = 0;
	
	for(int i=0; i<4; i++){
		printf("Informe um numero: ");
		scanf("%d", &numeros[i]);
		
		soma+=numeros[i];
		
		if(numeros[i] > maior)
			maior = numeros[i];
	}
	
	printf("\nSoma dos 3 menores numeros = %d\n", soma - maior);
	
	return 0;
}