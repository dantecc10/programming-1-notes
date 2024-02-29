#include <stdio.h>
#define MAX 100
char opcion;
int dato, i, j, matriz1[MAX][MAX], matriz2[MAX][MAX], matriz3[MAX][MAX], m1, n1, m2, n2, acumulador, sumador, a, b, c, valor;

readMatrix(int a, int b, int matrix[a][b]) {
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			printf("\nIngresa m%ij%i: ", i, j);
			scanf("%i", &matrix[i][j]);
		}
	}

}

displayMatrix(int a, int b, int matrix[a][b]) {
	printf("\n");
	for (i = 0; i < a; i++) {
		printf("   ");
		for (j = 0; j < b; j++) {
			// cout<<"Dato ["<<i<<"]["<<j<<"]: "<<matriz1[i][j]<<endl;
			printf("%i   ", matrix[i][j]);
		}
		printf("\n");
	}
}

main() {
	// Mutiplicación de matrices
	printf("\nIntroduce los valores de m y r para la primera matriz: ");
	printf("\nm: ");
	scanf("%i", &m1);
	printf("\nn: ");
	scanf("%i", &n1);
	printf("\nIntroduce los valores de m y r para la segunda matriz: ");
	printf("\nm: ");
	scanf("%i", &m2);
	printf("\nn: ");
	scanf("%i", &n2);
	if (n1 != m2) {
		printf("\nEl producto de las matrices está indefinido.");
	} else {
		printf("\nIngresa las datos de la matriz 1:");
		readMatrix(m1, n1, matriz1);
		displayMatrix(m1, n1, matriz1);
		/*for (i = 0; i < m1; i++) {
			for (j = 0; j < n1; j++) {
				printf("\nIngresa m%ij%i: ", i, j);
				scanf("%i", &matriz1[i][j]);
			}
		}*/
		/*for (i = 0; i < m1; i++) {
			printf("   ");
			for (j = 0; j < n1; j++) {
				// cout<<"Dato ["<<i<<"]["<<j<<"]: "<<matriz1[i][j]<<endl;
				printf("%i   ", matriz1[i][j]);
			}
			printf("\n");
		}*/
		printf("\nIngresa las datos de la matriz 2:");
		readMatrix(m2, n2, matriz2);
		displayMatrix(m2, n2, matriz2);
		/*for (i = 0; i < m2; i++) {
			for (j = 0; j < n2; j++) {
				printf("\nIngresa m%ij%i: ", i, j);
				scanf("%i", &matriz2[i][j]);
			}
		}*/

		// Código para calcular las direcciones de matriz 3
		/*
		for (a = 0; a < m1; a++) {
			// Iterador a
			// Aquí se harán los cálculos para los datos de m iterado (empieza en m: a = 0)
			for (b = 0; b < n2; b++) {
				// Iterador b
				// Aquí se harán los cálculos para los datos de m iterado (empieza en n: b = 0)
				acumulador = 0;
				for (c = 0; c < m1; c++) {
					// Iterador c
					// Aquí se harán los cálculos para los datos de m iterado (empieza en l: c = 0)
					sumador = 0;
					sumador = ((matriz1[a][c]) * (matriz2[c][b]));
					acumulador = (acumulador + sumador);
					sumador = 0;
				}
				matriz3[a][b] = acumulador;
				acumulador = 0;
			}
		}
		*/
		
		int matriz3[m1][n2];
		
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
		
		printf("\nEl producto de las matrices es: \n");

		displayMatrix(m1, n2, matriz3);
	}
}