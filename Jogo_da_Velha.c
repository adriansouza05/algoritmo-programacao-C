#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3

void mostrar_jogo(char matriz[TAM][TAM])
{
    printf("\n   0   1   2\n");
    for (int linha = 0; linha < TAM; linha++)
    {
        printf("%d  ", linha);
        for (int coluna = 0; coluna < TAM; coluna++)
        {
            printf(" %c ", matriz[linha][coluna]);
            if (coluna < TAM - 1)
                printf("|");
        }
        printf("\n");
        if (linha < TAM - 1)
            printf("   ---+---+---\n");
    }
}

int verificar_vitoria(char matriz[TAM][TAM], char jogador)
{
    // Linhas
    for (int i = 0; i < TAM; i++)
    {
        if (matriz[i][0] == jogador && matriz[i][1] == jogador && matriz[i][2] == jogador)
            return 1;
    }
    // Colunas
    for (int j = 0; j < TAM; j++)
    {
        if (matriz[0][j] == jogador && matriz[1][j] == jogador && matriz[2][j] == jogador)
            return 1;
    }
    // Diagonais
    if (matriz[0][0] == jogador && matriz[1][1] == jogador && matriz[2][2] == jogador)
        return 1;
    if (matriz[0][2] == jogador && matriz[1][1] == jogador && matriz[2][0] == jogador)
        return 1;

    return 0;
}

int verificar_empate(char matriz[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j] == ' ')
                return 0; // ainda tem espaço
        }
    }
    return 1; // deu velha
}

void jogada_usuario(char matriz[TAM][TAM])
{
    int linha, coluna;
    do
    {
        printf("\nSua vez!\n");
        printf("Informe a linha (0-2): ");
        scanf("%d", &linha);
        printf("Informe a coluna (0-2): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM || matriz[linha][coluna] != ' ')
        {
            printf("\nPosicao invalida! Tente novamente.\n");
        }
        else
        {
            matriz[linha][coluna] = 'X';
            break;
        }
    } while (1);
}

void jogada_maquina(char matriz[TAM][TAM])
{
    int linha, coluna;
    printf("\nVez da maquina...\n");

    do
    {
        linha = rand() % TAM;
        coluna = rand() % TAM;
    } while (matriz[linha][coluna] != ' ');

    matriz[linha][coluna] = 'O';
}

void jogar()
{
    char matriz[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = ' ';

    int acabou = 0;
    while (!acabou)
    {
        mostrar_jogo(matriz);

        jogada_usuario(matriz);
        if (verificar_vitoria(matriz, 'X'))
        {
            mostrar_jogo(matriz);
            printf("\nVoce venceu!\n");
            break;
        }
        if (verificar_empate(matriz))
        {
            mostrar_jogo(matriz);
            printf("\nDeu velha!\n");
            break;
        }

        jogada_maquina(matriz);
        if (verificar_vitoria(matriz, 'O'))
        {
            mostrar_jogo(matriz);
            printf("\nA maquina venceu!\n");
            break;
        }
        if (verificar_empate(matriz))
        {
            mostrar_jogo(matriz);
            printf("\nDeu velha!\n");
            break;
        }
    }
}

int main()
{
    srand(time(NULL)); // inicializa gerador de números aleatórios
    int opcao;

    do
    {
        printf("\n****** JOGO DA VELHA ******\n");
        printf("1 - Jogar\n");
        printf("0 - Sair\n");
        printf("***************************\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            jogar();
            break;
        case 0:
            printf("\nEncerrando...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
