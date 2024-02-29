#include <stdio.h>

int main() {
	int n, temp, j;

	printf("\nIngresa la cantidad de numeros: ");
	scanf("%i", &n);

	int a[n];

	for(int i = 0; i<n; i++) {
		printf("\nIngrese el dato %i: ", (i+1));
		scanf("%i", &a[i]);
	}

	for(int i = 0; i<n; i++) {
		j=i;

		while(a[j]<a[j-1]) {
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j = j-1;
		}
	}

	printf("\nEl arreglo ordenado es:");
	for(int i = 0; i<n; i++) {
		printf("\n%i: %i", (i+1), (a[i]));
	}
}