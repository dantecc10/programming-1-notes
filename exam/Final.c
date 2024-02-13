/*
    Programa final con todo lo solicitado

    1. Temperatura: Determinará la respuesta: de hipotermia sí la temperatura de una persona es menor de 35 °C,
       de estar en el intervalo 36°C±1.0°C considérese normal, y si es mayor de 37.0 °C existe hipertermia (hay fiebre).
    
    2. Dado un número n, y un límite, sumar los números múltiplos de n, menores a límite.
       Por ejemplo: Si n=5 y límite=23, se sumarán los números 5+10+15+20=50
    
    3. Leer las calificaciones del examen de ingreso a la BUAP mientras el valor sea mayor a 500; y al terminar
       presente el arreglo ordenado y dé la calificación más alta y la más baja del conjunto de calificaciones.
       Realice la prueba de ejecución para los siguientes datos:
          758 745 698 802 783 711 822 799 815 875
          699 840 796 723 741 800 769 700 810 459
    
    4. Escribir un programa que lea dos cadenas de caracteres, las compare e informe de si son iguales o diferentes.
       No usar la función de la biblioteca estándar strcmp().

    5. Salir del programa (Hasta que no se solicite repetir constantemente)
*/

#include <stdio.h>

int main ()
{
    int opc, result;
    int cont,cal,califs[100],j,respaldo; //variables para la opción 3
    do {
        printf ("\n ---   Menu   ---");
        printf ("\n 1 -  Temperatura");
        printf ("\n 2 -    Multiplos");
        printf ("\n 3 -     Arreglos");
        printf ("\n 4 -      Cadenas");
        printf ("\n 5 -        Salir\n");

        /* Validacion de la opcion, para evitar errores */
        /* Debe mejorarse, acepta cadenas que empiezan en un número (no deberia de suceder)*/
        do {
            printf ("\n Opcion: ");
            result = scanf ("%d",&opc);
            if (result==0 || opc<1 || opc>5)  {
                printf ("\n Ingresa un numero valido, los caracteres no son aceptados\n",163);
                while (getchar() != '\n');
            }
        } while (result==0 || opc<1 || opc>5);

        /* Menu */
        switch (opc) {
            case 1:
                float temp;

                /* Validacion de una temperatura, dada en números */
                /* Debe mejorarse, acepta cadenas que empiezan en un número (no deberia de suceder)*/
                do {
                    printf ("\n Temperatura del sujeto: ");
                    result = scanf ("%f",&temp);

                    if (result==0) {
                        printf ("\n Ingresa un valor valido, sin caracteres desconocidos\n");
                        while (getchar() != '\n');
                    }
                } while (result==0);

                if (temp<35.0)
                    printf ("\n El sujeto tiene hipotermia\n");
                else if (temp<=37.0)
                    printf ("\n La temperatura es normal\n");
                else
                    printf ("\n El sujeto tiene hipertemia\n");

                break;

            case 2:
                /* Codigo */
                break;

            case 3:
                cont=1;
		j=0;
	        printf("Ingrese las calificaciones\n");
		printf("1. ");
		scanf("%i",&cal);
		while(cal>500 && cont<100){
			califs[cont-1]=cal;//para almacenar las calificaciones en el arreglo 
			printf("%i. ",cont+1);
			scanf("%i",&cal);
			cont++;
		};
		//Bubblesort
                for (int i=1;i<=cont-1;i++){
                     for (int p=0;p<=j;p++){
                           if (califs[p]>califs[j]){
                               respaldo=califs[j];
                               califs[j]=califs[p];
                               califs[p]=respaldo;
                            };
                      };
                      j++;
                };//----------------------
                if (cont-1!=0){
                      printf("\nArreglo ordenado\n---------------\n");
                      for(int i=0;i<cont-1;i++){
			  printf("%i\n",califs[i]);
		      };
		      printf("\nLa menor calificacion es: %i\n",califs[0]);
		      printf("La mayor calificacion es: %i\n",califs[cont-2]);
		};
	        break;

            case 4:
                /* Codigo */
                break;

            case 5:
                printf ("\n Hasta luego, vuelva pronto\n");
                break;

        }

    } while (opc!=5);

    return 0;
}
