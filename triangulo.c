#include <stdio.h>
#include <stdlib.h>

void formar_triangulo(int a, int b, int c){
    if(a + b > c && a + c > b && b + c > a){
        printf("\nEh possivel formar um triangulo!\n");
        if(a == b  &&  b == c)
            printf("Triangulo Equilatero, todos os lados sao iguais!\n\n");
        else if(a == b || a == c || b == c)
            printf("Triangulo Isosceles, tem pelo menos dois lados com a mesma medida!\n\n");
        else
            printf("Triangulo Escaleno, todos os tres lados tem medidas diferentes!\n\n");
    }
    else
        printf("\nNao eh possivel formar um triangulo!\n");
}


int main(){
    int a, b, c;
    char resp;

    do{
        printf("informe o valor do lado A: ");
        scanf("%d", &a);

        printf("informe o valor do lado B: ");
        scanf("%d", &b);

        printf("informe o valor do lado C: ");
        scanf("%d", &c);

        formar_triangulo(a,b,c);

        printf("\nGostaria de continuar?[S/N]: ");
        scanf(" %c", &resp);

    } while(resp != 'N' && resp != 'n');

    return 0;
}