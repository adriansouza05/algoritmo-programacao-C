#include <stdio.h>
#include <stdlib.h>

int soma(int num, int num2){
    return num + num2;
}

int subtracao(int num, int num2){
    return num - num2;
}

int multiplicacao(int num, int num2){
    return num * num2;
}

float divisao(int num, int num2){
    if(num2 == 0){
        printf("\nNao eh possivel dividir por ZERO!\n");
        return 0;
    }
    return (float)num / num2;
}

int menu(){
    int opcao;

    system("cls");
    printf("\t* * * CALCULADORA * * *\n\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("0 - Sair\n\n");

    printf("Informe sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main(){
    int opcao_main;
    int num, num2 = 0;

    do{
        opcao_main = menu();
        
        switch(opcao_main){
            case 1:
                system("cls");
                printf("Informe um numero: ");
                scanf("%d", &num);
                printf("Informe mais numero: ");
                scanf("%d", &num2);
                printf("\n%d + %d = %d\n\n", num, num2, soma(num, num2));
                system("pause");
                break;

            case 2:
                system("cls");
                printf("Informe um numero: ");
                scanf("%d", &num);
                printf("Informe mais numero: ");
                scanf("%d", &num2);
                printf("\n%d - %d = %d\n\n", num, num2, subtracao(num, num2));
                system("pause");
                break;
                
            case 3:
                system("cls");
                printf("Informe um numero: ");
                scanf("%d", &num);
                printf("Informe mais numero: ");
                scanf("%d", &num2);
                printf("\n%d * %d = %d\n\n", num, num2, multiplicacao(num, num2));
                system("pause");
                break;

            case 4:
                system("cls");
                printf("Informe um numero: ");
                scanf("%d", &num);
                printf("Informe mais numero: ");
                scanf("%d", &num2);
                printf("\n%d / %d = %.1f\n\n", num, num2, divisao(num, num2));
                system("pause");
                break;

            case 0:
                break;

            default:
                printf("\nValor invalido!\n");
                system("pause");
                break;
        }
    } while(opcao_main != 0);

    return 0;
}