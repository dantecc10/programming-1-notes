#include <stdio.h>

int main() {
	int n, acumulador = 0;
	printf("\nIngrese el valor de n: ");
	scanf("%i", &n);

	int A[n], B[n], C[n];

	printf("\nIngrese los valores del primer arreglo: ");
	for(int i = 0; i<n; i++) {
		printf("\nA[%i]: ", i);
		scanf("%i", &A[i]);
	}
	printf("\nIngrese los valores del segundo arreglo: ");
	for(int i = 0; i<n; i++) {
		printf("\nB[%i]: ", i);
		scanf("%d", &B[i]);
	}
	
	for(int j = 0; j<n; j++) {
		acumulador += (A[j] * B[j]);
	}
	printf("\nEl producto punto de los arreglos ingresados es: %d", acumulador);
}