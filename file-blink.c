#include <stdio.h>
#define MAX 80

main() {
	FILE *ap_arch; // Apuntador al archivo
	char nom_arch[30], linea[MAX+1];

	printf("\nDame el nombre del archivo: ");
	gets(nom_arch);

	if ((ap_arch = fopen(nom_arch, "r")) != NULL) {
		printf("\nEl contenido del archivo es: \n");
		while(fgets(linea, MAX, ap_arch) != NULL) {
			printf("%s", linea);
		}
		fclose(ap_arch);
	} else {
		printf("\nError en el archivo.");
	}
}