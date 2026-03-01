#include <stdio.h>
#include <stdlib.h>

/*1 - (2 pontos) Declare uma struct para implementar uma lista
de nomes denominada SLista juntamente com um typedef TLista.
A struct deverá conter os elementos Nome e o marcador fim.*/

typedef struct SLista
{
    char nome[30];
    struct SLista *prox;
} TLista;

/*2 - (2 pontos) Escreva a função Inserir na pilha declarada na questão
1. Considere a seguinte linha identidade: int push(TPilha *p, char c[]).
A função deverá retornar 1 se a pilha estiver cheia ou 0 se o elemento
for inserido com sucesso. Use a função strcpy() para atribuição dos valores.*/

#define MAX 20

typedef struct
{
    char c[MAX][30];
    int topo;
} TPilha;

int push(TPilha *p, char c[])
{
    if (p->c[p->topo] == MAX - 1)
        return 1;

    p->topo++;
    strcpy(p->c[p->topo], c);
    return 0;
}

/*3 - (2 pontos) Faça a chamada na função PUSH considerando as variáveis TPilha
pilha, int flag e char nome[30] com os valores já atribuídos. (escreva somente a
linha referente à chamada da função). A variável flag deverá receber o retorno da função.*/

flag = push(&pilha, nome);