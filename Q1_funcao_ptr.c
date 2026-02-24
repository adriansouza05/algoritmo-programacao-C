/*Questão 1 - Básica:
Implemente uma função trocar que recebe dois ponteiros para inteiros e 
troca seus valores. Crie um programa principal que teste a função.*/

#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b){ //void pq nao queremos retornar nada
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x=1, y=2;

    printf("\n%d %d", x, y);

    trocar(&x, &y);

    printf("\n%d %d", x, y); //se eu deixar "&x, xy", vai aparecer os endereços de memoria, que nao é isso que queremos

    return 0;
}