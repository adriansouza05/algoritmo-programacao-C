/*Questão 2 - Intermediária:
Crie uma função que recebe um array de inteiros, seu tamanho e um
ponteiro para inteiro. A função deve armazenar no ponteiro a soma
de todos os elementos pares e retornar a quantidade de elementos pares encontrados.*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int funcao(int arr[], int tamanho, int *ptr)
{
    int soma = 0;
    int cont = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (arr[i] % 2 == 0)
        {
            soma += arr[i];
            cont++;
        }
    }

    *ptr = soma;
    return cont;
}

int main()
{
    int arr[TAM];

    // Lê o array aqui
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &arr[i]);
    }

    int soma_pares = 0;

    int qtd = funcao(arr, TAM, &soma_pares);

    printf("Quantidade de pares = %d\n", qtd);
    printf("Soma dos pares = %d\n", soma_pares);

    return 0;
}
