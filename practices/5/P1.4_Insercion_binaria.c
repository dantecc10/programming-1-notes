/*
    Problema 1,4
    Programar insecion binaria para ordenar un arreglo
*/

#include <stdio.h>

#define MAX 100

int main ()
{   
    int i, x, L, R, m, n, j, y, arr[MAX];

    printf ("\n Tamano del arreglo: ");
    scanf ("%d",&n);
    printf ("\n Leamos el arreglo:\n");

    for (y=0; y<n; y++) {
        printf (" Valor %d: ",y+1);
        scanf ("%d",&arr[y]);
    }

    /* Ordenamiento */
    for (i=2; i<n; i++) {
        x= arr[i];
        L= 1;
        R= i;

        while (L<R) {
            m= (L+R)/(2);
            if (arr[m] <= x)
                L= m+1;
            else
                R= m;
        }

        for (j=i; j<R+1; j--) {
            arr[j]= arr[j-1];
        }

        arr[R]= x;
    }

    printf ("\n El arreglo ordenado es: ");

    for (y=0; y<n; y++)
        printf ("%d, ",arr[y]);

    return 0;
}