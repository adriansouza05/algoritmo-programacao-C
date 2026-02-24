#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int dados[TAM];
    int tamanho;
} ListaEstatica;

void inicializar(ListaEstatica *lista)
{
    lista->tamanho = 0;
}

void inserir(ListaEstatica *lista, int posicao, int valor)
{
    if (lista->tamanho >= TAM)
    {
        printf("Lista cheia!\n");
        return;
    }

    if (posicao < 0 || posicao > lista->tamanho)
    {
        printf("Posição inválida!\n");
        return;
    }

    // Desloca os elementos para a direita
    for (int i = lista->tamanho; i > posicao; i--)
    {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;

    printf("Elemento %d inserido na posicao %d com sucesso!\n", valor, posicao);
}

void remover(ListaEstatica *lista, int posicao)
{
    if (posicao >= 0 && posicao < lista->tamanho)
    {
        int removido = lista->dados[posicao];
        for (int i = posicao; i < lista->tamanho - 1; i++)
        {
            lista->dados[i] = lista->dados[i + 1];
        }
        lista->tamanho--;
        printf("Elemento %d removido com sucesso!\n", removido);
    }
    else
    {
        printf("Posição inválida!\n");
    }
}

void exibir(ListaEstatica *lista)
{
    if (lista->tamanho == 0)
        printf("Lista vazia!\n");
    else
    {
        printf("Elementos da lista:\n");
        for (int i = 0; i < lista->tamanho; i++)
            printf("[%d] = %d\n", i, lista->dados[i]);
    }
}

int menu()
{
    int opcao;

    printf("\n=== MENU ===\n");
    printf("1 - Inserir\n");
    printf("2 - Imprimir\n");
    printf("3 - Remover\n");
    printf("0 - Sair\n\n");

    printf("Informe sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    ListaEstatica lista;
    inicializar(&lista);

    int num, opcao, posicao;

    do
    {
        system("cls");
        opcao = menu();

        switch (opcao)
        {
        case 1:
            system("cls");
            if (lista.tamanho >= TAM)
            {
                printf("Lista cheia! Não é possível inserir.\n");
            }
            else
            {
                printf("Informe o valor: ");
                scanf("%d", &num);
                printf("Informe a posicao (0 a %d): ", lista.tamanho);
                scanf("%d", &posicao);
                inserir(&lista, posicao, num);
            }
            system("pause");
            break;

        case 2:
            system("cls");
            exibir(&lista);
            system("pause");
            break;

        case 3:
            system("cls");
            if (lista.tamanho == 0)
            {
                printf("Lista vazia! Nada a remover.\n");
            }
            else
            {
                printf("Digite a posicao a remover (0 a %d): ", lista.tamanho - 1);
                scanf("%d", &posicao);
                remover(&lista, posicao);
            }
            system("pause");
            break;

        case 0:
            break;

        default:
            printf("Opção inválida!\n");
            system("pause");
            break;
        }

    } while (opcao != 0);

    return 0;
}
