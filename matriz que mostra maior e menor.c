#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int matriz[TAM][TAM] = {0};

void carregar_matriz(){
	system("cls");
	printf("\n");
	for (int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			printf("Informe o valor para a posicao [%d][%d]: ", linha,coluna);
			scanf("%d", &matriz[linha][coluna]);
		}
		printf("\n");
	}
	system("pause");
}

void imprimir_matriz(){
	system("cls");
	printf("\n");
	for(int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			printf("\t%d ", matriz[linha][coluna]);
		}
		printf("\n");
	}
	
	system("pause");
}

void media_elementos_matriz(){
	float soma = 0;
	float media = 0;
	
	system("cls");
	for(int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			soma += matriz[linha][coluna];
		}
	}
	media = soma / (TAM*TAM);
	
	printf("A media dos elementos da matriz eh = %.2f\n\n", media);
	system("pause");
}

void calcular_maior_menor(int matriz[TAM][TAM], int *maior, int *menor){
	*maior = matriz[0][0];
	*menor = matriz[0][0];
	
	for(int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			if(matriz[linha][coluna] > *maior)
				*maior = matriz[linha][coluna];
			if(matriz[linha][coluna] < *menor)
				*menor = matriz[linha][coluna];
		}
	}
}

int menu(){
	int opcao_menu;
	
	system("cls");
	
	printf("* * * M E N U * * *\n");
	printf("1 - Carregar elementos da matriz\n");
	printf("2 - Imprimir elementos da matriz\n");
	printf("3 - Calcular a media dos elementos da matriz\n");
	printf("4 - Mostrar o menor e o maior\n");
	printf("9 - Sair do programa\n");
	printf("\n\nInforme sua opcao: ");
	scanf("%d", &opcao_menu);
	
	return opcao_menu;
}


int main(){
	int opcao_main;
	int maior, menor;
	
	do{
		opcao_main = menu();
		
		switch(opcao_main){
			case 1:
				carregar_matriz();
				break;
			
			case 2:
				imprimir_matriz();
				break;
				
			case 3:
				media_elementos_matriz();
				break;
				
			case 4:
				system("cls");
				calcular_maior_menor(matriz, &maior, &menor);
				printf("O maior elemento eh = %d\n", maior);
				printf("O menor elemento eh = %d\n\n", menor);
				system("pause");
				break;
				
			case 9:
				break;
				
			default:
				printf("\nValor invalido!\n");
				system("pause");
				break;
		}
	} while(opcao_main != 9);
	
	printf("\nPrograma finalizado!\n");
	
	return 0;
}