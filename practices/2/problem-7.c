/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// Potencias

int main(){
	int b;
	float a, pot = 1;
	
	printf("\nProporciona el valor de a: ");
	scanf("%f", &a);
	
	printf("\nProporciona el valor de b: ");
	scanf("%i", &b);
	
	for(int i = 0; i<b; i++){
		pot *= a;
	}
	
	printf("\nEl resultado de elevar %f a la potencia %i es: %f", a, b, pot);
}