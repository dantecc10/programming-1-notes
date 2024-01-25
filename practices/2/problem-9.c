/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// Contar vocales

int main(){
	int vocales = 0;
	char inchar;
	
	do{
		printf("\nIngresa un caracter: ");
		scanf("%c", &inchar);
		if(inchar == 'a' || inchar == 'A' || inchar == 'e' || inchar == 'E' || inchar == 'i' || inchar == 'I' || inchar == 'o' || inchar == 'O' || inchar == 'u' || inchar == 'U'){
			vocales++;
		}
		getchar();
	}
	while(inchar != '.');
	printf("\nHas finalizado la ejecucion del programa con un '.'. Ingresaste %i vocales.", vocales);
}