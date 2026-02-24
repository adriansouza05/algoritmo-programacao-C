#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculo_delta(float a, float b, float c){
	return ((b * b) - 4 * a * c);
}

void calculo_raizes(float a, float b, float delta, float *x1, float *x2){
	*x1 = (-b + sqrt(delta)) / (2 * a);
	*x2 = (-b - sqrt(delta)) / (2 * a);
}

float calculo_vx(float b, float a){
	return (-b) / (2*a);
}

float calculo_vy(float delta, float a){
	return (-delta) / (4*a);
}


int main(){
	float valor_a, valor_b, valor_c;
	float delta, x1, x2;
	float vx, vy;
	
	printf("Informe o valor para A: ");
	scanf("%f", &valor_a);
	
	printf("Informe o valor para B: ");
	scanf("%f", &valor_b);
	
	printf("Informe o valor para C: ");
	scanf("%f", &valor_c);
	
	delta = calculo_delta(valor_a, valor_b, valor_c);
	
	if(delta < 0){
		printf("\nNao existe raiz real!\n");
		return 0;
	} else if(delta == 0){
		x1 = x2 = -valor_b / (2 * valor_a);
		printf("\nDelta igual a zero. Existe uma raiz real:\nX = %.2f\n", x1);
	} else{
		printf("\nDelta = %.1f\n", delta);
		
		calculo_raizes(valor_a, valor_b, delta, &x1, &x2);
		printf("X1 = %.2f\nX2 = %.2f\n", x1,x2);
	}
	
	vx = calculo_vx(valor_b, valor_a);
	vy = calculo_vy(delta, valor_a);
	printf("Vx = %.1f\n", vx);
	printf("Vy = %.1f\n", vy);
	
	return 0;
}