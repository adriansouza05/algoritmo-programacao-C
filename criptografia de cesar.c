#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME 256
#define MAX_LINE 1024

// Função para aplicar a Cifra de César
void cifra_cesar(char *texto, int chave, int criptografar) {
    int i;
    char c;
    
    // Se for para descriptografar, inverte a chave
    if (!criptografar) {
        chave = -chave;
    }
    
    for (i = 0; texto[i] != '\0'; i++) {
        c = texto[i];
        
        // Criptografa letras maiúsculas
        if (c >= 'A' && c <= 'Z') {
            texto[i] = ((c - 'A' + chave + 26) % 26) + 'A';
        }
        // Criptografa letras minúsculas
        else if (c >= 'a' && c <= 'z') {
            texto[i] = ((c - 'a' + chave + 26) % 26) + 'a';
        }
        // Outros caracteres permanecem inalterados
    }
}

// Função para criptografar arquivo
int criptografar_arquivo(char *nome_arquivo, int chave) {
    FILE *arquivo_original, *arquivo_criptografado;
    char linha[MAX_LINE];
    char nome_saida[MAX_FILENAME];
    
    // Abre arquivo original para leitura
    arquivo_original = fopen(nome_arquivo, "r");
    if (arquivo_original == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo '%s' para leitura.\n", nome_arquivo);
        return 0;
    }
    
    // Cria nome do arquivo criptografado
    snprintf(nome_saida, sizeof(nome_saida), "%s.criptografado", nome_arquivo);
    
    // Abre arquivo de saída para escrita
    arquivo_criptografado = fopen(nome_saida, "w");
    if (arquivo_criptografado == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo '%s'.\n", nome_saida);
        fclose(arquivo_original);
        return 0;
    }
    
    // Lê linha por linha e criptografa
    while (fgets(linha, sizeof(linha), arquivo_original) != NULL) {
        cifra_cesar(linha, chave, 1); // 1 = criptografar
        fputs(linha, arquivo_criptografado);
    }
    
    fclose(arquivo_original);
    fclose(arquivo_criptografado);
    
    printf("Arquivo criptografado com sucesso!\n");
    printf("Arquivo de saida: %s\n", nome_saida);
    return 1;
}

// Função para descriptografar arquivo
int descriptografar_arquivo(char *nome_arquivo, int chave) {
    FILE *arquivo_criptografado, *arquivo_descriptografado;
    char linha[MAX_LINE];
    char nome_saida[MAX_FILENAME];
    
    // Abre arquivo criptografado para leitura
    arquivo_criptografado = fopen(nome_arquivo, "r");
    if (arquivo_criptografado == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo '%s' para leitura.\n", nome_arquivo);
        return 0;
    }
    
    // Cria nome do arquivo descriptografado
    snprintf(nome_saida, sizeof(nome_saida), "%s.descriptografado", nome_arquivo);
    
    // Abre arquivo de saída para escrita
    arquivo_descriptografado = fopen(nome_saida, "w");
    if (arquivo_descriptografado == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo '%s'.\n", nome_saida);
        fclose(arquivo_criptografado);
        return 0;
    }
    
    // Lê linha por linha e descriptografa
    while (fgets(linha, sizeof(linha), arquivo_criptografado) != NULL) {
        cifra_cesar(linha, chave, 0); // 0 = descriptografar
        fputs(linha, arquivo_descriptografado);
    }
    
    fclose(arquivo_criptografado);
    fclose(arquivo_descriptografado);
    
    printf("Arquivo descriptografado com sucesso!\n");
    printf("Arquivo de saida: %s\n", nome_saida);
    return 1;
}

// Função para visualizar conteúdo do arquivo
void visualizar_arquivo(char *nome_arquivo) {
    FILE *arquivo;
    char linha[MAX_LINE];
    int numero_linha = 1;
    
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo '%s' para leitura.\n", nome_arquivo);
        return;
    }
    
    printf("\n--- Conteudo do arquivo '%s' ---\n", nome_arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%3d: %s", numero_linha, linha);
        numero_linha++;
    }
    printf("--- Fim do arquivo ---\n\n");
    
    fclose(arquivo);
}

// Função para exibir o menu
void exibir_menu() {
    printf("\n=== PROGRAMA DE CRIPTOGRAFIA DE ARQUIVOS ===\n");
    printf("1. Criptografar arquivo\n");
    printf("2. Descriptografar arquivo\n");
    printf("3. Visualizar arquivo\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para obter uma chave válida
int obter_chave() {
    int chave;
    printf("Digite a chave (deslocamento) para a Cifra de Cesar (1-25): ");
    scanf("%d", &chave);
    
    // Garante que a chave está no intervalo válido
    chave = ((chave % 26) + 26) % 26;
    if (chave == 0) chave = 1; // Evita chave 0
    
    return chave;
}

// Função principal
int main() {
    int opcao, chave;
    char nome_arquivo[MAX_FILENAME];
    
    printf("Bem-vindo ao Sistema de Criptografia de Arquivos!\n");
    printf("Este programa utiliza a Cifra de Cesar para criptografar/descriptografar arquivos de texto.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: // Criptografar
                printf("\n--- CRIPTOGRAFAR ARQUIVO ---\n");
                printf("Digite o nome do arquivo a ser criptografado: ");
                scanf("%s", nome_arquivo);
                
                chave = obter_chave();
                
                if (criptografar_arquivo(nome_arquivo, chave)) {
                    printf("Chave utilizada: %d\n", chave);
                    printf("IMPORTANTE: Anote a chave para poder descriptografar o arquivo!\n");
                }
                break;
                
            case 2: // Descriptografar
                printf("\n--- DESCRIPTOGRAFAR ARQUIVO ---\n");
                printf("Digite o nome do arquivo a ser descriptografado: ");
                scanf("%s", nome_arquivo);
                
                chave = obter_chave();
                
                if (descriptografar_arquivo(nome_arquivo, chave)) {
                    printf("Arquivo descriptografado usando a chave: %d\n", chave);
                }
                break;
                
            case 3: // Visualizar arquivo
                printf("\n--- VISUALIZAR ARQUIVO ---\n");
                printf("Digite o nome do arquivo a ser visualizado: ");
                scanf("%s", nome_arquivo);
                
                visualizar_arquivo(nome_arquivo);
                break;
                
            case 4: // Sair
                printf("\nObrigado por usar o programa de criptografia!\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        
        if (opcao != 4) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Limpa o buffer
            getchar(); // Aguarda Enter
        }
        
    } while (opcao != 4);
    
    return 0;
}

/*
=== INSTRUÇÕES DE USO ===

1. Compilação:
   gcc -o criptografia criptografia.c

2. Execução:
   ./criptografia

3. Funcionamento:
   - O programa utiliza a Cifra de César para criptografar/descriptografar
   - Apenas letras são alteradas (A-Z, a-z)
   - Números, espaços e símbolos permanecem inalterados
   - Arquivos criptografados recebem extensão .criptografado
   - Arquivos descriptografados recebem extensão .descriptografado

4. Exemplo de uso:
   - Crie um arquivo "teste.txt" com algum texto
   - Use a opção 1 para criptografar com chave 3
   - Use a opção 3 para visualizar o resultado
   - Use a opção 2 para descriptografar com a mesma chave

5. Dicas:
   - Anote sempre a chave usada para criptografar
   - A chave deve ser a mesma para criptografar e descriptografar
   - Teste com arquivos pequenos primeiro
*/