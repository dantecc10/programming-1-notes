#include <stdio.h>

/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

int main() {
	int r = 0;
	float cal, contador= 0;

	for (int i = 0; i<3; i++) {
		printf("\nIngrese la calificacion de la materia %d: ", (i+1));
		scanf("%f", &cal);
		contador+=cal;
		if(cal<6) {
			r++;
		}
	}

	if(r == 0) {
		printf("\nUsted ha aprobado todas sus materias. ¡Felicidades!");
	} else if(r == 3) {
		printf("\nUsted ha reprobado todas sus materias. Debe presentar examen extraordinario.");
	} else {
		printf("\nUsted ha reprobado %d materia(s). Debe presentar examen ordinario.", r);
	}
	printf("\nSu promedio es: %.2f", (contador/3));
}
