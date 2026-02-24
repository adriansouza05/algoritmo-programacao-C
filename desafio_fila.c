#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int enqueue(int fila[], int elemento, int *fim)
{
    if (*fim < (TAM - 1))
    {
        *fim = *fim + 1;
        fila[*fim] = elemento;
        return 0;
    }
    else
        return 1;
}

int dequeue(int fila[], int *fim)
{
    if (*fim == -1)
        return 1;
    else
    {
        for (int i = 0; i < *fim; i++)
            fila[i] = fila[i + 1];
        *fim = *fim - 1;
        return 0;
    }
}

int peek(int fila[], int *fim)
{
    system("cls");
    if (*fim == -1)
    {
        printf("\nNao ha elementos da fila!\n");
        system("pause");
        return 1;
    }
    printf("Fila: ");
    for (int i = 0; i <= *fim; i++)
        printf("%d ", fila[i]);
    printf("\n\n");
    system("pause");
    return 0;
}

int menu()
{
    int opcao;
    system("cls");
    printf("1 - Enqueue\n");
    printf("2 - Dequeue\n");
    printf("3 - Peek Queue\n");
    printf("0 - Sair\n");

    printf("\nInforme sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    int opcao_main;
    int fila[TAM], elemento, fim;

    fim = -1;

    do
    {
        opcao_main = menu();

        switch (opcao_main)
        {
        case 1:
            system("cls");
            printf("Informe um elemento para a fila: ");
            scanf("%d", &elemento);
            int flag = enqueue(fila, elemento, &fim);
            if (flag == 0)
                printf("\nElemento inserido com sucesso!\n");
            else
                printf("\nFila Cheia!\n");
            system("pause");
            break;

        case 2:
            system("cls");
            flag = dequeue(fila, &fim); // Variável com nome diferente
            if (flag == 0)
                printf("\nElemento removido com sucesso!\n");
            else
                printf("\nFila Vazia!\n");
            system("pause");
            break;

        case 3:
            peek(fila, &fim);
            break;

        case 0:
            printf("\nSaindo...\n");
            system("pause");
            break;

        default:
            printf("\nValores invalidos\n");
            system("pause");
            break;
        }
    } while (opcao_main != 0);

    return 0;
}