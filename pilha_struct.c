#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int vetor[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p)
{
    p->topo = -1;
}

int pilha_cheia(Pilha *p)
{
    return p->topo == TAM - 1;
}

int pilha_vazia(Pilha *p)
{
    return p->topo == -1;
}

int push(Pilha *p, int valor)
{
    if (pilha_cheia(p))
        return 1;

    p->topo++;
    p->vetor[p->topo] = valor;
    return 0;
}

int pop(Pilha *p)
{
    if (pilha_vazia(p))
        return 1;

    p->topo--;
    return 0;
}

void peek(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("\nPilha Vazia!\n");
        return;
    }
    else
    {
        printf("Elementos da pilha:\n");
        for (int i = p->topo; i >= 0; i--)
        {
            printf("\t[%d]\n", p->vetor[i]);
        }
    }
}

int funcao_menu()
{
    int opcao;

    system("cls");
    printf("1-Push\n");
    printf("2-Pop\n");
    printf("3-Peek Pilha\n");
    printf("0-Sair\n\n");

    printf("Informe sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    Pilha pilha;
    int opcao, valor, flag;

    inicializar(&pilha);

    do
    {
        opcao = funcao_menu();

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\nInforme um elemento para a pilha: ");
            scanf("%d", &valor);
            flag = push(&pilha, valor);
            if (flag == 1)
            {
                printf("\nPilha Cheia!\n");
            }
            else
            {
                printf("\nElemento inserido com sucesso!\n");
            }
            system("pause");
            break;

        case 2:
            system("cls");
            flag = pop(&pilha);
            if (flag == 1)
            {
                printf("\nPilha Vazia\n");
            }
            else
            {
                printf("\nElemento removido com sucesso!\n");
            }
            system("pause");
            break;

        case 3:
            peek(&pilha);
            system("pause");
            break;

        case 0:
            break;

        default:
            printf("\nOpcao Invalida!\n\n");
            system("pause");
            break;
        }

    } while (opcao != 0);

    return 0;
}