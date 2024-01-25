/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// Valor de serie

int main(){
	int n;
	float total_s = 0;
	printf("\nProporciona el valor de n: ");
	scanf("%i", &n);
	
	for(float i = 0; i<n; i++){
		total_s += (1/(i+1));
	}
	
	printf("\nEl valor total de la serie 1/i hasta %i es %.4f", n, total_s);
}