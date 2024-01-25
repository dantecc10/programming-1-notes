/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// Sacar promedio de números

int main(){
	int n;
	float num, sumatoria = 0;
	printf("\nProporciona la cantidad de datos: ");
	scanf("%i", &n);
	for(int i = 0; i<n; i++){
		printf("\n%i° numero: ", (i+1));
		scanf("%f", &num);
		sumatoria += num;
	}
	printf("\nEl promedio de los numeros es: %.3f", (sumatoria/n));
}