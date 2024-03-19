#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 80

int option, palindrome_flag = 1, i, j, k, spaces, length;
char palindrome[MAX], lower_palindrome[MAX];

char to_lower_string(char string[MAX]){
	for(int i = 0; i < strlen(string); i++){
		string[i] = tolower(string[i]);
	}
	return string;
}

int main() {
	do {
		printf("\nElija una opción: ");
		printf("\n 1.- Palindromo");
		printf("\n 2.- Matrices");
		printf("\n 3.- Estructuras");
		printf("\n 4.- Salir");
		scanf("%i", &option);

		switch(option) {
			case 1:
				/* Código del palíndromo */
				
				spaces = 0;
				printf("\nIngrese el contenido de la cadena a evaluar: \n");
				getchar();
				gets(palindrome);
			
				strcpy(lower_palindrome, );
				
				//lower_palindrome = to_lower_string(palindrome);
				length = strlen(lower_palindrome);
				for(i = 0; i < length; i++) {
					if(palindrome_flag) {
						if(lower_palindrome[i] != lower_palindrome[length - 1 - i]) {
							palindrome_flag = 0;
						}
					}else{
						break;
					}
				}
				(palindrome_flag) ? printf("\nLa cadena '%s' es un palindromo.", palindrome) : printf("\nLa palabra '%s' no es un palindromo.", palindrome);
				break;
			case 2:
				/* Código del palíndromo */
				break;
			case 3:
				/* Código del palíndromo */
				break;
			default:
				break;
		}
	} while(option!=4);
}