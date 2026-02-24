#include <stdio.h>
#define TAM 10

int main(){
	float salario[TAM] = {0}, media=0, acc=0;
	
	for(int i=0; i<TAM; i++){
		printf("Informe o salario %d: R$", i+1);
		scanf("%f", &salario[i]);
		acc+=salario[i];
	}
	
	media = acc / 10;
	
	printf("\nA media salarial da empresa eh = R$%.2f\n", media);
	
	return 0;
}
