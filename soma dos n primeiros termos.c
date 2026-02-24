#include <stdio.h>
#include <math.h>

int main(){
	int qnd_termos;
	float termo, soma=0;
	
	printf("Informe a quantidade de termos para a PA: ");
	scanf("%d", &qnd_termos);
	
	for(int i=1; i<=qnd_termos; i++){
		termo = (5 * i)/ (3 * pow(2, i-1));
		soma+=termo;
	}
	
	printf("A soma dos n primeiros termos eh = %.2f", soma);
	
	
	return 0;
}
	
