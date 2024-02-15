#include <stdio.h>

int main() {
	int matrices, m1, n1, m2, n2;
	// Mutiplicación de matrices
	printf("\nIntroduce los valores de m y r para la primera matriz: ");
	printf("\nm: ");
	scanf("%i", &m1);
	printf("\nn: ");
	scanf("%i", &n1);
	printf("\nIntroduce los valores de m y r para la segunda matriz:\n");
	printf("m: ");
	scanf("%i", &m2);
	printf("\nn: ");
	       scanf("%i", &n2);
	if (n1 != m2) {
	printf("\nEl producto de las matrices está indefinido.");
	} else {
		int matriz1[m1][n1];

		printf("\nIngresa las datos de la matriz 1:");
		for (int j = 0; j < n1; j++) {
			for (int i = 0; i < m1; i++) {
				printf("\nIngresa m[%i] j[%j]: ", i, j);
				scanf("%i", &matriz1[i][j]);
			}
		}


		for (int i = 0; i < m1; i++) {
			printf("\n   \n");
			for (int j = 0; j < n1; j++) {
				// cout<<"Dato ["<<i<<"]["<<j<<"]: "<<matriz1[i][j]<<endl;
				printf("%i   ", matriz1[i][j]);
			}
			printf("\n   \n");
		}

		int matriz2[m2][n2];

		printf("\nIngresa las datos de la matriz 2:");
		for (int j = 0; j < n2; j++) {
			for (int i = 0; i < m2; i++) {
				printf("\nIngresa m%ij%j: ", i, j);
				scanf("%i", &matriz2[i][j]);
			}
		}


		for (int i = 0; i < m2; i++) {
			printf("\n   \n");
			for (int j = 0; j < n2; j++) {
				// cout<<"Dato ["<<i<<"]["<<j<<"]: "<<matriz1[i][j]<<endl;
				printf("%i   ", matriz2[i][j]);
			}
			printf("\n   \n");
		}

		int matriz3[m1][n2];
		int valor;
		// Código para calcular las direcciones de matriz 3
		for (int a = 0; a < m1; a++) {
			// Iterador a
			// Aquí se harán los cálculos para los datos de m iterado (empieza en m: a = 0)
			for (int b = 0; b < n2; b++) {
				// Iterador b
				// Aquí se harán los cálculos para los datos de m iterado (empieza en n: b = 0)
				int acumulador = 0;
				for (int c = 0; c < m1; c++) {
					// Iterador c
					// Aquí se harán los cálculos para los datos de m iterado (empieza en l: c = 0)
					int sumador = 0;
					sumador = ((matriz1[a][c]) * (matriz2[c][b]));
					acumulador = (acumulador + sumador);
					sumador = 0;
				}
				matriz3[a][b] = acumulador;
				acumulador = 0;
			}
		}


		for (int i = 0; i < m1; i++) {
			printf("\n   \n");
			for (int j = 0; j < n2; j++) {
			// cout<<"Dato ["<<i<<"]["<<j<<"]: "<<matriz1[i][j]<<endl;
			printf("%i   ", matriz3[i][j]);
			}
			printf("\n");
		}
	}
}