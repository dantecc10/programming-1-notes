#include <stdio.h>
#include <string.h>
#define MAX 20

// Variables globales
int i;

struct jugadores{
	char nickname[MAX];
	int nivel;
	int vidas;
	int bandera;
};

void menu() {
	printf("\n------------ MENU ------------\n");
	printf("1. Altas\n2. Mostrar jugadores en orden\n3. Buscar un jugador\n");
	printf("4. Eliminar un jugador\n5. Salir\n\nR: ");
}


void alta_jugador(struct jugadores c[]){
	int disponibilidad=0;
	i=0;
	do { //Checa espacio disponible en estructura
		if(c[i].bandera==0){
			disponibilidad=1;
		}
		i++;
	} while((disponibilidad==0)&&(i<MAX));
	
	if (disponibilidad==1) {//Agrega jugador en espacio disponible
		i--;
		printf("Ingrese nickname: ");
		scanf("%s",&c[i].nickname);
		printf("Ingrese nivel: ");
		scanf("%i",&c[i].nivel);
		printf("Ingrese numero de vidas: ");
		scanf("%i",&c[i].vidas);
	}
	else {
		printf("No hay espacio disponible");
	}
}







int buscar_jugador(struct jugadores c[], char nickname_buscar[MAX],int *donde){
	for (i=0;i<MAX;i++){
		if (c[i].bandera!=0 && (strcmp(c[i].nickname,nickname_buscar))==0) {
			*donde=i;  //posicion donde se encuentra el jugador buscado
			return 1;  //se encuentra 
		}
	}
	return 0; //no  se encuentra
}

void guardar_datos(struct jugadores var[]) // Guarda el Nickname y vidas restantes de cada jugador en un archivo txt 
{
	FILE *players;
	players = fopen("PlayersData.txt", "w");

	for (i=0; i<MAX; i++)
	{
		if (var[i].bandera != 0 && (strlen(var[i].nickname)) > 0)
			fprintf(players, "%c - %d\n", var[i].nickname, var[i].vidas);
	}
	fclose(players);
}

// ----------------------------------------------------------------------------------------------------

int main(){
	int opc,donde; //declaracion de variables
	char nickname_buscar[MAX];
	struct jugadores lista[MAX];
	FILE *jugadores_arch;
	
	jugadores_arch=fopen("Jugadores_:)","rb"); //para la recuperación de datos en el archivo binario
	
	if(jugadores_arch != NULL){ //existe el archivo binario
		fread(lista, sizeof(struct jugadores), MAX, jugadores_arch);
                fclose(jugadores_arch);
	}else{ // no  existe el archivo binario
		for (i=0;i<MAX;i++) {
		    lista[i].bandera=0; // se inicializan todas las bandera en 0, 
		};                      //indicando que todas las posiciones están desocupadas
	}; 
	
	do{
		menu();
		scanf("%i",&opc);
		switch(opc){
			case 1: // Alta
				alta_jugador(lista);
				break;
		  
			case 2: // Mostrar
				break;
			
			case 3: // Buscar jugador
				printf("\nNickname del jugador: ");
				scanf("%[^\n]s",nickname_buscar);
				if(buscar_jugador(lista,nickname_buscar,&donde)){
					printf("\nEncontrado!\n\n");
					printf("Nickname: %s \n",lista[donde].nickname);
					printf("Nivel: %i\n",lista[donde].nivel);
					printf("Vidas: %i\n",lista[donde].vidas);	 
				}else{
					printf("\nJugador no encontrado\n");
				};
				break;
			
			case 4: // Eliminar
				break;
			
			case 5: // Salir
				printf("\nSaliendo...");
				break;
			
			default:
				printf("Opcion invalida\n");
				break;
		};
			
	} while(opc!=5);
	
	// Para guardar los datos en el archivo binario
	jugadores_arch = fopen("Jugadores_:)", "wb"); 
	fwrite(lista, sizeof(struct jugadores), MAX, jugadores_arch); //se escribe en el archivo binario
	fclose(jugadores_arch);

	// Para guardar en el archivo de texto
	guardar_datos(lista);
}

