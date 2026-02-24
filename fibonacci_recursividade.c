#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num)
{
    if (num == 0)
        return 0; // caso base 1
    else if (num == 1)
        return 1; // caso base 2
    else
        return fibonacci(num - 1) + fibonacci(num - 2); // chamada recursiva
}

int main()
{
    int qnd;

    printf("Quantos numeros voce quer mostrar pra sequencia: ");
    scanf("%d", &qnd);

    if (qnd <= 0)
        return 1;

    for (int i = 0; i < qnd; i++)
        printf("%d ", fibonacci(i));

    return 0;
}
