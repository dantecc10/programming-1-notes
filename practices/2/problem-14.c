/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// n impares

int main(){
	int n;
	
	printf("\nIndica el valor de n: ");
	scanf("%i", &n);
	
	printf("\nLos primeros %i impares son: ", n);
	for(int i = 0; i<n; i++){
		printf("\n%i.- %i", (i+1), (((i+1)*2)-1));
	}
}