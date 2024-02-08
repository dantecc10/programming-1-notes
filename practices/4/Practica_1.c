/*
    Problema 1
    Concatenar 2 cadenas sin usar la libreria string.h
*/

#include <stdio.h>

#define MAX 100
#define DMAX 200

int main ()
{
    int i=0, x=0;
    char cad1[MAX], cad2[MAX], cad3[DMAX];

    printf ("\n Concatenacion de cadenas");
    printf ("\n ------------------------");
    printf ("\n\n Dame una cadena: ");
    gets (cad1);
    printf ("\n Dame otra cadena: ");
    gets (cad2);

    while (cad1[i] != '\0') {
        cad3[i]= cad1[i];
        i++;
    }

    while (cad2[x] != '\0') {
        cad3[i]= cad2[x];
        i++;
        x++;
    }

    /* Limpieza de caracteres aleatorios */
    for (i; i<DMAX; i++)
        cad3[i] = '\0';

    printf ("\n La concatenacion es:\n %s\n",cad3);

    return 0;
}