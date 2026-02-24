#include <stdio.h>
#include <stdlib.h>
#define TAM 3
//início 15:10
//fim 15:34

void carregar_matriz(int matriz[TAM][TAM]){
	system("cls");
	for(int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			printf("Informe um valor para a posicao [%d][%d]: ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
		}
		printf("\n");
	}
	system("pause");
}

void imprimir_matriz(int matriz[TAM][TAM]){
	system("cls");
	printf("Matriz 3x3:\n\n");
	for(int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			printf("\t%d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\n\n");
	system("pause");
}

void maior_menor(int matriz[TAM][TAM]){
	system("cls");
	int maior = matriz[0][0];
	int menor = matriz[0][0];
	
	for(int linha=0; linha<TAM; linha++){
		for(int coluna=0; coluna<TAM; coluna++){
			if(matriz[linha][coluna] > maior)
				maior = matriz[linha][coluna];
			if(matriz[linha][coluna] < menor)
				menor = matriz[linha][coluna];
		}
	}
	
	printf("\nMaior valor: %d", maior);
    printf("\nMenor valor: %d\n\n", menor);
    system("pause");
}


int menu(){
	int opcao_menu;
	
	system("cls");
	
	printf("* * * M E N U * * *\n\n");
	printf("1 - Inserir dados na matriz\n");
	printf("2 - imprimir matriz\n");
	printf("3 - Mostrar o maior e menor\n");
	printf("0 - Sair do programa\n\n");
	printf("* * * * * * * * * *\n\n");
	
	printf("Informe sua opcao: ");
	scanf("%d", &opcao_menu);
	
	return opcao_menu;
}

int main(){
	int opcao_main;
	int matriz[TAM][TAM] = {0};
	
	do{
		opcao_main = menu();
		
		switch(opcao_main){
			case 1:
				carregar_matriz(matriz);
				break;
			
			case 2:
				imprimir_matriz(matriz);
				break;
				
			case 3:
				maior_menor(matriz);
				break;
				
			case 0:
				break;
				
			default:
				printf("\nValores invalidos!\n");
				system("pause");
				break;
		}
	} while(opcao_main != 0);
	
	printf("\nPrograma finalizado com sucesso!\n");
	
	return 0;
}