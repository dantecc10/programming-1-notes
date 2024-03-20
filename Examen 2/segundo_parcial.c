#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINE1 "---------------------"
#define MAX 50
struct estudiantes {
	char nombre[80];
	long int matricula;
	int anios_BUAP;
	int creditos;
	int cuatri;
};
void menu() {
	printf("\n%s\n", LINE1);
	printf("1. Palindromo\n2. Matrices\n3. Estructuras\n4. Salir\n");
	printf("%s\nR: ", LINE1);
}
void leer_cadena(char *cad) {
	printf("Dame la frase: ");
	scanf("%s",cad);
}
int palindromo(char *cad) {
	int i,j,p;
	j=strlen(cad)-1;
	p=j;
	for(i=0; i<=p; i++) {
		if(toupper(cad[i])!=toupper(cad[j])) {
			return 0;
		}
		j--;
	}
	return 1;
}
void imprimir (int filas, int columnas, int matrix[MAX][MAX]) {
	for(int i=0; i<filas; i++) {
		printf("|");
		for(int j=0; j<columnas; j++) {
			printf("% i ",matrix[i][j]);
		}
		printf("|\n");
	}
}
void almacenar_matriz(int filas, int columnas, int matrix[MAX][MAX]) {
	for(int i=0; i<filas; i++) {
		for(int j=0; j<columnas; j++) {
			printf("[%i][%i] : ",i+1,j+1);
			scanf("%i",&matrix[i][j]);
		}
	}
}
void suma(int filas, int columnas, int matrix[MAX][MAX]) {
	int suma_local,suma_global=0;
	printf("Suma de cada columna: \n|");
	for(int i=0; i<columnas; i++) {
		suma_local=0;
		for(int j=0; j<filas; j++) {
			if((i + j)% 2 == 0) {
				suma_local+=matrix[j][i];
			}
		}
		printf(" %i |",suma_local);
		suma_global+=suma_local;
	}
	printf("\n\n>> La suma total es: %i <<\n",suma_global);
}
void almacenar_estudiantes(struct estudiantes c[],int *num_estudiantes) {
	int p=*num_estudiantes;
	do {
		printf("\n      #%i ",p+1);
		printf("\nNombre Completo: ");
		scanf(" %[^\n]s",c[p].nombre);
		printf("Matricula: ");
		scanf("%ld",&c[p].matricula);
		if(c[p].matricula!=0) {
			printf("Anios en la BUAP: ");
			scanf("%i",&c[p].anios_BUAP);
			printf("Numero de creditos: ");
			scanf("%i",&c[p].creditos);
			c[p].cuatri = (c[p].creditos/ c[p].anios_BUAP)/2;//para determinar el numero de creditos por cuatrimestre
		}
		p++;
	} while(c[p-1].matricula!=0 && (p < MAX));
	*num_estudiantes=p-1;
}
void imprimir_e(struct estudiantes c[],int num_estudiantes) {
	int i,bandera=1;
	printf("\n\nAlumnos que tienen pocos creditos acreditados:\n");
	for(i=0; i<num_estudiantes; i++) {
		if(c[i].cuatri<31) {
			printf("\n%s\nNombre: %s\n",LINE1,c[i].nombre);
			printf("Matricula: %ld\n",c[i].matricula);
			printf("Creditos por cuatrimestre: %i\n\n",c[i].cuatri);
			bandera=0;
		}
	}
	if(bandera) {
		printf("\nNo hay ninguno \n");
	}
}
//-----------------------
int main (void) {
	int opc,matrix[MAX][MAX]; //
	char frase[MAX];  //declaración de variables
	int fil,col,num_estudiantes; //
	//⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻⁻
	struct estudiantes lista[MAX];
	do {
		menu();
		scanf("%i",&opc);
		switch (opc) {
			case 1: //palindromos
				leer_cadena(frase);
				(palindromo(frase)) ? printf("\n¡¡ Es un palindromo !!\n") : printf("\nNO es un palindromo\n");
				break;
			case 2://matrices
				printf("Dame la dimension de la matriz: ");
				scanf("%i x %i",&fil,&col);
				if(fil<=MAX && col<=MAX) {
					almacenar_matriz(fil,col,matrix);
					printf("\n");
					imprimir(fil,col,matrix);
					printf("\n");
					suma(fil,col,matrix);
				} else {
					printf("\n❌ Medidas no permitidas");
				}
				break;
			case 3://estructuras
				num_estudiantes=0;
				almacenar_estudiantes(lista,&num_estudiantes);
				imprimir_e(lista,num_estudiantes);
				break;
			case 4:
				printf("Hasta la proxima ദ്ദി・ᴗ・)\n");
				break;
			default:
				printf("Opcion incorrecta\n");
				break;
		};
	} while(opc!=4);
}
