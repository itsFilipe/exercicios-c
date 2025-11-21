#include <stdio.h>

//codigo para somar valores impares entre o valor A e B

int main() {

    int a, b, soma = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a < b)
    {
        for (a + 1; a < b; a++)
        {
            if (a % 2 != 0)
            {
                soma += a;
            }
        }
    }
    else
    {
        b = b + 1;

        for (b; b < a; b++)
        {
            if (b % 2 != 0)
            {
                soma += b;
            }
        }
    }

    printf("%d\n", soma);

    return 0;
}