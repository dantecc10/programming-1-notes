#include <stdio.h>
#define MAX 60

struct jugadores{
	char nickname[60];
	int nivel;
	int vidas;
	int bandera;
};
void menu(){
	printf("\n------------ MENU ------------\n");
	printf("1. Altas\n2. Mostrar jugadores en orden\n3. Buscar un jugador\n");
	printf("4. Eliminar un jugador\n5. Salir\n\nR: ");
}

//------------------
int main(){
	int opc;
	jugadores lista[20];
	do{
	   menu();
           scanf("%i",&opc);
	   switch(opc){
		case 1: break;
			
		case 2: break;
			
		case 3: break;
			
		case 4: break;
			
		case 5: break;
			
		default:
		      printf("Opcion invalida\n"); break;
	  };		
	}while(opc!=5);
}
