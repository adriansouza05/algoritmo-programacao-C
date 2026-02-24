#include <stdio.h>
#include <stdlib.h>
 
int main() {
    char resp;
    
    float altura = 0, peso = 0, soma_peso = 0, soma_altura = 0, 
    maior_peso = -1, menor_peso = 999, menor_altura = 999, 
    maior_altura = -1, media_peso = 0, media_altura = 0, maior_imc = -1, menor_imc = 999,
    media_imc = 0, imc = 0, soma_imc = 0;

    int cont = 0;

    do{
        printf("Informe seu peso(em kg, ex: 76kg): ");
        scanf("%f", &peso);

        printf("Informe sua altura(em metros, ex: 1.80m): ");
        scanf("%f", &altura);

        if (peso > 0 && altura > 0){
            soma_peso+=peso;
            if(peso > maior_peso)
                maior_peso = peso;
            if(peso < menor_peso)
                menor_peso = peso;
    
            soma_altura+=altura;
            if(altura > maior_altura) maior_altura = altura;
            if(altura < menor_altura) menor_altura = altura;

            imc = peso / (altura * altura);
            soma_imc+=imc;
            if(imc > maior_imc) maior_imc = imc;
            if(imc < menor_imc)  menor_imc = imc;

            cont++;
        } else{
        printf("\nValores invalidos! peso e altura devem ser maior que 0.\n");
    }

    printf("Gostaria de continuar?[S/N]: ");
    scanf(" %c", &resp);

    } while (resp != 'N' && resp != 'n');

    if(cont > 0){
        media_peso = soma_peso / cont;
        media_altura = soma_altura / cont;
        media_imc = soma_imc / cont;
    

        printf("\nO maior peso eh = %.2fkg", maior_peso);
        printf("\nO menor peso eh = %.2fkg", menor_peso);
        printf("\nA media de pesos eh = %.2fkg\n", media_peso);

        printf("\nA maior altura eh = %.2fm", maior_altura);
        printf("\nA menor altura eh = %.2fm", menor_altura);
        printf("\nA media de altura eh = %.2fm\n", media_altura);

        printf("\nO menor IMC eh = %.2f", menor_imc);
        printf("\nO maior IMC eh = %.2f", maior_imc);
        printf("\nA media dos IMC's eh = %.2f\n\n", media_imc);
    } else {
        printf("\nNenhum valor valido foi informado.\n");
    }

    return 0;
}