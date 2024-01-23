#include <stdio.h>

int main() {
	float l, p;
	int option;
	const float pi = 3.1416;

	printf("Elija la figura: \n1.- Circulo\n2.- Cuadrado\n3.- Pentagono\n4.- Hexagono\n5.- Salir\nOpcion = ");
	scanf("%d", &option);

	(option == 1) ? printf("\nIntroduzca el valor del diametro: ") : printf("\nIntroduzca el valor del lado: ");
	scanf("%f", &l);

	switch(option) {
		case 1:
			p = l*pi;
			break;
		case 2:
			p = l*4;
			break;
		case 3:
			p = l*5;
			break;
		case 4:
			p = l*6;
			break;
		default:
			printf("\n¡Hasta pronto!");
	}
	printf("\nEl perimetro de la figura es: %f", p);
}