/*
    Problema 1,4
    Programar insecion binaria para ordenar un arreglo
*/

#include <stdio.h>

#define MAX 101

int main ()
{   
    int i, value, left, right, medium, size, j, y, arr[MAX];

    printf ("\n Tamano del arreglo: ");
    scanf ("%d",&size);
    printf ("\n Leamos el arreglo:\n");

    for (y=0; y<size; y++) {
        printf (" [%d]: ",y+1);
        scanf ("%d",&arr[y]);
    }

    /* Ordenamiento */
    for (i=1; i<size; i++) {
        value = arr[i];
        left = 0;
        right = i-1;

        /* 
            Mientras el item a la izquierda sea menor o igual al de la derecha
            * Se busca la mitad
            * Si el item de la mitad del arreglo es mayor al item guardado
              se reduce la mitad en 1
            * Si el item de la mitad del arreglo es menor o igual al item
              guardado, se aumenta la mitad a 1
        */
        while (left<=right) {
            medium = (left+right)/2;
            if (arr[medium] > value)
                right = medium-1;
            else
                left = medium+1;
        }

        /* Mueve los valores a sus lugares ideales */
        for (j=i-1; j>=left; j--)
            arr[j+1] = arr[j];
        /* Asisna el valor en memoria al primer lugar disponible */
        arr[left] = value;
    }

    printf ("\n El arreglo ordenado es: ");

    for (y=0; y<size; y++)
        printf ("%d, ",arr[y]);

    return 0;
}