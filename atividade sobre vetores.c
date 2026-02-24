#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void carregar_vetor(int vetor[TAM]){
    system("cls");
    for(int i=0; i<TAM; i++){
        printf("Informe um numero para o indice [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\n\n");
    system("pause");
}

void mostrar_vetor(int vetor[TAM]){
    system("cls");
    printf("Vetor:\n");
    for(int i=0; i<TAM; i++){
        printf("%d | ", vetor[i]);
    }
    printf("\n\n");
    system("pause");
}

void dobrar_numeros_pares_vetor(int vetor[TAM]){
    system("cls");
    for(int i=0; i<TAM; i++){
        if(vetor[i] % 2 == 0)
            vetor[i] *= 2;
    }
    printf("\nNumeros pares dobrados com sucesso!\n\n");
    system("pause");
}

void dobrar_numeros_vetor(int vetor[TAM]){
    system("cls");
    for(int i=0; i<TAM; i++)
        vetor[i] *= 2;
    printf("\nTodos os numeros dobrados com sucesso!\n\n");
    system("pause");
}

void somatoria_vetor(int vetor[TAM]){
    int somatoria = 0;
    system("cls");
    for(int i=0; i<TAM; i++)
        somatoria+=vetor[i];
    printf("\nSomatoria dos elementos do vetor = %d\n\n", somatoria);
    system("pause");
}

void maior_elemento_vetor(int vetor[TAM]){
    int maior_elemento = vetor[0];
    system("cls");
    for(int i=1; i<TAM; i++){
        if(vetor[i] > maior_elemento)
            maior_elemento = vetor[i];
    }
    printf("\nO maior elemento do vetor eh = %d\n\n", maior_elemento);
    system("pause");
}

void somatoria_impares_vetor(int vetor[TAM]){
    int somatoria_impares = 0;
    system("cls");
    for(int i=0; i<TAM; i++){
        if(vetor[i] % 2 != 0)
            somatoria_impares += vetor[i];
    }
    printf("\nA somatoria dos elementos impares do vetor eh = %d\n\n", somatoria_impares);
    system("pause");
}

void numeros_divisiveis_por_tres(int vetor[TAM]){
    int qnd_numeros_divi_tres = 0;
    system("cls");
    for(int i=0; i<TAM; i++){
        if(vetor[i] % 3 == 0)
            qnd_numeros_divi_tres++;
    }
    printf("\nA quantidade de numeros divisiveis por 3 eh = %d\n\n", qnd_numeros_divi_tres);
    system("pause");
}

void menor_numero_do_indice_vetor(int vetor[TAM]){
    system("cls");
    int menor_numero = vetor[0];
    int posicao = 0;

    for(int i=1; i<TAM; i++){
        if(vetor[i] < menor_numero){
            menor_numero = vetor[i];
            posicao = i;
        }
    }
    printf("\nO menor numero do vetor eh = %d que esta no indice[%d]\n\n", menor_numero, posicao);
    system("pause");
}

// agora realmente cria o vetor invertido
void criar_vetor_invertido(int vetor[TAM], int invertido[TAM]){
    for(int i=0; i<TAM; i++){
        invertido[i] = vetor[TAM-1-i];
    }
}

void mostrar_vetor_invertido(int invertido[TAM]){
    system("cls");
    printf("Vetor invertido:\n");
    for(int j=0; j<TAM; j++)
        printf("%d | ", invertido[j]);
    printf("\n\n");
    system("pause");
}

void mostrar_vetores_juntos(int vetor[TAM], int invertido[TAM]){
    system("cls");
    printf("Vetor:                              Vetor invertido:\n");
    for(int i=0; i<TAM; i++)
        printf("[%d]", vetor[i]);
    printf(" || ");
    for(int j=0; j<TAM; j++)
        printf("[%d]", invertido[j]);
    printf("\n\n");
    system("pause");
}

char menu(){
    char opcao;

    system("cls");
    printf("* * * M E N U * * *\n");
    printf("a - Carregar o vetor com numeros digitados pelo usuario\n");
    printf("b - Mostrar o vetor na tela\n");
    printf("c - Dobrar  os elementos do vetor, porem apenas os numeros pares\n");
    printf("d - Dobrar todos os elementos do vetor\n");
    printf("e - Calcular e imprimir a somatoria dos numeros do vetor\n");
    printf("f - Calcular e imprimir o maior elemento do vetor\n");
    printf("g - Calcular e imprimir a somatoria dos numeros impares do vetor\n");
    printf("h - Calcular e imprimir a quantidade de numeros divisiveis por 3 que estao no vetor\n");
    printf("i - Encontrar a posicao do menor elemento do vetor e imprimir a posicao na tela do computador\n");
    printf("j - Criar um segundo vetor invertido e mostrar\n");
    printf("k - Imprimir os dois vetores lado a lado\n");
    printf("0 - para sair\n");
    printf("* * * * * * * * * *\n\n");

    printf("Informe sua opcao: ");
    scanf(" %c", &opcao);

    return opcao;
}

int main(){
    char opcao_main;
    int vetor[TAM] = {0};
    int invertido[TAM] = {0};
    
    do{
        opcao_main = menu();

        switch (opcao_main){
        case 'a':
            carregar_vetor(vetor);
            break;

        case 'b':
            mostrar_vetor(vetor);
            break;

        case 'c':
            dobrar_numeros_pares_vetor(vetor);
            break;

        case 'd':
            dobrar_numeros_vetor(vetor);
            break;

        case 'e':
            somatoria_vetor(vetor);
            break;

        case 'f':
            maior_elemento_vetor(vetor);
            break;

        case 'g':
            somatoria_impares_vetor(vetor);
            break;

        case 'h':
            numeros_divisiveis_por_tres(vetor);
            break;

        case 'i':
            menor_numero_do_indice_vetor(vetor);
            break;

        case 'j':
            criar_vetor_invertido(vetor, invertido);
            mostrar_vetor_invertido(invertido);
            break;

        case 'k':
            mostrar_vetores_juntos(vetor, invertido);
            break;
        
        case '0':
            break;
        
        default:
            printf("\nOpcao invalida!\n");
            system("pause");
            break;
        }
    } while(opcao_main != '0');
    
    printf("\nExecucao encerrada com sucesso!\n");

    return 0;
}
