#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5 // tamanho máximo da lista

// Estrutura que representa um funcionário
typedef struct SFuncionario
{
    char nome[50];
    float salario;
} TFuncionario;

// Estrutura que representa a lista de funcionários
typedef struct SLista
{
    TFuncionario funcionarios[TAM]; // vetor fixo de funcionários
    int fim;                        // indica a última posição ocupada (-1 = lista vazia)
} TLista;

/*
Retornos possíveis:
 0 - inserido com sucesso
 1 - lista cheia
*/
int inserir(TLista *l, char n[], float s)
{
    int i;

    // Verifica se a lista está cheia
    if (l->fim == TAM - 1)
        return 1;

    // Incrementa o fim (nova posição livre)
    l->fim++;
    i = l->fim;

    // Enquanto o nome anterior for "maior" (vem depois no alfabeto),
    // desloca os elementos para abrir espaço
    while (i > 0 && strcmp(l->funcionarios[i - 1].nome, n) > 0)
    {
        strcpy(l->funcionarios[i].nome, l->funcionarios[i - 1].nome);
        l->funcionarios[i].salario = l->funcionarios[i - 1].salario;
        i--;
    }

    // Insere o novo funcionário na posição correta
    strcpy(l->funcionarios[i].nome, n);
    l->funcionarios[i].salario = s;

    return 0; // sucesso
}

/*
Retornos possíveis:
 0 - removido com sucesso
 1 - lista vazia
 2 - funcionário não encontrado
*/
int remover(TLista *l, char n[])
{
    int pos, i;

    // Verifica se a lista está vazia
    if (l->fim < 0)
        return 1;

    // Procura a posição do funcionário
    pos = 0;
    while (pos <= l->fim && strcmp(l->funcionarios[pos].nome, n) != 0)
        pos++;

    // Se chegou ao fim sem encontrar
    if (pos > l->fim)
        return 2;

    // Desloca os elementos para "tampar o buraco"
    for (i = pos; i < l->fim; i++)
    {
        strcpy(l->funcionarios[i].nome, l->funcionarios[i + 1].nome);
        l->funcionarios[i].salario = l->funcionarios[i + 1].salario;
    }

    l->fim--; // reduz o tamanho da lista
    return 0;
}

void imprimir(TLista l)
{
    system("cls");
    printf("* * * *   Cadastro de funcionarios   * * * *\n\n");

    if (l.fim < 0)
        printf("\nCadastro Vazio....\n\n");
    else
    {
        for (int i = 0; i <= l.fim; i++)
        {
            printf("\nNome       : %s", l.funcionarios[i].nome);
            printf("\nSalario    : %.2f\n", l.funcionarios[i].salario);
        }
        printf("\n");
    }

    system("pause");
}

int menu()
{
    int opcao;
    system("cls");
    printf("* * * *   M E N U   * * * *\n\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Imprimir\n");
    printf("9 - Sair\n\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &opcao);
    getchar(); // limpa o \n do buffer
    return opcao;
}

int main()
{
    TLista lista;
    lista.fim = -1; // lista começa vazia
    int flag, op;
    float salario;
    char nome[50];

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            system("cls");
            printf("* *  Inserir  * *\n\n");
            printf("Digite o nome: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0'; // remove o \n
            printf("Digite o salario: ");
            scanf("%f", &salario);
            getchar(); // limpa o \n

            flag = inserir(&lista, nome, salario);

            if (flag == 0)
                printf("\nFuncionario inserido com sucesso!\n\n");
            else
                printf("\nImpossivel inserir... Cadastro cheio!\n\n");

            system("pause");
            break;

        case 2:
            system("cls");
            printf("* *  Remover  * *\n\n");
            printf("Digite o nome do funcionario a ser removido: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            flag = remover(&lista, nome);

            if (flag == 0)
                printf("\nFuncionario removido com sucesso!\n\n");
            else if (flag == 1)
                printf("\nImpossivel remover... Cadastro vazio!\n\n");
            else
                printf("\nFuncionario nao encontrado!\n\n");

            system("pause");
            break;

        case 3:
            imprimir(lista);
            break;
        }
    } while (op != 9);

    return 0;
}
