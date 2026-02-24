#include <stdio.h>

#define TAM 100

typedef struct {
    int dados[TAM];
    int fim;
} Lista;

// Inicializa a lista
void inicializar(Lista *l) {
    l->fim = -1;
}

// Verifica se a lista está cheia
int estaCheia(Lista *l) {
    return l->fim == TAM - 1;
}

// Verifica se a lista está vazia
int estaVazia(Lista *l) {
    return l->fim == -1;
}

// Insere um elemento em uma posição válida
void inserir(Lista *l, int valor, int pos) {
    if (estaCheia(l)) {
        printf("Lista cheia! Nao eh possível inserir.\n");
        return;
    }

    if (pos < 0 || pos > l->fim + 1) {
        printf("Posicao invalida para insercao.\n");
        return;
    }

    for (int i = l->fim + 1; i > pos; i--) {
        l->dados[i] = l->dados[i - 1];
    }

    l->dados[pos] = valor;
    l->fim++;

    printf("Valor %d inserido na posicao %d.\n", valor, pos);
}

// Remove um elemento de uma posição válida
void remover(Lista *l, int pos) {
    if (estaVazia(l)) {
        printf("Lista vazia! Nao ha elementos para remover.\n");
        return;
    }

    if (pos < 0 || pos > l->fim) {
        printf("Posicao invalida para remocao.\n");
        return;
    }

    int valor = l->dados[pos];

    for (int i = pos; i < l->fim; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->fim--;

    printf("Valor %d removido da posicao %d.\n", valor, pos);
}

// Imprime os elementos da lista
void imprimir(Lista *l) {
    if (estaVazia(l)) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Elementos da lista:\n");
    for (int i = 0; i <= l->fim; i++) {
        printf("[%d] %d\n", i, l->dados[i]);
    }
}

int main() {
    Lista lista;
    int opcao, valor, pos;

    inicializar(&lista);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("9 - Fim\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao (0 ate %d): ", lista.fim + 1);
                scanf("%d", &pos);
                inserir(&lista, valor, pos);
                break;
            case 2:
                printf("Digite a posicao para remover (0 ate %d): ", lista.fim);
                scanf("%d", &pos);
                remover(&lista, pos);
                break;
            case 3:
                imprimir(&lista);
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
