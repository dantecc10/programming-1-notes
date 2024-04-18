#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 30
#define ANCHO_RECIBO 70

// Estructura para representar a un cliente
typedef struct {
    int medidor;
    int m3;
    char zona;
    char paterno[20];
    char materno[20];
    char nombre[30];
    float subtotal;
    float iva;
    float total;
} Cliente;

// Función para calcular el subtotal del cliente
float calcularSubtotal(Cliente cliente) {
    float precio_por_m3;
    switch(cliente.zona) {
        case 'A':
            precio_por_m3 = 10.0;
            break;
        case 'B':
            precio_por_m3 = 15.0;
            break;
        case 'C':
            precio_por_m3 = 20.0;
            break;
        case 'D':
            precio_por_m3 = 30.0;
            break;
        default:
            precio_por_m3 = 0.0; // Zona inválida
            break;
    }
    return cliente.m3 * precio_por_m3;
}

// Función para calcular el IVA del cliente
float calcularIVA(float subtotal) {
    return subtotal * 0.16;
}

// Función para calcular el total del cliente
float calcularTotal(float subtotal, float iva) {
    return subtotal + iva;
}

// Función para imprimir una línea de caracteres con un separador
void imprimirLineaSeparadora(char separador) {
    for(int i = 0; i < ANCHO_RECIBO; i++) {
        printf("%c", separador);
    }
    printf("\n");
}

// Función para imprimir el recibo de un cliente
void imprimirRecibo(Cliente cliente) {
    printf("| MED: %5d | ZONA: %c | CONSUMO: %5d |\n", cliente.medidor, cliente.zona, cliente.m3);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("| SUBTOTAL: %10.2f | IMPUESTO: %10.2f | TOTAL: %10.2f |\n", cliente.subtotal, cliente.iva, cliente.total);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("| TOTAL EN TEXTO: \n"); // Aquí debería ir la función para imprimir el total en texto
    printf("------------------------------------------------------------------------------------------------------------\n");
}

// Función para imprimir la lista de recibos ordenada por nombre
void imprimirRecibosPorNombre(Cliente clientes[], int num_clientes) {
    printf("Inicio de la lista de recibos ordenados por nombre:\n");
    imprimirLineaSeparadora('-');

    // Ordenar los clientes por nombre usando bubble sort
    for (int i = 0; i < num_clientes - 1; i++) {
        for (int j = 0; j < num_clientes - i - 1; j++) {
            if (strcmp(clientes[j].nombre, clientes[j+1].nombre) > 0) {
                // Intercambiar clientes
                Cliente temp = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = temp;
            }
        }
    }

    // Imprimir los recibos ordenados
    for (int i = 0; i < num_clientes; i++) {
        imprimirRecibo(clientes[i]);
        if ((i + 1) % 10 == 0 && i != num_clientes - 1) {
            printf("Pausa - Presione Enter para continuar...\n");
            getchar(); // Pausa para cada 10 recibos
        }
    }

    imprimirLineaSeparadora('-');
    printf("Fin de la lista de recibos ordenados por nombre.\n");
}

// Función para imprimir la lista de recibos ordenada por total
void imprimirRecibosPorTotal(Cliente clientes[], int num_clientes) {
    printf("Inicio de la lista de recibos ordenados por total:\n");
    imprimirLineaSeparadora('-');

    // Ordenar los clientes por total usando bubble sort
    for (int i = 0; i < num_clientes - 1; i++) {
        for (int j = 0; j < num_clientes - i - 1; j++) {
            if (clientes[j].total > clientes[j+1].total) {
                // Intercambiar clientes
                Cliente temp = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = temp;
            }
        }
    }

    // Imprimir los recibos ordenados
    for (int i = 0; i < num_clientes; i++) {
        imprimirRecibo(clientes[i]);
        if ((i + 1) % 10 == 0 && i != num_clientes - 1) {
            printf("Pausa - Presione Enter para continuar...\n");
            getchar(); // Pausa para cada 10 recibos
        }
    }

    imprimirLineaSeparadora('-');
    printf("Fin de la lista de recibos ordenados por total.\n");
}
int continuar = 1;
int main() {
    // Declarar arreglo de clientes
    Cliente clientes[MAX_CLIENTES];

    // Leer información de los clientes
    printf("Ingrese la informacion de los clientes:\n");
    for (int i = 0; i < MAX_CLIENTES; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("MEDIDOR M3 ZONA PATERNO MATERNO NOMBRE: ");
        scanf("%d %d %c %s %s %s", &clientes[i].medidor, &clientes[i].m3, &clientes[i].zona, clientes[i].paterno, clientes[i].materno, clientes[i].nombre);
        getchar(); // Limpiar el buffer del teclado

        // Calcular subtotal, IVA y total para cada cliente
        clientes[i].subtotal = calcularSubtotal(clientes[i]);
        clientes[i].iva = calcularIVA(clientes[i].subtotal);
        clientes[i].total = calcularTotal(clientes[i].subtotal, clientes[i].iva);
    
    	printf("¿Desea añadir otro registro?");
    	printf("\nSi (1)");
    	printf("\nNo (0)\n");
    	scanf("%i", &continuar);
    	if(!continuar){
    		break;
		}
		printf("\n");
    }

    // Imprimir recibos ordenados por nombre
    imprimirRecibosPorNombre(clientes, MAX_CLIENTES);

    // Imprimir resumen
    printf("\nResumen:\n");
    printf("Total de clientes: %d\n", MAX_CLIENTES);
    float suma_subtotal = 0.0, suma_iva = 0.0, suma_total = 0.0;
    for (int i = 0; i < MAX_CLIENTES; i++) {
        suma_subtotal += clientes[i].subtotal;
        suma_iva += clientes[i].iva;
        suma_total += clientes[i].total;
    }
    printf("Suma de Subtotales: %.2f\n", suma_subtotal);
    printf("Suma de IVAs: %.2f\n", suma_iva);
    printf("Suma de Totales: %.2f\n", suma_total);

    // Imprimir recibos ordenados por total
    imprimirRecibosPorTotal(clientes, MAX_CLIENTES);

    return 0;
}