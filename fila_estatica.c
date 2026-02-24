#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
	int vetor[TAM];
	int fim;
	int inicio;
} Fila;

void inicializar(Fila *f)
{
	f->fim = -1;
	f->inicio = 0;
}

int fila_cheia(Fila *f)
{
	return f->fim == TAM - 1;
}

int fila_vazia(Fila *f)
{
	return f->fim == -1;
}

int enqueue(Fila *f, int elemento)
{
	if (fila_cheia(f))
		return 1;

	f->fim++;
	f->vetor[f->fim] = elemento;
	return 0;
}

int dequeu(Fila *f, int *inicio)
{
	if (fila_vazia(f))
		return 1;

	*inicio = f->vetor[0];
	for (int i = 0; i < f->fim; i++)
		f->vetor[i] = f->vetor[i + 1];
	f->fim--;
	return 0;
}

void peek(Fila *f)
{
	system("cls");
	if (fila_vazia(f))
		printf("\nFila vazia!\n");
	else
	{
		printf("\nFila:\n");
		for (int i = 0; i <= f->fim; i++)
			printf("\t%d\n", f->vetor[i]);
	}
	printf("\n");
	system("pause");
}

int funcao_menu()
{
	int opcao;

	system("cls || clear"); // compatível com Windows e Linux
	printf("1 - Enqueue (Inserir)\n");
	printf("2 - Dequeue (Remover)\n");
	printf("3 - Mostrar Fila\n");
	printf("0 - Sair\n\n");

	printf("Informe sua opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

int main()
{
	Fila fila;
	int opcao, elemento, inicio, flag;

	inicializar(&fila);

	do
	{
		opcao = funcao_menu();

		switch (opcao)
		{
		case 1:
			system("cls");
			printf("Informe um elemento para a fila: ");
			scanf("%d", &elemento);
			flag = enqueue(&fila, elemento);
			if (flag == 0)
				printf("\nElemento inserido com sucesso!\n\n");
			else
				printf("\nFila Cheia! Remova um elemento para inserir mais...\n\n");
			system("pause");
			break;

		case 2:
			system("cls");
			flag = dequeu(&fila, &inicio);
			if (flag == 0)
				printf("\nElemento %d removido com sucesso!\n\n", inicio);
			else
				printf("\nNao eh possivel remover mais elementos! Fila vazia...\n\n");
			system("pause");
			break;

		case 3:
			peek(&fila);
			break;

		case 0:
			break;

		default:
			printf("\nOpcao Invalida!\n\n");
			system("pause || read -p \"Pressione Enter para continuar...\" ");
			break;
		}

	} while (opcao != 0);

	return 0;
}
