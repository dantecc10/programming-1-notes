#include <stdio.h>
#define MAX 100

void readMatrix(int a, int b, int matrix[MAX][MAX]) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
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

void matrixProduct(int a1, int b1, int a2, int b2, int matriz1[MAX][MAX], int matriz2[MAX][MAX], int matriz3[MAX][MAX]) {
	int acumulador = 0;
	for(int a = 0; a < a1; a++) {
		for(int b = 0; b < b2; b++) {
			acumulador = 0;
			for(int c = 0; c < a1; b++) {
				acumulador += ((matriz1[a][c]) * (matriz2[c][b]));
			}
			matriz3[a][b] = acumulador;
		}
	}
}

int main() {
	int m1, n1, m2, n2, matriz1[MAX][MAX], matriz2[MAX][MAX], matriz3[MAX][MAX];

	// Lectura dimensiones
	printf("\nIntroduce las dimensiones de la primera matriz: ");
	printf("\nFilas: ");
	scanf("%i", &m1);
	printf("Columnas: ");
	scanf("%i", &n1);
	printf("\nIntroduce las dimensiones de la segunda matriz: ");
	printf("\nFilas: ");
	scanf("%i", &m2);
	printf("Columnas: ");
	scanf("%i", &n2);

	if(m1 == n2) {
		printf("\nIngrese los datos de la primera matriz: \n");
		readMatrix(m1, n1, matriz1);
		printf("\n");
		displayMatrix(m1, n1, matriz1);

		printf("\nIngrese los datos de la segunda matriz: \n");
		readMatrix(m2, n2, matriz2);
		printf("\n");
		displayMatrix(m2, n2, matriz2);

		printf("\nEl producto de las matrices es: \n");
		matrixProduct(m1, n1, m2, n2, matriz1, matriz2, matriz3);
		displayMatrix(m1, n2, matriz3);
	} else {
		printf("\nEl producto de las matrices está indefinido.");
	}

}