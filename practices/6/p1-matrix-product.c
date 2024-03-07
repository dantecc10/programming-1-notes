#include <stdio.h>

#define MAX 10

void readMatrix(int, int, int[MAX][MAX]);
void displayMatrix(int, int, int[MAX][MAX]);
void product(int, int, int, int[MAX][MAX], int[MAX][MAX], int[MAX][MAX]);

void readMatrix(int a, int b, int matrix[MAX][MAX]) {
	for (int j = 0; j < b; j++) {
		for (int i = 0; i < a; i++) {
			printf("M[%i][%i]: ", i+1, j+1);
			scanf("%i", &matrix[i][j]);
		}
	}
	printf("\n");
}

void displayMatrix(int a, int b, int matrix[MAX][MAX]) {
	for (int i = 0; i < a; i++) { // Imprime la matriz
		for (int j = 0; j < b; j++) {
			if (j==0)
				printf("|");
			if (j==b-1) // Casos por ubicacion del elemento
				printf(" %4i ", matrix[i][j]);
			else
				printf(" %4i ,", matrix[i][j]);
		}
		printf("|\n");
	}
}

void product(int f1, int f2, int c2, int matriz1[MAX][MAX], int matriz2[MAX][MAX], int matriz3[MAX][MAX]) {
	
	// Código para calcular las direcciones de la matriz resultante
	int a, b, c, product;

	for (a = 0; a < f1; a++) { 
		// Iteracion sobre las filas de M1
		for (b = 0; b < c2; b++) {
			// Iteracion sobre las columnas de M2
			product = 0;
			for (c = 0; c < f2; c++) {
				// Iteracion sobre el producto de filas x columnas
				product += (matriz1[a][c])*(matriz2[c][b]);
			}
			matriz3[a][b] = product; // asignacion
		}
	}
}

int main() {
	int f1, c1, f2, c2;

	// Lectura dimensiones
	printf("\nIntroduce las dimensiones de la primera matriz: ");
	printf("\nFilas: ");
	scanf("%i", &f1);
	printf("Columnas: ");
	scanf("%i", &c1);
	printf("\nIntroduce las dimensiones de la segunda matriz: ");
	printf("\nFilas: ");
	scanf("%i", &f2);
	printf("Columnas: ");
	scanf("%i", &c2);

	if (c1 != f2) { // Verifica si es posible el producto
		printf("\nEl producto de las matrices est%c indefinido.",160); // Codigo de error
		return 1;
	} else {
		int matriz1[MAX][MAX], matriz2[MAX][MAX], matriz3[MAX][MAX];

		printf("\nIngresa los datos de la matriz 1:\n");
		readMatrix(f1, c1, matriz1);
		displayMatrix(f1, c1, matriz1);

		printf("\nIngresa los datos de la matriz 2:\n");
		readMatrix(f2, c2, matriz2);
		displayMatrix(f2, c2, matriz2);

		printf("\nMatriz resultante:\n\n");
		product(f1, f2, c2, matriz1, matriz2, matriz3);
		displayMatrix(f1, c2, matriz3);
	}
	return 0;
}