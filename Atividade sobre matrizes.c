#include <stdio.h>
#include <stdlib.h>
#define TAM 3

void carregar_matriz(int matriz[TAM][TAM]){
	system("cls");
	for(int linha=0; linha<TAM; linha++){
        for(int coluna=0; coluna<TAM; coluna++){
            printf("Informe um valor para a matriz na posicao [%d][%d]: ", linha,coluna);
            scanf("%d", &matriz[linha][coluna]);
        }
        printf("\n");
    }
	printf("Matriz registrada com sucesso!\n");
	system("pause");
}

void mostrar_matriz(int matriz[TAM][TAM]){
	system("cls");
	printf("Matriz:\n");
	for(int linha=0; linha<TAM; linha++){
        for(int coluna=0; coluna<TAM; coluna++){
            printf("%d | ", matriz[linha][coluna]);
        }
        printf("\n");
    }
	printf("\n");
	system("pause");
}

int somatoria_elementos_matriz(int matriz[TAM][TAM]){
    int somatoria = 0;
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            somatoria+=matriz[i][j];
        }
    }
    return somatoria;
}

int maior_elemento_matriz(int matriz[TAM][TAM]){
    int maior_elemento = 0;
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if(matriz[i][j] > maior_elemento)
                maior_elemento = matriz[i][j];
        }
    }
    return maior_elemento;
}

int qnd_impares_diagonal_secundaria(int matriz[TAM][TAM]){
    int qnd_impares = 0;
    for(int linha = 0; linha<TAM; linha++){
        if(matriz[linha][TAM - 1 - linha] % 2 != 0){
            qnd_impares++;
        }
    }
    return qnd_impares;
}

int somatoria_pares_diagonal_principal(int matriz[TAM][TAM]){
    int soma_pares = 0;
    for(int linha = 0; linha<TAM; linha++){
        if(matriz[linha][linha] % 2 == 0){
            soma_pares += matriz[linha][linha];
        }
    }
    return soma_pares;
}

int diferenca_somatoria_diagonais(int matriz[TAM][TAM]){
    int soma_principal = 0;
    int soma_secundaria = 0;
    for(int linha=0; linha<TAM; linha++){
        soma_principal += matriz[linha][linha];
        soma_secundaria += matriz[linha][TAM - 1 - linha];
    }
    return soma_principal - soma_secundaria;
}

int dobrar_elementos_matriz(int matriz[TAM][TAM]){
    for(int linha=0; linha<TAM; linha++){
        for(int coluna=0; coluna<TAM; coluna++){
            matriz[linha][coluna] *= 2;
        }
    }
    return 0;
}

void dobrar_elementos_linhas_pares(int matriz[TAM][TAM]){
    system("cls");
    int matriz2[TAM][TAM] = {0};
    for(int linha=0; linha<TAM; linha++){
        for(int coluna=0; coluna<TAM; coluna++){
            if(linha % 2 == 0){
                matriz2[linha][coluna] = matriz[linha][coluna] * 2;
            } else{
                matriz2[linha][coluna] = matriz[linha][coluna];
            }
        }
    }
    printf("Matriz com linhas pares dobradas:\n");
    for(int linha=0; linha<TAM; linha++){
        for(int coluna=0; coluna<TAM; coluna++){
            printf("%d | ", matriz2[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
}

char funcao_menu(){
	char opcao;

	system("cls");
	printf("* * * M E N U * * *\n");
	printf("a - Registrar dados na matriz\n");
	printf("b - Imprimir a matriz\n");
	printf("c - Somatoria dos elementos da matriz\n");
	printf("d - Maior elemento da matriz\n");
	printf("e - Calcule a quantidade de numeros impares da diagonal secundaria\n");
	printf("f - Calcule a somatoria dos numeros pares da diagonal principal\n");
	printf("g - Calcule a diferenca entre a somatoria da diagonal principal pela somatoria dos elementos da diagonal secundaria\n");
	printf("h - Dobrar os elementos da matriz\n");
	printf("i - Faca uma copia da matriz em uma segunda matriz dobrando os elementos que estao nas linhas pares\n");
	printf("0 - Para encerrar programa\n");
	printf("* * * * * * * * * *\n\n");

	printf("Informe sua opcao: ");
	scanf(" %c", &opcao);

	return opcao;
}

int main() {
    int matriz[TAM][TAM] = {0};
    char opcao_main;
	
	do{
		opcao_main = funcao_menu();

		switch (opcao_main){
		case 'a':
			carregar_matriz(matriz);
			break;

        case 'b':
			mostrar_matriz(matriz);
			break;

		case 'c':
			system("cls");
            printf("A somatoria dos elementos da matriz eh = %d\n\n", somatoria_elementos_matriz(matriz));
            system("pause");
			break;

		case 'd':
			system("cls");
            printf("O maior elemento da matriz eh = %d\n\n", maior_elemento_matriz(matriz));
            system("pause");
			break;

		case 'e':
            system("cls");
			printf("A quantidade de impares na diagonal secundaria eh = %d\n\n", qnd_impares_diagonal_secundaria(matriz));
            system("pause");
			break;

		case 'f':
            system("cls");
			printf("A somatoria dos elementos pares da diagonal principal eh = %d\n\n", somatoria_pares_diagonal_principal(matriz));
            system("pause");
			break;

		case 'g':
			system("cls");
			printf("A diferenca da somatoria das diagonais eh = %d\n\n", diferenca_somatoria_diagonais(matriz));
            system("pause");
			break;

		case 'h':
			system("cls");
            dobrar_elementos_matriz(matriz);
			printf("Elementos da matriz dobrados com sucesso!\n\n");
            system("pause");
			break;

		case 'i':
			dobrar_elementos_linhas_pares(matriz);
			break;
		
		case '0':
			break;
		
		default:
			printf("\nValores invalidos!\n");
			system("pause");
			break;
		}
	} while(opcao_main != '0');
	
	printf("\nExecucao encerrada com sucesso!\n");
    return 0;
}