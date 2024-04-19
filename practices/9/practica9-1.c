// Practica 9.1
// Crear un programa que copie el contenido de un archivo en otro

#include <stdio.h>
#include <string.h>

#define MAX 200

void cleanCad(char cad[31]);

int main()
{
    char name[31], line[MAX+1], opc;
    FILE *imput, *output;

    printf(" ------| Copia de archivos |------\n\n");

    do { // Entrada del archivo para copiar
        printf(" Archivo a copiar: ");
        fgets(name, 30, stdin);
        cleanCad(name);
        imput = fopen(name, "r");

        if (imput == NULL) {
            printf("\n Archivo no encontrado, reintentar? (s/n)\n");
            scanf("%c", &opc);
            while (getchar() != '\n');
            printf("\n");
            if (opc == 'n')
                return 1;
        }
    } while (opc == 's');

    // Crea el archivo copia
    printf(" Nombre de la copia: ");
    fgets(name, MAX, stdin);
    cleanCad(name);
    output = fopen(name, "w");

    // Copia el archivo, linea por linea
    while (fgets(line, MAX, imput))
        fprintf(output, "%s", line);

    // Cierra los archivos para una ejecucion optima
    fclose(imput);
    fclose(output);

    return 0;
}

void cleanCad(char cad[31]) // Limpia el caracter '\n' (cuestion de usar fgets)
{
    int size;

    size = strlen(cad);
    if (cad[size-1] == '\n') {
        cad[size-1] = '\0';
    }
}