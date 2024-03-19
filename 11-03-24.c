#include <stdio.h>
#include <stdlib.h>

main(int a, char *aCad[]){
	int i;
	double dato, suma = 0.0;
	printf("\nEl tamanio del arreglo es: %d", a);
	for (i = 0; i < a; i++) {
		printf("\naCad[%i] = %s", );
	}
	if (a > 1) {
		for (i = 1; i < a; i++) {
			dato = atof(aCad[i]);
			printf("\nValor de dato: %f", dato);
			suma += dato;
		}
		printf("\nLa suma es: %f", suma);
	} else {
		printf("\nNo hay parametros de entrada.");
	}
}