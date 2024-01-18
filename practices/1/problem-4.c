#include <stdio.h>

/*
	Código por Dante Castelán Carpinteyro (github.com/dantecc10)
*/

int main(){
	int num1, num2; 
	printf("\nEsribe un numero: ");
	scanf("%d", &num1);
	printf("\nEsribe otro numero: ");
	scanf("%d", &num2);
	
	if(num2%num1 == 0){
		printf("\nEl numero %d es multiplo del numero %d.", num2, num1);
	}else if(num1%num2 == 0){
		printf("\nEl numero %d es multiplo del numero %d.", num1, num2);
	}else{
		printf("\nLos numeros no son multiplos entre si.");
	}
}