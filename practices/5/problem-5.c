#include <stdio.h>

int main() {
	int n, k, x;

	printf("\nIngresa la cantidad de numeros: ");
	scanf("%i", &n);

	int a[n];

	for(int i = 0; i<n; i++) {
		printf("\nIngrese el dato %i:", (i+1));
		scanf("%i", &a[i]);
	}

	for(int i = 0; i<n; i++) {
		k = i;
		x = a[i];
		for(int j = i+1; j<n; j++) {
			if(a[j] < x) {
				k = j;
				x = a[k];
			}
		}
		a[k] = a[i];
		a[i] = x;
	}

	printf("\nEl arreglo ordenado es:");
	for(int i = 0; i<n; i++) {
		printf("\n%i: %i", (i+1), (a[i]));
	}
}