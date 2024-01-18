/* Ejercicio 8 */

#include<stdio.h>

int main(){
int opc=1;
float guacamole;

while(opc!=5){
	
	printf("\n-----------------------------------------------\n1:Circulo\n2:Cuadrado\n3:Pentagono\n4:Hexagono\n5:Salir\n\n");
	scanf("%i",&opc);
	
	switch(opc){
		case 1:
			printf("\nIngrese valor de diametro: ");
			scanf("%f",&guacamole);
			printf("\nEl perimetro es de %f\n",guacamole*3.1416);
			break;
		case 2:
			printf("\nIngrese valor de un lado: ");
			scanf("%f",&guacamole);
			printf("\nEl perimetro es de %f\n",guacamole*4);
			break;
		case 3:
			printf("\nIngrese valor de un lado: ");
			scanf("%f",&guacamole);
			printf("\nEl perimetro es de %f\n",guacamole*5);
			break;
		case 4:
			printf("\nIngrese valor de un lado: ");
			scanf("%f",&guacamole);
			printf("\nEl perimetro es de %f\n",guacamole*6);
			break;
		default:
			if(opc!=5){
				printf("\nERROR Opcion Invalida");}
			else{
				printf("\nHasta Luego\n");}
		
		
	}

}
}
