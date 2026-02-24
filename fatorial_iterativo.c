#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcao_fatorial_iterativo(int num){
	int fatorial = 1;
	
	for(int i=num; i>0; i--){
		fatorial *= i;
	}
	return fatorial;
}

int main(){
	int num;
	int fatorial;
	
	printf("Informe um numero para descobrir seu fatorial: ");
	scanf("%d", &num);
	
	fatorial = funcao_fatorial_iterativo(num);
	
	printf("O fatorial de %d! eh = %d", num, fatorial);
	
    return 0;
}