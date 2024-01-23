/* Programa 6 */
/* Verifica si un numero es par o impar  */

#include <stdio.h>

main()
{
    int a,b;

    printf("\nVerificacion de pares e impares\n");
    printf("\nIngresa un numero: ");
    scanf("%i",&a);
    b=a;
    b%=2;
    if(b==0)
        {
        printf("El numero %i es par\n",a);
        }
    else
        {
        printf("El numero %i es impar\n",a);
        }
}