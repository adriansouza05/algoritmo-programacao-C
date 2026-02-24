#include <stdio.h>
#include <stdlib.h>

int main() {
    char resp;
    float nota, soma = 0, media = 0;
    int cont = 0;

    do {
        printf("\nInforme a nota do aluno: ");
        scanf("%f", &nota);

        if(nota < 0 || nota > 10){
            printf("\nNota invalida!(notas menores que 0 e maiores que 10 serao anuladas)\n");
        } else{
            soma+=nota;
            cont++;
            media = soma / cont;
        }

        printf("\nQuer continuar a execucao do programa? [S/N]: ");
        scanf(" %c", &resp);
        
    } while(resp != 'N' && resp != 'n');

    printf("\nA media das notas eh = %.2f\n", media);

    return 0;
}
