/* Programa 5 */
/* Resuelve una ecuacion de 2do grado por formula general */

#include <stdio.h>
#include <math.h>

main()
{
    int a=0,b,c,det;
    float end;
    
    printf("\nCalculadora de ecuaciones de segundo grado\n");
    while(a==0)
        {
        printf("\nDame el coeficiente del termino cuadratico: "); /* A(x^2) */
        scanf("%i",&a);
        if(a==0)
            printf("El coeficiente no puede ser 0\n");
        }
    printf("\nDame el coeficiente del termino literal: "); /* Bx */
    scanf("%i",&b);
    printf("\nDame el coeficiente del termino independiente: "); /* C */
    scanf("%i",&c);
    det=b*b-(4*a*c);
    if(det<=0)
        {
        printf("\nLa ecuacion no tiene solucion en los reales\n");
        }
    else
        {
        double raiz=sqrt(det);
        end=(-b+raiz)/(2*a);
        printf("\nx1 = %f",end);
        end=(-b-raiz)/(2*a);
        printf("\nx2 = %f\n",end);
        }
}