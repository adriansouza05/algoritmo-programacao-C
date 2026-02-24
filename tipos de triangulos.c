#include <stdio.h>

int main(){
	int lado[3];

	for(int i=0; i<3; i++){
		printf("Informe o lado%d: ", i+1);
		scanf("%d", &lado[i]);
	}
	
	if(lado[0] + lado[1] > lado[2] && lado[1] + lado[2] > lado[0] && lado[0] + lado[2] > lado[1]){
		printf("\nTemos um triangulo!\n");
		if(lado[0] == lado[1] && lado[1] == lado[2])
			printf("\nEquilatero!\n");
		else if(lado[0] != lado[1] && lado[1] != lado[2] && lado[2] != lado[0])
			printf("\nEscaleno!\n");
		else
			printf("\nIsosceles!\n");
	}else
		printf("\nNao temos um triangulo!\n");
	
	return 0;
}
