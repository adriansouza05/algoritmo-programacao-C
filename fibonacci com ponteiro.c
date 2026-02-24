#include <stdio.h>

void fibonacci(int *ponteiro){
	int qnd_elementos;
	int i;
	int atual=0, anterior=1, aux=0;
	
	for(i=0; i<= *ponteiro; i++){
		atual+=aux;
		printf("%d ", atual);
		aux = anterior;
		anterior = atual;
	}
}

int main(){
	int *ponteiro_qnd_elementos;
	int qnd_elementos;
	
	printf("Informe a quantidade de elementos para a sequencia: ");
	scanf("%d", &qnd_elementos);
	
	ponteiro_qnd_elementos = &qnd_elementos;
	
	fibonacci(ponteiro_qnd_elementos);

	return 0;
}