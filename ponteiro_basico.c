#include <stdio.h>

int main()
{
    int *p;
    int valor = 5;

    p = &valor;

    printf("Valor antes ponteiro %d\n", valor);

    *p = 10;
    
    printf("Valor apos ponteiro %d\n", valor);

    return 0;
}