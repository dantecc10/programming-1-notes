#include <stdio.h>

/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

int main(){
	int h, s;
	const int i = 5;
	float pt;
	
	printf("\nIngresa la cantidad de horas trabajadas: ");
	scanf("%d", &h);
	
	printf("\nIngresa el sueldo por hora: $");
	scanf("%d", &s);
	
	pt = (h * s);
	
	if(pt > 5000){
		pt = pt * 0.95;
	}
	printf("El sueldo total es: %f", pt);
}