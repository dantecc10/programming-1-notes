#include <stdio.h>
#define MAX 100
char opcion;
int n, dato, i, j, triangular, matriz[MAX][MAX]; // Uso la varaible triangular como una flag
main() {
	printf("Ingresa la dimensión de la matriz: ");
	scanf("%i", &n);


	printf("\nIntroduce los datos de la matriz: ");
	for(i = 0; i<n; i++) {
		for(j = 0; j < n; j++) {
			printf("\nIngresa el dato [%i][%i]: ", i, j);
			scanf("%i", &dato);
			matriz[i][j] = dato;
		}
	}

	triangular = 1;
	// Detectar matriz triangular superior (triángulo superior)
	for(i = 0; i<n; i++) {
		for (j = (n-1); j>=i; j--) {
			if((matriz[i][j]) == 0) {
				// Campo nulo -> no sería triangular
				triangular = 0;
			}
		}
	}
	// Detectar matriz triangular superior (triángulo inferior)
	for (i = (n-1); i >= 1; i--) {
		for (j = (i-1); j>=0; j--) {
			if(matriz[i][j] != 0) {
				triangular = 0;
			}
		}
	}

	// Detectar matriz triangular inferior
	if(triangular) {
		// Es triangular (superior)
		printf("\nLa matriz es triangular superior.");
	} else {
		printf("\nLa matriz no es triangular superior.");

		triangular = 1;
		// Detectar matriz triangular superior (triángulo superior)
		for(i = 0; i<n; i++) {

			for (j = 0; j<=i; j++) {
				if((matriz[i][j]) == 0) {
					// Campo nulo -> no sería triangular
					triangular = 0;
				}
			}
		}

		// Detectar matriz triangular superior (triángulo inferior)
		for (i = 0; i <= (n-2); i++) {

			for (j = (i+1); j<=(n-1); j++) {

				if(matriz[i][j] != 0) {
					triangular = 0;
				}
			}
		}

		if(triangular) {
			// Es triangular (superior)
			printf("\nLa matriz es triangular inferior.");
		} else {
			printf("\nLa matriz no es triangular inferior.");
			printf("\nLa matriz no es triangular.");
		}
	}
	printf("\n");

	for(i = 0; i<n; i++) {
		for(j = 0; j < n; j++) {
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
}