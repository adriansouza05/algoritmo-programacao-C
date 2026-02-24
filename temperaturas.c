#include <stdio.h>

int main(){
	float maior_temp=-9999, menor_temp=9999, temp, acc_temp=0, media_temp;
	int contador=0;
	char opcao;
	
	do{
		printf("Informe a temperatura: ");
		scanf("%f", &temp);
		
		acc_temp+=temp;
		contador++;
		
		if(temp > maior_temp)
			maior_temp = temp;
		if(temp < menor_temp)
			menor_temp = temp;
		
		printf("Deseja continuar? [S/N]: ");
		scanf(" %c", &opcao);
			
	} while(opcao != 'N' && opcao != 'n');
	
	if(contador>0)
		media_temp = acc_temp / contador;
	
	printf("\nA media das temperaturas eh = %.2f\n", media_temp);
	printf("\nA maior temperatura eh = %.2f\n", maior_temp);
	printf("\nA menor temperatura eh = %.2f\n", menor_temp);
	
	return 0;
}
