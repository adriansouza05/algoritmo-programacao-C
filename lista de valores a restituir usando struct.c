#include <stdio.h>
#include <string.h>

#define TAM 100

typedef struct {
    char nome[50];
    float valor;
} Restituicao;

typedef struct {
    Restituicao itens[TAM];
    int quantidade;
} ListaRestituicoes;

// Inicializa a lista
void inicializar(ListaRestituicoes *lista) {
    lista->quantidade = 0;
}

// Verifica se a lista esta cheia
int estaCheia(ListaRestituicoes *lista) {
    return lista->quantidade == TAM;
}

// Verifica se a lista esta vazia
int estaVazia(ListaRestituicoes *lista) {
    return lista->quantidade == 0;
}

// Insere uma nova restituicao
void inserir(ListaRestituicoes *lista, char nome[], float valor) {
    if (estaCheia(lista)) {
        printf("Lista cheia! Nao eh possivel adicionar.\n");
        return;
    }

    strcpy(lista->itens[lista->quantidade].nome, nome);
    lista->itens[lista->quantidade].valor = valor;
    lista->quantidade++;

    printf("Restituicao adicionada com sucesso!\n");
}

// Remove uma restituicao pela posicao
void remover(ListaRestituicoes *lista, int posicao) {
    if (estaVazia(lista)) {
        printf("Lista vazia! Nao ha o que remover.\n");
        return;
    }

    if (posicao < 0 || posicao >= lista->quantidade) {
        printf("Posicao invalida!\n");
        return;
    }

    printf("Removendo %s (R$ %.2f)\n", 
        lista->itens[posicao].nome, 
        lista->itens[posicao].valor);

    for (int i = posicao; i < lista->quantidade - 1; i++) {
        lista->itens[i] = lista->itens[i + 1];
    }

    lista->quantidade--;
}

// Exibe a lista de restituicoes
void exibir(ListaRestituicoes *lista) {
    if (estaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nLista de valores a restituir:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d. Nome: %s - Valor: R$ %.2f\n", 
            i + 1, 
            lista->itens[i].nome, 
            lista->itens[i].valor);
    }
}

int main() {
    ListaRestituicoes lista;
    int opcao, pos;
    char nome[50];
    float valor;

    inicializar(&lista);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Adicionar restituicao\n");
        printf("2 - Remover restituicao\n");
        printf("3 - Exibir lista\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1:
                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove '\n'
                printf("Digite o valor a restituir: ");
                scanf("%f", &valor);
                inserir(&lista, nome, valor);
                break;

            case 2:
                printf("Digite a posicao para remover (1 ate %d): ", lista.quantidade);
                scanf("%d", &pos);
                remover(&lista, pos - 1); // Ajusta para indice
                break;

            case 3:
                exibir(&lista);
                break;

            case 9:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 9);

    return 0;
}