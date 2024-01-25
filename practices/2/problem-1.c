/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// Obtener el factorial de un número

int main(){
	int n, sumatoria = 1;
	printf("\nProporciona el valor de n: ");
	scanf("%i", &n);
	for(int i = 1; i<=n; i++){
		sumatoria *= i;
	}
	printf("\nEl valor del factorial para el numero %i es %i", n, sumatoria);
}