#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void inserir (int v[])
{
    int i;
    system ("cls");
    printf("* * * *   Cadastrar elementos do vetor    * * * *\n\n");
    for(i=0;i<TAM;i++)
    {
        printf("\nDigite o elemento para vetor[%d]: ",i);
        scanf("%d",&v[i]);
    }
    printf("\n\nElementos cadastrados com sucesso!!\n\n");
    system("pause");
}

void imprimir (int v[])
{
    int i;
    system("cls");
    printf("* * * *   Impressao do vetor   * * * *\n\n");
    for(i=0;i<TAM;i++)
    {
        printf("%d\t",v[i]);
    }
    printf("\n\n");
    system("pause");
}

int somatoria (int v[])
{
    int acc=0;
    for(int i=0;i<TAM;i++)
        acc+=v[i];
    return acc;
}

int menu()
{
    int opcao;
    system("cls");
    printf("* * * *   M E N U   * * * *\n\n");
    printf("\n1 - Cadastrar elementos no vetor");
    printf("\n2 - Imprimir os elementos do vetor");
    printf("\n3 - Calcular a somatoria dos elementos do vetor");
    printf("\n9 - Sair");
    printf("\nDigite a sua opcao: ");
    scanf("%d",&opcao);
    return opcao;
}


int main(){
	
    int vetor[TAM];
    int op;
    
    do{
        op=menu();

        switch(op){
            case 1 : 
				inserir(vetor);
                break;

            case 2 : 
				imprimir(vetor);
                break;

            case 3 : system("cls");
                     printf("* * * *  Somatoria vetor   * * * *\n\n");
                     printf("\nA somatoria dos elementos do vetor eh: %d\n\n",somatoria(vetor));
                     system("pause");
                     break;
    	}
    }while(op!=9);

    return 0;
}