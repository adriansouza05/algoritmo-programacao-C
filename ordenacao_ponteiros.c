#include <stdio.h>

void ordenar(int *ponteiro_de_n1, int *ponteiro_de_n2){
	int aux;
	
	if(*ponteiro_de_n1 > *ponteiro_de_n2){
		aux = *ponteiro_de_n1;
		*ponteiro_de_n1 = *ponteiro_de_n2;
		*ponteiro_de_n2 = aux;
	}
}

int main(){
	int n1, n2;
	
	printf("Informe um numero: ");
	scanf("%d", &n1);
	
	printf("Informe um numero: ");
	scanf("%d", &n2);
	
	ordenar(&n1, &n2);
	
	printf("o menor numero %d e o maior %d\n", n1, n2);
	
    return 0;
}
