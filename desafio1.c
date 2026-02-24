/*Média de Valores: Crie um programa que leia 10 números 
inteiros e os armazene em um vetor. Em seguida, calcule 
e imprima a média desses números.*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    int vetor[10] = {0};
    float media = 0;
    float soma = 0;

    for(int i=0; i<10; i++){
        printf("Informe o %d° valor para o vetor[%d]: ", i+1, i);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / 10;

    printf("A media dos elementos do vetor eh = %.2f", media);

    return 0;
}