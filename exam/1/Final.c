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

    4. Escribir un programa que lea dos cadenas de caracteres, las compare e infor me de si son iguales o diferentes.
       No usar la función de la biblioteca estándar strcmp().

    5. Salir del programa (Hasta que no se solicite repetir constantemente)
*/

#include <stdio.h>

#define LINE1 "   **************************"
#define LINE2 "--------------------------------"

int main()
{
    int opc, valid, last; // Variables de menu y vadilacion

    do
    {
        printf("\n%s", LINE1);
        printf("\n   * 1.   Temperatura       *");
        printf("\n   * 2.   Multiplos         *");
        printf("\n   * 3.   Arreglos          *");
        printf("\n   * 4.   Cadenas           *");
        printf("\n   * 5.   Salir             *");
        printf("\n%s", LINE1);

        do
        { // Ciclo que valida la entrada
            printf("\n Opcion: ");
            valid = scanf("%d", &opc);

            if ((last = getchar()) != '\n')
            { // Si se ingresa una caracter
                while (getchar() != '\n')
                {
                }
                valid = 0;
            }

            if (valid == 0)
                printf("\n Los caracteres no son aceptados\n");

        } while (valid == 0);

        if (opc >= 1 && opc <= 5) // Solo imprime si la opcion es valida
            printf("%s\n", LINE2);

        switch (opc)
        { // Opciones
        case 1:
            float temp;

            do
            { // Ciclo que valida la entrada
                printf("\n Temperatura del sujeto: ");
                valid = scanf("%f", &temp);

                if ((last = getchar()) != '\n')
                {
                    while (getchar() != '\n')
                    {
                    }
                    valid = 0;
                }

                if (valid == 0)
                    printf("\n Los caracteres no son aceptados\n");

            } while (valid == 0);

            if (temp < 35.0)
                printf("\n El sujeto tiene hipotermia\n");
            else if (temp <= 37.0)
                printf("\n La temperatura es normal\n");
            else
                printf("\n El sujeto tiene hipertermia\n");

            break;

        case 2:

            int dccn, dcclim, dccacumulador, dcci;
            dccacumulador=0;
            dcci=0;

            printf("\nIntroduce un número: ");
            scanf("%i", &dccn);
            printf("\nIndica un límite: ");
            scanf("%i", &dcclim);
            while ((dccn * dcci) <= dcclim)
            {
                dccacumulador += dccn * dcci;
                dcci++;
            }

            printf("\nLa suma de los multiplos de %i hasta el numero %i es %i.", dccn, dcclim, dccacumulador);
            break;

        case 3:
            int cont, cal, califs[100], j, respaldo;

            cont = 1;
            j = 0;
            printf("\n Ingrese las calificaciones\n");
            printf(" 1. ");
            scanf("%i", &cal);
            while (cal > 500 && cont < 100)
            {
                califs[cont - 1] = cal; // Para almacenar las calificaciones en el arreglo
                printf(" %i. ", cont + 1);
                scanf("%i", &cal);
                cont++;
            };

            // Bubblesort
            for (int i = 1; i <= cont - 1; i++)
            {
                for (int p = 0; p <= j; p++)
                {
                    if (califs[p] > califs[j])
                    {
                        respaldo = califs[j];
                        califs[j] = califs[p];
                        califs[p] = respaldo;
                    };
                };
                j++;
            }; //----------------------
            if (cont - 1 != 0)
            {
                printf("\n Arreglo ordenado\n%s\n", LINE2);
                for (int i = 0; i < cont - 1; i++)
                {
                    printf(" %i\n", califs[i]);
                };
                printf("\n La menor calificacion es: %i\n", califs[0]);
                printf(" La mayor calificacion es: %i\n", califs[cont - 2]);
            }
            else
            {
                printf("No ingresaste ninguna calificación valida\n");
            };
            break;

        case 4:
            int n, i, bandera;
            char cad1[32], cad2[32];

            // Lectura y comprobacion de tamaño de las cadenas
            do
            {
                printf("\n Ingrese primera cadena\n ");
                scanf("%s", cad1);
                while (getchar() != '\n')
                {
                }
                i = 0;
                n = 0;
                while (cad1[i] != '\0')
                {
                    i = i + 1;
                    n = n + 1;
                }
                if (i > 32 || i < 1)
                {
                    printf("\a\n *Tama%co invalido*\n", (char)164);
                }
            } while (i > 32);

            printf("\n");

            do
            {
                printf(" Ingrese segunda cadena\n ");
                scanf("%s", cad2);
                while (getchar() != '\n')
                {
                }
                i = 0;
                while (cad2[i] != '\0')
                {
                    i = i + 1;
                }
                if (i > 32 || i < 1)
                {
                    printf("\a\n *Tama%co invalido*\n", (char)164);
                }
            } while (i > 32);

            // Comparacion de las dos cadenas
            bandera = 1;
            for (i = 0; i < n; i++)
            {
                if (cad1[i] != cad2[i])
                {
                    bandera = 0;
                }
            }

            // Resultado de la comprobación
            if (bandera == 1)
            {
                printf("\n *Las cadenas son iguales*\n");
            }
            else
            {
                printf("\n *Las cadenas no son iguales*\n");
            }
            break;

        case 5:
            printf("\n Hasta luego, vuelva pronto :)\n");
            break;

        default:
            printf("\n Opcion invalida");
            break;
        }
        if (opc >= 1 && opc <= 5) // Imprime solo si la opcion era valida
            printf("\n%s\n", LINE2);

    } while (opc != 5);

    return 0;
}
