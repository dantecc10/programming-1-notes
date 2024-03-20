#include<stdio.h>
#include<string.h>
#define TAM 10
#define NTAM 20
#define ETAM 20
//struct principal
struct moribundos {
	char nombre [NTAM];
	char enfermedad [NTAM];
	int edad;
	float peso;
	float estatura;
	int estatus;
};
struct moribundos datos[TAM];


//Funciones----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Menu
void menu () {
	printf("--------------------------------\n1-Alta\n2-Consulta\n3-Modificaciones\n4-Salir\n--------------------------------\n");
}
 //limpiar 
void limpiar (struct moribundos *a) {
	int i=0;
	for(i=0;i<NTAM;i++) {
	a->nombre[i]='\0';
	a->enfermedad[i]='\0';
	}
	a->edad=0;
	a->peso=0;
	a->estatura=0;
	a->estatus=0;
}


int statusval (struct moribundos a[],int *i) {
	*i=0;
	do {
		if((a[*i].estatus)!=1) {
			return 1;	
		}
		else {
			(*i)++;
		}
	}while (*i<TAM);
	return 0;
}


int busqueda (struct moribundos a[],int *i) {
	char nom[NTAM];
	*i=0;
	printf ("\nEscriba nombre de paciente:");
	scanf ("%s",&nom);
	getchar();
	do {
		if (!strcmp(a[*i].nombre,nom)) {
			return 1;
		}
		else {
			(*i)++;
		}
	} while (*i<TAM);
	return 0;
}


void alta (struct moribundos a[]) {
	int i;
	if (statusval(a,&i)==1) {
		printf("\nNombre:");
		scanf("%s",&a[i].nombre);
		printf("\nEnfermedad:");
		scanf("%s",&a[i].enfermedad);
		printf("\nEdad:");
		scanf("%i",&a[i].edad);
		printf("\nPeso:");
		scanf("%f",&a[i].peso);
		printf("\nEstatura:");
		scanf("%f",&a[i].estatura);
		printf("\n");
		a[i].estatus=1;
	}
	else {
		printf("\nCupo lleno\n");
	}
}

void modificar (struct moribundos *a) {
	int tempopc=0;
	do {
		printf("\n1-Nombre\n2-Enfermedad\n3-Edad\n4-Peso\n5-Estatura\n6-Salir\n");
		scanf ("%i",&tempopc);
		switch (tempopc) {
			case 1 :{
				printf ("\nNombre:");
				scanf ("%s",&a->nombre);
				break;
			}
			case 2: {
				printf ("\nEnfermedad:");
				scanf ("%s",&a->enfermedad);
				break;
			}
			case 3: {
				printf ("\nEdad:");
				scanf ("%i",&a->edad);
				break;
			}
			case 4: {
				printf ("\nPeso:");
				scanf ("%f",&a->peso);
				break;
			}
			case 5: {
				printf ("\nEstatura:");
				scanf ("%f",&a->estatura);
				break;
			}
		}	
	}while (tempopc!=6);
	
	
}

void consulta (struct moribundos *a) {
	printf("\nNombre:%s",a->nombre);
	printf("\nEnfermedad:%s",a->enfermedad);
	printf("\nEdad:%i",a->edad);
	printf("\nPeso:%f",a->peso);
	printf("\nEstatura:%f\n",a->estatura);
}

//Main----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------https://www.youtube.com/watch?feature=shared&v=8KtyMcb86go

int main () {
int opc,i=0,tempopc;

do{
	limpiar(&datos[i]);
	i++;
} while (i<TAM);
	do {
		menu ();
		scanf("%i",&opc);
		getchar();
		
		switch (opc) {
			case 1: {
				alta (datos);
				break; 
			}
			case 2: {
			if (busqueda (datos,&i)==1) {
					consulta (&datos[i]);
				}
				else {
					printf("No existe paciente con ese nombre\n");
				}
				break;
			}

			case 3: {
					if (busqueda (datos,&i)==1) {
					printf ("\n1-Modificar\n2-Eliminar\n3-Regresar\n");
					do {
						scanf("%i",&tempopc);
						if ((tempopc!=1)&&(tempopc!=2)&&(tempopc!=3)) {
							printf("\nOpcion Ivalida\n");
						}
					} while ((tempopc!=1)&&(tempopc!=2)&&(tempopc!=3));
					if (tempopc==1){
						modificar (&datos[i]);
					}
					else {
						if (tempopc==2) {
							limpiar (&datos[i]);
						}
					}
				}
				else {
					printf("No existe paciente con ese nombre\n");
				}
				
				
				break;
			}
			case 4: {
				printf("Adiou");
				break;
			}
		}
	} while (opc!=4);
	
}

