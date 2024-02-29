#include <stdio.h>
#include <string.h>

#define MAX 10

struct amigo {
	char nom[30];
	char dir[30];
	int telf;
	int edad;
};

struct amigo agenda[MAX];

main() {
	int opc, i = 0, j, band;
	char nombre[30];


	do {
		printf("\n1.- Alta de un nuevo elemento.\n2.- Mostrar agenda.\n3.- Mostrar a un 'fulanito'.\n4.- Salir.");
		printf("\nDa la opcion: ");
		scanf("%d", &opc);

		switch(opc) {
			case 1:
				altas(&i);
				break;
			case 2:
				for(int j = 0; j<i; j++) { //Mostrar agenda
					printf("\nNombre: %s", agenda[j].nom);
					printf("\nTelefono: %d", agenda[j].telf);
				}
				break;
			case 3:
				printf("\nDame el nombre a buscar: ");
				scanf("%[^n]s", nombre);
				band = 0;
				j = 0;
				while(j<i && (strcmp(nombre, agenda[j].nom)!=0)) {
					j++;
				}
				(j==i) ? printf("\nNombre no encontrado.") : printf("\nNombre: %s\nDireccion: %s\nTelefono: %d\nEdad: %d", agenda[j].nom, agenda[j].dir, agenda[j].telf, agenda[j].edad);
				break;
			case 4:
				break;
		}

	} while(opc!=4);
}

void altas(int *i) {
	if(*i<MAX) { // Agregar
		printf("\nDame el nombre: ");
		scanf("%[^n]s", agenda[*i].nom);
		//getchar();
		printf("\nDame la direccion: ");
		gets(agenda[*i].dir);
		//scanf("%[^n]s",agenda[i].dir);
		printf("\nDame el telefono: ");
		scanf("%d", &agenda[*i].telf);
		printf("\nDame su edad: ");
		scanf("%d", &agenda[*i].edad);
		(*i)++;
	} else {
		printf("\nAgenda llena");
	}
}