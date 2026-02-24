#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    float valor;
} Pessoa;

typedef struct {
    Pessoa pessoas[TAM];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return f->fim == TAM;
}

// Cadastra uma nova pessoa na fila
void cadastrar(Fila *f, char nome[], float valor) {
    if (estaCheia(f)) {
        printf("Fila cheia! Nao eh possivel cadastrar.\n");
        return;
    }

    strcpy(f->pessoas[f->fim].nome, nome);
    f->pessoas[f->fim].valor = valor;
    f->fim++;

    printf("Pessoa cadastrada com sucesso!\n");
}

// Atende (remove) a pessoa da frente da fila
void atender(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia! Ninguem para atender.\n");
        return;
    }

    printf("Atendendo %s - Valor a restituir: R$ %.2f\n", 
           f->pessoas[f->inicio].nome, f->pessoas[f->inicio].valor);

    f->inicio++;
}

// Imprime as pessoas na fila
void imprimir(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Pessoas na fila:\n");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d. Nome: %s | Valor: R$ %.2f\n", i - f->inicio + 1, f->pessoas[i].nome, f->pessoas[i].valor);
    }
}

int main() {
    Fila fila;
    int opcao;
    char nome[TAM_NOME];
    float valor;

    inicializar(&fila);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Atender pessoa\n");
        printf("3 - Imprimir fila\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Nome da pessoa: ");
                fgets(nome, TAM_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove o \n do final
                printf("Valor a restituir: R$ ");
                scanf("%f", &valor);
                cadastrar(&fila, nome, valor);
                break;
            case 2:
                atender(&fila);
                break;
            case 3:
                imprimir(&fila);
                break;
            case 9:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}
