#include<stdio.h>
#define MAX 30

main() {
	int donarreglo[MAX];
	int n,i,may=0,men=0,igu=0,x;


	/*Tamaño de arreglo*/
	do {
		printf("Ingrese tama%co de arreglo (menor a 30)\n\n",(char)164);
		scanf("%i",&n);
		printf("\n");
	} while(n>MAX);
	
	
	
	/*Lectura de arreglo*/
		
	printf("-----------------------------------------------\n\nIngrese los elementos del arreglo\n\n");
	
	for(i=0;i<n;i++) {
		printf("Dato %i: ",(i+1));
		scanf("%i",&donarreglo[i]);
	}

	
	
	/*Numero x*/

	printf("\n-----------------------------------------------\nIngrese numero a comparar:\n\n");
	scanf("%i",&x);
	
	
	
	
	/*Comparacion de arreglo con numero*/
	
	for(i=0;i<n;i++) {
		
		if (donarreglo[i]<=x) {
			if (donarreglo[i]<x) {
				men=men+1;
			}
			else {
				igu=igu+1;
				printf("%i",igu);
			}
		}
		else {
			may=may+1;
		}	
	}

	printf("\n-----------------------------------------------\n\nNumeros mayores a %i:%i\nNumeros menores a %i:%i\nNumeros iguales a %i:%i\n",x,may,x,men,x,igu);






}