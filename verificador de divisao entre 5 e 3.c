#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificador(int numero){
	if((numero % 5 == 0) && (numero % 3 == 0)){
		printf("\nO numero %d eh divisivel por 5 e por 3!\n", numero);
		return 0;
	}
	else{
		printf("O numero %d nao eh divisivel por 5 e 3!", numero);
		return 1;	
	}
}

int main(){
	int numero;
	
	printf("Informe um numero natural: ");
	scanf("%d", &numero);
	
	verificador(numero);
	
	return 0;
}