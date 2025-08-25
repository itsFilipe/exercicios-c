#include <stdio.h>
#include <math.h>

int main()
{
    int contagem[12] = {0};
    double valor;
    double dinheiro[12] = {100, 50, 20, 10, 5, 2, 1.0, 0.50, 0.25, 0.10, 0.05, 0.01};

    scanf("%lf", &valor);

    for(int i = 0 ; i < 12 ; i++)
    {
        contagem[i] = (int)(valor / dinheiro[i]);
        valor = fmod(valor, dinheiro[i]);
    }

    printf("NOTAS:\n");

    for(int i = 0; i < 6; i++)
    {
        printf("%d nota(s) de R$ %.2lf\n", contagem[i], dinheiro[i]);
    }

    printf("MOEDAS:\n");

    for(int i = 6; i < 12; i++)
    {
        printf("%d moeda(s) de R$ %.2lf\n", contagem[i], dinheiro[i]);
    }

    return 0;
}