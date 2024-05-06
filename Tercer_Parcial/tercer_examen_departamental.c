#include <stdio.h>
#include <string.h>
#define MAX 20

int i; //variable global

struct jugadores{
	char nickname[MAX];
	int nivel;
	int vidas;
	int bandera;
};

void menu(){
	printf("\n------------ MENU ------------\n");
	printf("1. Altas\n2. Mostrar jugadores en orden\n3. Buscar un jugador\n");
	printf("4. Eliminar un jugador\n5. Salir\n\nR: ");
}

int buscar_jugador(struct jugadores c[], char nickname_buscar[MAX],int *donde){
	for (i=0;i<MAX;i++){
		if (c[i].bandera!=0 && (strcmp(c[i].nickname,nickname_buscar))==0){
			*donde=i;  //posicion donde se encuentra el jugador buscado
			return 1;  //se encuentra 
		};
	};
	return 0;   //no  se encuentra
}

//------------------
int main(){
	int opc,donde; //declaracion de variables
	char nickname_buscar[MAX];
	jugadores lista[MAX];
	
	for(i=0;i<MAX;i++){
	    lista[i].bandera=0; // se inicializan todas las bandera en 0, 
        };                      //indicando que todas las posiciones están desocupadas

	do{
		menu();
		scanf("%i",&opc);
		switch(opc){
			case 1: break;
		
			case 2: break;
			
			case 3://buscar jugador
			     printf("\nNickname del jugador: ");
			     scanf(" %[^\n]s",nickname_buscar);
			     if(buscar_jugador(lista,nickname_buscar,&donde)){
					 printf("\nEncontrado!\n\n");
					 printf("Nickname: %s \n",lista[donde].nickname);
					 printf("Nivel: %i\n",lista[donde].nivel);
					 printf("Vidas: %i\n",lista[donde].vidas);
					 
				 }else{
				     printf("\nJugador no encontrado\n");
				 };
			     break;
			
			case 4: break;
			
			case 5: break;
			
			default:
			     printf("Opcion invalida\n"); break;
		};
			
	}while(opc!=5);
}
