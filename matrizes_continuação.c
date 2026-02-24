#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

// Funcao que gera numeros aleatorios de 0 a 99 na matriz
void carregar_matriz_aleatorios(int matriz[TAM][TAM])
{
	int linha, coluna;

	srand(time(NULL)); // Garante aleatoriedade a cada execução

	for (linha = 0; linha < TAM; linha++)
	{
		for (coluna = 0; coluna < TAM; coluna++)
		{
			matriz[linha][coluna] = rand() % 100;
		}
	}

	printf("\nMatriz com numeros aleatorios gerada!\n\n");
	system("pause");
}

// Funcao que atualiza os dados com base na matriz preenchida
void atualizar_dados_matriz(int matriz[TAM][TAM], int *soma_elementos, int *maior, int *menor,
							int *qnd_pares_principal, int *qnd_impares_secundaria,
							int *qnd_pares_secundaria, int *somatoria_linha_impar)
{
	int linha, coluna;

	// Inicialização das variáveis auxiliares
	*soma_elementos = 0;
	*maior = -9999;
	*menor = 9999;
	*qnd_pares_principal = 0;
	*qnd_impares_secundaria = 0;
	*qnd_pares_secundaria = 0;
	*somatoria_linha_impar = 0;

	for (linha = 0; linha < TAM; linha++)
	{
		for (coluna = 0; coluna < TAM; coluna++)
		{
			int valor = matriz[linha][coluna];

			*soma_elementos += valor;

			if (valor > *maior)
				*maior = valor;
			if (valor < *menor)
				*menor = valor;
		}

		// Verifica paridade na diagonal principal
		if (matriz[linha][linha] % 2 == 0)
			(*qnd_pares_principal)++;

		// Verifica paridade na diagonal secundaria
		if (matriz[linha][TAM - 1 - linha] % 2 == 0)
			(*qnd_pares_secundaria)++;
		else
			(*qnd_impares_secundaria)++;

		// Soma os elementos da linha impar (linha 1, por exemplo)
		if (linha % 2 != 0)
		{
			for (coluna = 0; coluna < TAM; coluna++)
			{
				*somatoria_linha_impar += matriz[linha][coluna];
			}
		}
	}
}

// Funcao para cadastro manual dos valores da matriz
void carregar_matriz_manual(int matriz[TAM][TAM])
{
	int linha, coluna;

	system("cls");
	for (linha = 0; linha < TAM; linha++)
	{
		for (coluna = 0; coluna < TAM; coluna++)
		{
			printf("Informe um valor para a posicao %dx%d = ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
		}
	}
	system("pause");
}

// Funcao para impressao da matriz na tela
void imprimir_matriz(int matriz[TAM][TAM])
{
	int linha, coluna;

	system("cls");
	printf("\tMatriz %dx%d:\n\n", TAM, TAM);
	for (linha = 0; linha < TAM; linha++)
	{
		for (coluna = 0; coluna < TAM; coluna++)
		{
			printf("\t%d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\n\n");
	system("pause");
}

// Funcao para exibir o menu principal e capturar a opcao do usuario
int menu()
{
	int opcao;

	system("cls");
	printf("* * * M E N U * * *\n\n");
	printf("0 - Gerar matriz com numeros aleatorios\n");
	printf("1 - Cadastrar matriz manualmente\n");
	printf("2 - Imprimir a matriz\n");
	printf("3 - Somatoria dos elementos da matriz\n");
	printf("4 - Maior e menor elemento da matriz\n");
	printf("5 - Quantidade de numeros pares da diagonal principal\n");
	printf("6 - Quantidade de numeros impares da diagonal secundaria\n");
	printf("7 - Quantidade de numeros pares da diagonal secundaria\n");
	printf("8 - Somatoria dos elementos das linhas impares\n");
	printf("9 - Sair\n\n");
	printf("Informe sua opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

int main()
{
	int opcao_main;
	int matriz[TAM][TAM] = {0};

	// Variáveis auxiliares que armazenam os dados calculados
	int somatoria = 0;
	int maior, menor;
	int qnd_pares_principal = 0;
	int qnd_impares_secundaria = 0;
	int qnd_pares_secundaria = 0;
	int somatoria_linha_impar = 0;

	do
	{
		opcao_main = menu();

		switch (opcao_main)
		{
		case 0:
			// Gera matriz aleatória e atualiza os dados
			carregar_matriz_aleatorios(matriz);
			atualizar_dados_matriz(matriz, &somatoria, &maior, &menor,
								   &qnd_pares_principal, &qnd_impares_secundaria,
								   &qnd_pares_secundaria, &somatoria_linha_impar);
			break;

		case 1:
			// Cadastro manual e atualiza os dados
			carregar_matriz_manual(matriz);
			atualizar_dados_matriz(matriz, &somatoria, &maior, &menor,
								   &qnd_pares_principal, &qnd_impares_secundaria,
								   &qnd_pares_secundaria, &somatoria_linha_impar);
			break;

		case 2:
			imprimir_matriz(matriz);
			break;

		case 3:
			system("cls");
			printf("\n\tSomatoria dos elementos da matriz: %d\n\n", somatoria);
			system("pause");
			break;

		case 4:
			system("cls");
			printf("\n\tMaior elemento: %d\n", maior);
			printf("\tMenor elemento: %d\n\n", menor);
			system("pause");
			break;

		case 5:
			system("cls");
			printf("\n\tQuantidade de pares na diagonal principal: %d\n\n", qnd_pares_principal);
			system("pause");
			break;

		case 6:
			system("cls");
			printf("\n\tQuantidade de impares na diagonal secundaria: %d\n\n", qnd_impares_secundaria);
			system("pause");
			break;

		case 7:
			system("cls");
			printf("\n\tQuantidade de pares na diagonal secundaria: %d\n\n", qnd_pares_secundaria);
			system("pause");
			break;

		case 8:
			system("cls");
			printf("\n\tSomatoria das linhas impares: %d\n\n", somatoria_linha_impar);
			system("pause");
			break;

		case 9:
			// Finaliza o programa
			break;

		default:
			printf("\nOpcao invalida!\n");
			system("pause");
		}

	} while (opcao_main != 9);

	printf("\nPrograma Finalizado!\n");

	return 0;
}
