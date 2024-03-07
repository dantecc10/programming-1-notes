#include<stdio.h>
#define TAM 10
//struct
struct moribundos {
	char nombre;
	char enfermedad;
	int edad;
	int peso;
	int estatura;
	int estatus;
};
struct moribundos bdatos[TAM];


//Funciones
void menu () {
	printf("--------------------------------\n1-Alta\n2-Consulta\n3-Modificaciones\n4-Salir\n--------------------------------\n");
}

int statusval (struct moribundos a[],int *i) {
	int j=0,bandera=0;
	do {
		if((a[j].estatus)!=1) {
			bandera=1;
			return 1;	
		}
		else {
			j++;
		}
	}while (j<TAM);
	return 0;
}



void alta (struct moribundos a[]) {
	int i;
	if (statusval(a[10],&i)==1) {
		printf("\n--------------------------------\nNombre:");
		scanf("%c",&a[i]->nombre);
		printf("\n--------------------------------\nEnfermedad:");
		scanf("%c",&a[i]->enfermedad);
		printf("\n--------------------------------\nEdad:");
		scanf("%i",&a[i]->edad);
		printf("\n--------------------------------\nPeso:");
		scanf("%i",&a[i]->peso);
		printf("\n--------------------------------\nEstatura:");
		scanf("%i",&a[i]->estatura);
	}
	else {
		printf("Cupo lleno");
	}
}





//Main
main () {
int opc;
	do {
		menu ();
		scanf("%i",&opc);
		
		switch (opc) {
			case 1: alta (bdatos);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				printf("Adiou");
				break;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	} while (opc!=4);
	
	
	
	
	
	
	
	
	
	
}
