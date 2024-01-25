/* Programa 5 */
/* Resuelve una ecuacion de 2do grado por formula general */

#include <stdio.h>
#include <math.h>

main()
{
    int opc=2,a=0,b,c,det;
    float end;
    
    
    printf("\nCalculadora de ecuaciones de segundo grado\n------------------------------------------");
    while(opc==2) {
        while(a==0)
            {
            printf("\nTermino cuadratico:    "); /* A(x^2) */
            scanf("%i",&a);
            if(a==0)
                printf("El coeficiente no puede ser 0, ingresa otro valor\n");
            }
        printf("Termino literal:       "); /* Bx */
        scanf("%i",&b);
        printf("Termino independiente: "); /* C */
        scanf("%i",&c);
        printf("\nLa ecuacion dada proporcionada es: %ix%c",a,253);
        if(b<0) {
            printf("%ix",b);
            }
        else if(b>0) {
                printf("+%ix",b);
                }
        if(c<0) {
            printf("%i",c);
            }
        else if(c>0) {
                printf("+%i",c);
                }
        printf("\n------------------------------------------\nDesea continuar o reescribir la ecuacion?\nContinuar  = 1\nReescribir = 2\n");
        scanf("%i",&opc);
        if(opc==2)
            a=0;
        }
    det=b*b-(4*a*c);
    if(det<=0)
        {
        printf("\nLa ecuacion no tiene solucion en los reales\n");
        }
    else
        {
        double raiz=sqrt(det);
        end=(-b+raiz)/(2*a);
        printf("\nx1 = %.3f",end);
        end=(-b-raiz)/(2*a);
        printf("\nx2 = %.3f\n",end);
        }
}
