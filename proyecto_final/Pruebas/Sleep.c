#include <stdio.h>
#include <windows.h>

int main()
{
    int num=1;

    do {
        printf("\nDame un numero: ");
        scanf("%d", &num);
        printf("\nEl numero que has dado es el \"%d\"\n", num);
        printf("Reiniciando...\n");
        Sleep(1000); // 1 segundo de espera
    } while (num != 0);

    return 0;
}
