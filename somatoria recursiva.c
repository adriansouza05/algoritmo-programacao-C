#include <stdio.h>

int somatoria_recursiva(int num){
	if (num == 0)
		return 0;
	return num + somatoria_recursiva(num - 1);
}

int main(){
	int num;
	
	printf("Informe um numero para sua somatoria: ");
	scanf("%d", &num);
	
	if (num < 0){
		printf("Nao ha somatoria para negativos!\n");
		return 1;
	}
		
	printf("\nA somatoria de %d eh = %d\n", num, somatoria_recursiva(num));
	
	return 0;
}