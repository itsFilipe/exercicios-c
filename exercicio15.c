#include <stdio.h>

int main()
{
    int soma = 0;

    for(int i = 2 ; i<=30 ; i += 2)
    {
        soma += i;
    }

    printf("%i", soma);

    return 0;

}