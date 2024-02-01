#include <stdio.h>

int main() {
	int n;
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
	for(int j = 1; j<(n-1); j++) {
		C[j] = ((A[j]*B[j+1])-(B[j]*A[j+1]));
		if(j==(n-1)) {
			C[j] = ((A[n-1]*B[0])-(B[n-1]*A[0]));
			C[n-1] = ((A[0]*B[1])-(B[0]*A[1]));
		}
	}

	printf("\nEl producto punto es:");
	for (int i = 0; i<n; i++) {
		printf("\nC[%i]: %i", i, C[i]);
	}
}