#include <stdio.h>
#define MAX3 3
#define NTAM3 10

struct alm {
	int matricula;
	char nombre[NTAM3];
	int years;
	int creditos;
	int estatus;
};

//Funcion que despliega una linea del tamaño de la de fin de programa (32 caracteres)
void linea () {
	int i=0;
		printf("\n");
	for (i=0;i<32;i++) {
		printf("-");
	}
	printf("\n");
}
//Funcion para desplegar menu principal
void menu () {
	int i;
	linea();
	printf("      %c",(char)218);
	for (i=0;i<16;i++) {
		printf("%c",(char)196);
	}
	printf("%c",(char)191);
	
		printf("\n      %c Menu Principal %c",(char)179,(char)179);
	printf("\n      %c",(char)179);
	for (i=0;i<16;i++) {
		printf("%c",(char)196);
	}
	printf("%c",(char)179);
	
	printf("\n      %c 1-Palindromo   %c",(char)179,(char)179);
	printf("\n      %c 2-Matrices     %c",(char)179,(char)179);
	printf("\n      %c 3-Estructuras  %c",(char)179,(char)179);
	printf("\n      %c 4-Salir        %c\n",(char)179,(char)179);
	printf("      %c",(char)192);
	for (i=0;i<16;i++) {
		printf("%c",(char)196);
	}
	printf("%c\n\n",(char)217);
}

//---PARTE3---
//---PARTE3---Menu de opciones
void menu3 () {
	int i;
	linea();
	
	printf("      %c",(char)218);
	for (i=0;i<16;i++) {
		printf("%c",(char)196);
	}
	printf("%c",(char)191);
	
	printf("\n      %c    Opcion 3    %c",(char)179,(char)179);
	printf("\n      %c",(char)179);
	for (i=0;i<16;i++) {
		printf("%c",(char)196);
	}
	printf("%c",(char)179);
	
	printf("\n      %c 1-Ingresar     %c",(char)179,(char)179);
	printf("\n      %c 2-Eliminar     %c",(char)179,(char)179);
	printf("\n      %c 3-Mostrar      %c",(char)179,(char)179);
	printf("\n      %c 4-Salir        %c\n",(char)179,(char)179);
	printf("      %c",(char)192);
	for (i=0;i<16;i++) {
		printf("%c",(char)196);
	}
	printf("%c\n\n",(char)217);
}
//---PARTE3---Limpia el arreglo
void limpiarstruct (struct alm a[]) {
	int i,j;
	for (i=0;i<MAX3;i++) {
		a[i].matricula=0;
		for(j=0;j<NTAM3;j++) {
			a[i].nombre[j]='\0';
		}
		a[i].creditos=0;
		a[i].years=0;
		a[i].estatus=0;
	}
}
//---PARTE3---Checa si hay espacio disponible en el arreglo para ingresar un nuevo alumno
int checkstruct (struct alm a[],int *i) {
	for (*i=0;*i<MAX3;(*i)++) {
		if ((a[*i].estatus)==0) {
			return 1;
		}	
	}
	return 0;
}
 //---PARTE3---Funcion que ingresa informacion de alumnos se ponga un 0 en la matricula
void ingresarstruct (struct alm a[],int *ban3,int *i) {
	printf("Matricula:");
	scanf("%i",&a[*i].matricula);
	if ((a[*i].matricula)!=0) {
		printf("Nombre:");
		scanf("%s",&a[*i].nombre);
		do {
			printf("A%cos:",(char)164);
			scanf("%i",&a[*i].years);
		} while (a[*i].years==0);
		printf("Creditos:");
		scanf("%i",&a[*i].creditos);
		a[*i].estatus=1;
		printf("\n");
	}
	else {
		printf("\nIngreso terminado");
		*ban3=1;
	}
}
//---PARTE3----Funcion que muestra en pantalla si hay algun alumno que tenga menos creditos de los que se requiere
void mostrarstruct (struct alm a[]) {
	int temp=0,i=0;
	do{
		if ((a[i].estatus)==1) {
			if ((a[i].creditos)/(a[i].years*2)<31){
				temp=1;
				linea ();
				printf("Alumnos flojos:");
			}		
		}
		i++;
	} while ((i<MAX3)&&temp!=1);
	if (temp==1) {
			for (i=i-1;i<MAX3;i++) {
				if (a[i].estatus==1) {
					if ((a[i].creditos)/(a[i].years*2)<31){
						printf("\n%s %i",a[i].nombre,a[i].matricula);
					}		
				}
			}
	}
	else {
		linea ();
		printf("Todos son alumnos responsables");
	}
}









//Programa principal
int main () {
	//Variables
	int opc,i;
	struct alm esclavos [MAX3];
	menu();
	//Limpiar estructura
	limpiarstruct (esclavos);

	//Opciones del menu principal
	do {
		scanf("%i",&opc);
		switch (opc) {
			case 1: {
				printf("\nOpcion 1\n");
				menu();
				break;
			}
			case 2: {
				printf("\nOpcion 2\n");
				menu();
				break;
			}
			case 3: {
				//---PARTE3---
				int opc3=0;
				menu3 ();
				//Menu y opciones de parte 3
				do {
					scanf ("%i",&opc3);
					switch (opc3) {
						//Opcion de ingresar
						case 1: {
							int ban3=0;
							if (checkstruct(esclavos,&i)==1) {
								linea();
							}
							do {
							if (checkstruct(esclavos,&i)==1) {
								ingresarstruct(esclavos,&ban3,&i);
							}
							else {
								linea ();
								printf("No espacio disponible");
								ban3=1;
							}
							} while (ban3!=1);
							menu3 ();
							break;
						}
						//Opcion de eliminar
						case 2: {
							limpiarstruct (esclavos);
							linea () ;
							printf("Arreglo limpio");
							menu3 ();
							break;
						}
						//Opcion de mostrar
						case 3: {
							mostrarstruct (esclavos);
							menu3 ();
							break;
						}	
					}
				} while (opc3!=4);
				
				menu();
				break;
			}
			case 4: {
				printf("Adiou");
				break;
			}
		}		
	} while (opc!=4);
}
