// Practica 9.2
// Crear un programa que dado el nombre de un archivo:
// 1. Cuente todas las palabras en el archivo.
// 2. Cuente la cantidad de caracteres que contiene.
// 3. Cuente el número de líneas en el archivo.
// 4. Muestre cada uno de los resultados.

#include <stdio.h>
#include <string.h>

#define MAX 1000

void cleanCad(char cad[]);
int wordCount(FILE *punter);
int charCount(FILE *punter, int *spaces);
int lineCount(FILE *punter);

char line[MAX+1]; // Variable global para uso en funciones

int main()
{
    int words, chars, lines, spaces=0;
    char name[31], opc;
    FILE *imput;

    printf(" ------| Escaner de archivos |------\n\n");

    do { // Entrada del archivo
        opc = 'n';
        printf(" Archivo a escanear: ");
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

    // Funciones que realizan los calculos
    words = wordCount(imput);
    chars = charCount(imput, &spaces);
    spaces += chars;
    lines = lineCount(imput);

    // Imprime los valores
    printf("\n Cantidad de palabras: %d\n Cantidad de caracteres (sin espacios): %d\n Cantidad de caracteres (con espacios): %d\n Cantidad de lineas: %d\n", words, chars, spaces, lines);

    fclose(imput);

    return 0;
}

void cleanCad(char cad[]) // Limpia el caracter '\n' (cuestion de usar fgets)
{
    int size;

    size = strlen(cad);
    if (cad[size-1] == '\n') {
        cad[size-1] = '\0';
    }
}

int wordCount(FILE *punter)
{
    int count=0, i;

    while(fgets(line, MAX, punter)) {
        i = 0;
        if (line[0] != '\n') {
            while (line[i] != '\0') {
                if (line[i] == ' ')
                    count++;
                i++;
            }
            count++;
        }
    }
    return count;
}

int charCount(FILE *punter, int *spaces)
{
    int count=0;
    char cGet;

    rewind(punter);
    while ((cGet = fgetc(punter)) != EOF) {
        if (cGet < 33 || cGet > 126) { // Limites de los caracteres ascii reconocibles
            if (cGet == ' ')
                (*spaces)++;
            cGet = fgetc(punter);
        } if (cGet != '\n')
            count++;
    }
    return count;
}

int lineCount(FILE *punter)
{
    int count=0;

    rewind(punter);
    while(fgets(line, MAX, punter))
        count++;

    return count;
}