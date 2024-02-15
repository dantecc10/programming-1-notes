#include <stdio.h>

#define MAX 255
int main() {
	int l1 = 0, l2 = 0, pos;
	char string1[MAX], string2[MAX];
	printf("\nIngresa la primera cadena: ");
	gets(string1);

	printf("\nIngresa la segunda cadena: ");
	gets(string2);

	while(string1[l1]!='\0') {
		l1++;
	}
	while(string2[l2]!='\0') {
		l2++;
	}


	for(int i = 0; i<l1; i++) {
		if(string1[i] == string2[0]) {
			pos = i;
			for(int j = i; j<(i+l2); j++) {
				if(string2[j-pos] != string1[j]) {
					pos=-1;
					break;
				}
			}
		}
	}
	(pos != (-1)) ? printf("\nLa cadena '%s' se encontro en la cadena '%s' en la posición %i", string2, string1, pos) : printf("\nLa cadena '%s' no se encontro en la cadena '%s'.", string2, string1);
}