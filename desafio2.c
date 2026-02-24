/*Busca de Elemento: Peça ao usuário para inserir 8 números inteiros em um vetor.
Depois, solicite que ele digite um número a ser buscado.
O programa deve verificar se o número está no vetor e, se estiver, informar sua primeira
posição (índice).*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[8] = {0};
    int num;

    for (int i = 0; i < 8; i++)
    {
        printf("Informe o %d° valor para a posicao [%d]: ", i + 1, i);
        scanf("%d", &vet[i]);
    }

    printf("\n\nInforme um a ser buscado: ");
    scanf("%d", &num);

    int encontrado = 0; // Variável de controle (flag)

    for (int i = 0; i < 8; i++)
    {
        if (vet[i] == num)
        {
            printf("O numero %d foi encontrado na posicao %d.\n", num, i);
            encontrado = 1; // Marca a variável como 'encontrado'
            break;          // Sai do loop para encontrar apenas a primeira ocorrencia
        }
    }

    if (encontrado == 0)
    {
        printf("O numero %d nao foi encontrado no vetor.\n", num);
    }

    return 0;
}