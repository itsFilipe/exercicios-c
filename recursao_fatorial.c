#include <stdio.h>

 int fatorial(int x);

int main(void)
{
    int valor, resultado;

    printf("Digite um valor: \n");
    scanf("%d", &valor);

    resultado = fatorial(valor);

    printf("O fatorial e %d", resultado);

    return 0;
}

 int fatorial(int x)
 {
    int resultado;

    if (x==0)
    {
        resultado = 1;
    }
    else
    {
        resultado = x * fatorial(x - 1);
    }

    return resultado;
 }
