/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

#include <stdio.h>

// División por resta sucesiva

int main() {
	float a, b, cociente = 0;

	printf("\nProporciona el valor de a: ");
	scanf("%f", &a);
	const float pa = a;

	printf("\nProporciona el valor de b: ");
	scanf("%f", &b);
	const float pb = b;

	if(a > 0 && b > 0) {
		while((a-b) >= 0) {
			cociente++;
			a-=b;
		}
		printf("\nEl resultado dividir %.2f entre %.2f por resta sucesiva es: %.4f", pa, pb, cociente);
	} else {
		printf("\nSi me da mas tiempo, le hago la division con numeros negativos, positivos y mixtos...");
	}
}