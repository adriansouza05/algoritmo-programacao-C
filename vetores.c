#include <stdio.h>
#define TAM 10

int main(){
	int vetor[TAM] = {0}, vetor2[TAM] = {0}, vetor3[TAM] = {0};
	int i, par = 0;
	int maior = -9999, menor = 9999;
	float media = 0, acc = 0;
	
	for(i=0; i<TAM; i++){
		printf("Informe um valor para vet[%d] = ", i);
		scanf("%d", &vetor[i]);
		acc+=vetor[i];
		if(vetor[i] > maior)
			maior = vetor[i];
		if(vetor[i] < menor)
			menor = vetor[i];
		if(vetor[i] % 2 == 0)
			par++;
	}
	
	printf("\n\n");
	
	printf("Vetor original:\n");
	for(i=0; i<TAM; i++)
		printf("\tvet[%d] = %d\n", i, vetor[i]);
		
	printf("\n\n");
	
	printf("Vetor com valores dobrados:\n");
	for(i=0; i<TAM; i++){
		vetor2[i] = vetor[i] * 2;
		printf("\tvet[%d] = %d\n", i, vetor2[i]);
	}
		
		
	printf("\n\n");
		
	printf("Vetor com valores invertidos:\n");
	for(i=0; i<TAM; i++){
		vetor3[i] = vetor[TAM - i - 1];
		printf("\tvet[%d] = %d\n", i, vetor3[i]);
	}
		
		
	printf("\n\n");
	
	media = acc / TAM;
	
	printf("\tA media dos vetores eh = %.2f\n", media);
	printf("\tO menor elemento do vetor eh: %d\n", menor);
	printf("\tO maior elemento do vetor eh: %d\n", maior);
	printf("\tTemos %d elemento(s) par\n", par);
		
	return 0;
}
	
