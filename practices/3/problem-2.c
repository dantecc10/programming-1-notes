#include <stdio.h>

int main() {
	int n;
	printf("\nIngrese la cantidad de valores (n): ");
	scanf("%i", &n);

	float temp[n], max = 0, min;

	printf("\nIngrese las temperaturas: ");
	for(int i = 0; i<n; i++) {
		printf("\nTemperatura %i: ", (i+1));
		scanf("%f", &temp[i]);
	}
	min = temp[n-1];

	for(int k = 0; k<n; k++) {
		(temp[k] >= max) ? (max = temp[k]) : (1);
		(temp[k] <= min) ? (min = temp[k]) : (1);
	}

	printf("\nDe las temperaturas: ");
	for(int k = 0; k<n; k++) {
		printf("\n%.2f C", temp[k]);
	}
	printf("\nLa temperatura maxima es de %.2f C.",max);
	printf("\nLa temperatura minima es de %.2f C.",min);
}