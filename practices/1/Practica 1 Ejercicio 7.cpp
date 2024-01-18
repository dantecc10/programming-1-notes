/* Ejercicio 7 */

#include<stdio.h>

int main(){
float a,b,c;
int opc=1;

while(opc!=2){
	
	printf("\n-----------------------------------------------\n1:Correr programa\n2:Terminar programa\n\n");
	scanf("%i",&opc);
	
	if(opc==1){
		printf("\n-----------------------------------------------\n");
		printf("\nIngrese primera calificacion: ");
		scanf("%f",&a);
		printf("\nIngrese segunda calificacion: ");
		scanf("%f",&b);
		printf("\nIngrese tercera calificacion: ");
		scanf("%f",&c);
	
		if(a<=10 && a>=0 && b<=10 && b>=0 && c<=10 && c>=0){
			if(a>=6 && b>=6 && c>=6){
				printf("\nAprobado: Su calificacion es %f\n",(a+b+c)/3);}
			else{
				if(a<=6 && b<=6 && c<=6){
					printf("\nReprobado: Presentar examen extraordinario\n");}
				else{
					printf("\nPresentar examen de recuperacion\n");}}}
		else{
			printf("\nERROR Calificacion invalida\n");}
	}
	else{
		if(opc!=2){
			printf("\nERROR Opcion invalida\n");}
		else{
			printf("\nHasta Luego\n");
		}
		
	}
}
}
