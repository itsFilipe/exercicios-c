#include <stdio.h>

int main()
{
    int numero, maiorPrimeiro, maiorSegundo;

    // Lê os dois primeiros números
    printf("Digite o 1º número: ");
    scanf("%d", &maiorPrimeiro);

    printf("Digite o 2º número: ");
    scanf("%d", &numero);

    // Inicializa maior e segundo maior corretamente
    if (numero > maiorPrimeiro)
    {
        maiorSegundo = maiorPrimeiro;
        maiorPrimeiro = numero;
    }
    else
    {
        maiorSegundo = numero;
    }

    // Agora lê os 8 restantes
    for (int i = 2; i < 10; i++)
    {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numero);

        if (numero > maiorPrimeiro)
        {
            maiorSegundo = maiorPrimeiro;
            maiorPrimeiro = numero;
        }
        else if (numero > maiorSegundo)
        {
            maiorSegundo = numero;
        }
    }

    printf("\nMaior: %d\n", maiorPrimeiro);
    printf("Segundo maior: %d\n", maiorSegundo);

    return 0;
}
