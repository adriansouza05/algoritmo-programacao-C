#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0;

    do{
        printf("\n\nInforme um numero para mostrar sua tabuada(digite -1 para sair): ");
        scanf("%d", &num);

        if(num == -1)
            break; 

        for(int i=0; i<=10; i++)
            printf("\n%d x %d = %d", num, i, num * i);
    } while(num != -1);
    
    return 0;
}