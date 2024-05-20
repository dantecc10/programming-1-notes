#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h> //para usar la función sleep

#define MAX 50
#define LINE1 "-------------------------"

struct almacen
{
	long int identificador;
	char descripcion[60];
	int cantidad;
	float pcompra;
	float pventa;
	int descuento;
	int bandera;
};

void animacion_carrito()
{
	int num = 70;

	for (int i = 0; i <= 70; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			printf(" ");
		}
		num--;
		printf("🛒\n");
		printf("Cargando...\n");
		sleep(50);
		system("clear");
	}
	printf("💥\n");
}

void menu_admin()
{
	printf("\n%s\n", LINE1);
	printf("1. Dar de alta producto\n2. Dar de baja producto\n");
	printf("3. Cambios en los productos\n4. Salir\n");
	printf("%s\nR: ", LINE1);
}

void descuentos(char decidir, struct almacen a[], int num)
{
	if (decidir == 'S' || decidir == 's')
	{
		printf("Ingrese el descuento: ");
		scanf("%i", &a[num].descuento);
	}
	else
	{
		a[num].descuento = 0;
	}
}

int buscar_b(struct almacen a[], int id_buscar, int *donde)
{
	int j;

	for (j = 0; j < MAX; j++)
	{
		if ((a[j].identificador == id_buscar) && (a[j].bandera != 0))
		{
			*donde = j;
			return 1;
		}
	}
	return 0;
}

void agregar(struct almacen a[])
{
	int num = 0, donde;
	char y_n;

	while (a[num].bandera != 0 && num < MAX)
	{
		num++;
	}
	if (num != MAX)
	{
		printf("\nIdentificador: ");
		scanf("%ld", &a[num].identificador);
		while (buscar_b(a, a[num].identificador, &donde))
		{
			printf("\nIdentificador ya existente. Ingrese otro\n");
			printf("Identificador: ");
			scanf("%ld", &a[num].identificador);
		};
		printf("Descripcion: ");
		scanf(" %[^\n]s", a[num].descripcion);
		printf("Cantidad: ");
		scanf("%i", &a[num].cantidad);
		printf("Precio de Compra: ");
		scanf("%f", &a[num].pcompra);
		printf("Precio de Venta: ");
		scanf("%f", &a[num].pventa);
		printf("¿El producto tiene algun descuento?  (s / n) \nR: ");
		getchar();
		scanf("%c", &y_n);
		descuentos(y_n, a, num);
		a[num].bandera = 1;
	}
	else
	{
		printf("Espacio insuficiente\n");
	}
}

void eliminar(struct almacen a[])
{
	int donde;
	long int buscar;

	printf("\nIdentificador del producto: ");
	scanf("%ld", &buscar);
	if (buscar_b(a, buscar, &donde))
	{
		a[donde].bandera = 0;
		printf("\nEl producto fue eliminado con exito\n");
	}
	else
	{
		printf("\nIdentificador no encontrado\n");
	}
}

void cambios(struct almacen a[])
{
	long int buscar;
	int donde, opc, cantidad_nueva;

	printf("Identificador del porducto: ");
	scanf("%ld", &buscar);

	if (buscar_b(a, buscar, &donde))
	{
		printf("\n¿Que deseas modificar?\n\n1. Precio de Venta\n");
		printf("2. Precio de Compra\n3. Descuento\n4. Cantidad\nR: ");
		scanf("%i", &opc);

		switch (opc)
		{
		case 1:
			printf("\nPrecio de Venta: ");
			scanf("%f", &a[donde].pventa);
			break;

		case 2:
			printf("\nPrecio de Compra: ");
			scanf("%f", &a[donde].pcompra);
			break;

		case 3:
			printf("\nDescuento: ");
			scanf("%i", &a[donde].descuento);
			break;

		case 4:
			printf("\nCantidad de nuevo producto comprado: ");
			scanf("%i", &cantidad_nueva);
			a[donde].cantidad += cantidad_nueva;
			break;

		default:
			printf("\nOpcion invalida\n");
			break;
		}
	}
	else
	{
		printf("\nIdentificador no encontrado\n");
	}
}

void imprimir_p(struct almacen a[])
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		if (a[i].bandera != 0 && a[i].cantidad > 0)
		{
			printf("Producto: %s\n", a[i].descripcion);
			printf("Identificador: %ld\n", a[i].identificador);
			printf("Precio de venta: %.2f\n\n", a[i].pventa);
		}
	}
	printf("\n");
}

