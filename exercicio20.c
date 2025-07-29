#include <stdio.h>

int main()
{
    int numeroConta;
    float LimiteCreditoAnterior, SaldoAtual, LimiteCreditoAtual;

    for (int i = 0; i < 3; i++)
    {
        printf("Cliente %d - numero da conta: ", i+1);
        scanf("%i", &numeroConta);

        printf("Cliente %d - Limite credito anterior: ", i+1);
        scanf("%f", &LimiteCreditoAnterior);

        printf("Cliente %d - Saldo Atual: ", i+1);
        scanf("%f", &SaldoAtual);

        //logica

        LimiteCreditoAtual = LimiteCreditoAnterior/2;

        printf("\nCliente %i - Seu novo credito e: %.2f", i+1, LimiteCreditoAtual);

        if(SaldoAtual > LimiteCreditoAtual)
            printf("\nSeu saldo excede o seu limite de credito atual\n");
    }

    return 0;

}