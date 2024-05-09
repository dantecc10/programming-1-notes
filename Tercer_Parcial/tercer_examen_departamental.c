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
		};
		i++;
	} while((disponibilidad==0)&&(i<MAX));
	
	if (disponibilidad==1) {//Agrega jugador en espacio disponible
		i--;
		printf("\nIngrese nickname: ");
		scanf(" %[^\n]s",c[i].nickname);
		printf("Ingrese nivel: ");
		scanf("%i",&c[i].nivel);
		printf("Ingrese numero de vidas: ");
		scanf("%i",&c[i].vidas);
		c[i].bandera=1;
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

void guardar_datos(struct jugadores var[]) // Guarda el Nickname y vidas restantes
{                                          // de cada jugador en un archivo txt 
	FILE *players;
	players = fopen("PlayersData.txt", "w");
    if(players != NULL){
	    for (i=0; i<MAX; i++)
	    {
		    if (var[i].bandera != 0 && (strlen(var[i].nickname)) > 0)
			    fprintf(players, "%s - %d\n", var[i].nickname, var[i].vidas);
	    }
	    fclose(players);
    }else{
		printf("Error en el archivo\n");
	};
}

void ordenar_max_min(int cadenita[], int total,struct jugadores c[]){//ordenar el arreglo array e
    int j,respaldo;                                                  //imprimir los jugadores
    for (i = 0; i < total - 1; i++) {// Selection Sort
        for (j = i + 1; j < total; j++) {
            if (cadenita[j] > cadenita[i]) {
               respaldo = cadenita[i];
               cadenita[i] = cadenita[j];
               cadenita[j] = respaldo;
            };
        };
     };//
     
     printf("\nJugadores ordenados de mayor a menor\n\n");
     for (i=0;i<total;i++){//para recorrer el arreglo array
		 for(int p=0;p<MAX;p++){//para recorrer todo el arreglo de jugadores
			 if(c[p].bandera!=0 && c[p].nivel==cadenita[i]){
				 printf(">> %s --- %d\n",c[p].nickname,c[p].nivel);
			 };
		 };
     };
}

int duplicado(int numero, int array[MAX],int total){
	int p;
	for (p=0;p<total;p++){ //para saber si el numero ya está en el arreglo
		if(numero == array[p])
			return 0;// se encuentra
	};
	return 1;// no se encuentra
}

void mostrar_j(struct jugadores c[]){
	int array[MAX],j=1;
	array[0]=c[0].nivel;
	for (i=1;i<MAX;i++){//para ingresar las distintas vidas al arreglo array
		if(c[i].bandera == 1 && duplicado(c[i].nivel,array,j)){
			array[j]=c[i].nivel;
			j++;
		};
	};
	ordenar_max_min(array,j,c);
}
// ------------------------------------------------------------------------------------------

int main(){
	int opc,donde; //declaracion de variables
	char nickname_buscar[MAX];
	struct jugadores lista[MAX];
	FILE *jugadores_arch;
	
	jugadores_arch=fopen("Jugadores_:)","rb"); //para la recuperación de datos
	                                           
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
			    mostrar_j(lista);
				break;
			
			case 3: // Buscar jugador
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
			
			case 4: // Eliminar
			    printf("\nNickname del jugador a eliminar: ");
				scanf(" %[^\n]s",nickname_buscar);
				if(buscar_jugador(lista,nickname_buscar,&donde)){
					lista[donde].bandera=0;
					printf("\nJugador eliminado con exito ...\n");	 
				}else{
					printf("\nJugador no encontrado\n");
				};
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