void ticket(int arreglo[], struct almacen a[], FILE *market_arch, char fecha[])
{
	int j;

	market_arch = fopen(fecha, "a");
	float descuentito, total, total_global = 0;

	fprintf(market_arch, "%s", "\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
	fprintf(market_arch, "%s", "║  Producto                  Precio      Descuento     Cantidad      Total      ║\n");
	fprintf(market_arch, "%s", "╠═══════════════════════════════════════════════════════════════════════════════╣\n");
	printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║  Producto                  Precio      Descuento     Cantidad      Total      ║\n");
	printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");

	for (j = 0; j < MAX; j++)
	{
		if (arreglo[j] != 0)
		{
			descuentito = (a[j].pventa * a[j].descuento) / 100;
			descuentito = a[j].pventa - descuentito;
			total = arreglo[j] * descuentito;
			printf("║  %-24s  $%-13.2f  %-12.2i %-8.2i   $%-10.2f║\n", a[j].descripcion, descuentito, a[j].descuento, arreglo[j], total);
			fprintf(market_arch, "║  %-24s  $%-13.2f  %-12.2i %-8.2i   $%-10.2f║\n", a[j].descripcion, descuentito, a[j].descuento, arreglo[j], total);
			total_global += total;
		}
	}

	printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
	printf("                                                                  Total: $%.2f  \n", total_global);
	fprintf(market_arch, "%s", "╚═══════════════════════════════════════════════════════════════════════════════╝\n");
	fprintf(market_arch, "                                                                  Total: $%.2f  \n", total_global);
	fclose(market_arch);
}

void comprar(struct almacen a[], char fecha[], FILE *market_arch)
{
	int cantidad_p[MAX], donde, i;
	long int buscar_e;

	for (i = 0; i < MAX; i++)
		cantidad_p[i] = 0;

	printf("Ingrese el identificador.\nPara terminar presione 0.\n\n");

	do
	{
		printf("Id: ");
		scanf("%ld", &buscar_e);

		if (buscar_e != 0 && (buscar_b(a, buscar_e, &donde)))
		{
			if (a[donde].cantidad > 0)
			{
				cantidad_p[donde]++;
				a[donde].cantidad--;
			}
			else
			{
				printf("\nNo hay más piezas disponibles de este producto\n");
			}
		}
		else
		{
			if (buscar_e != 0)
				printf("\nIdentificador no encontrado\n");
		}
	} while (buscar_e != 0);

	animacion_carrito();
	printf("\nTicket de compra\n\n");
	ticket(cantidad_p, a, market_arch, fecha);
}
//____________________
int main()
{
	time_t now;
	time(&now); // Obtener la fecha actual
	char fecha[20];
	strftime(fecha, 20, "%d_%m_%Y.txt", localtime(&now));
	// -----------------------------------------------------------------------------------
	FILE *market_arch;	// declaración de archivos, para los tickets
	FILE *almacen_arch; // para almacenar el almacén
	// -----------------------------------------------------------------------------------
	market_arch = fopen(fecha, "a"); // crear un archivo cuyo nombre
	struct almacen alma[MAX]; // es la fecha actual
	// -----------------------------------------------------------------------------------
	int opc1, opc2, i, ventas_del_dia = 0, bandera = 1, cantidad_de_productos;
	// -----------------------------------------------------------------------------------

	if (market_arch != NULL)
	{
		almacen_arch = fopen("almacen", "rb");
		if (almacen_arch != NULL)
		{
			fread(alma, sizeof(struct almacen), MAX, almacen_arch);
			fread(&cantidad_de_productos, sizeof(int), 1, almacen_arch);
			fclose(almacen_arch);
		}
		else
		{
			for (i = 0; i < MAX; i++)
			{
				alma[i].bandera = 0;
				alma[i].identificador = 0;
			};
			cantidad_de_productos = 0;
		}
		do
		{
			printf("%s\n1. Menu de administrador\n2. Menu de ventas\n3. Salir\n%s\nR:", LINE1, LINE1);
			scanf("%i", &opc1);
			switch (opc1)
			{
				case 1: // menu de administrador
					do
					{
						menu_admin();
						scanf("%i", &opc2);
						switch (opc2)
						{
							case 1:
								agregar(alma);
								cantidad_de_productos++;
								break;

							case 2:
								if (cantidad_de_productos > 0)
								{
									eliminar(alma);
									cantidad_de_productos--;
								}
								else
								{
									printf("No hay productos en almacen\n");
								}
								break;

							case 3:
								if (cantidad_de_productos > 0)
								{
									cambios(alma);
								}
								else
								{
									printf("No hay productos en almacen\n");
								}
								break;

							case 4:
								system("clear");
								break;
						};
					} while (opc2 != 4);
					break;

				case 2: // menu de ventas
					system("clear");
					if (cantidad_de_productos > 0)
					{
						imprimir_p(alma);
						ventas_del_dia++;
						comprar(alma, fecha, market_arch);
					}
					else
					{
						printf("No hay productos en almacen\n");
					};
					break;

				case 3:
					printf("\nGracias por usar el programa :D\n");
					break;

				default:
					printf("\nOpcion invalida\n");
					break;
			};
		} while (opc1 != 3);

		fclose(market_arch);
		almacen_arch = fopen("almacen", "wb");
		fwrite(alma, sizeof(struct almacen), MAX, almacen_arch);
		fwrite(&cantidad_de_productos, sizeof(int), 1, almacen_arch);
		fclose(almacen_arch);
		printf("\n\nTotal de ventas en el dia: %i\n\n", ventas_del_dia);

		if (cantidad_de_productos > 0)
		{
			printf("Productos cuya cantidad es menor a 5 :\n");
			for (i = 0; i < MAX; i++)
			{
				if (alma[i].cantidad < 5 && alma[i].bandera != 0)
				{
					printf("\n%i. Producto : %s \n", i + 1, alma[i].descripcion);
					printf("Cantidad: %i\n", alma[i].cantidad);
					printf("Identificador: %ld\n", alma[i].identificador);
					bandera = 0;
				}
			}
			if (bandera)
			{
				printf("None\n\n");
			}
		}
		else
		{
			printf("No hay productos en almacen\n");
		}
	}
	else
	{
		printf("Hubo un error :(\n");
	}

	return 0;
}
