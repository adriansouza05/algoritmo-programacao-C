#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main(){
    char vetorChar[MAX];
    int vetorInt[MAX];
    char resp;
    int i;

    do {
        printf("Digite uma palavra: ");
        scanf("%s", vetorChar);

        // Copiar cada caractere para vetorInt
        for(i = 0; vetorChar[i] != '\0'; i++){
            vetorInt[i] = vetorChar[i];
        }

        // Imprimir lado a lado
        printf("\nCaractere | ASCII\n");
        for(i = 0; vetorChar[i] != '\0'; i++){
            printf("    %c     |  %d\n", vetorChar[i], vetorInt[i]);
        }

        printf("\nGostaria de continuar a execucao do programa? [S/N]: ");
        scanf(" %c", &resp);

    } while(resp != 'n' && resp != 'N');

    return 0;
}
