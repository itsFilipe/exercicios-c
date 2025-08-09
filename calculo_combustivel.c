#include <stdio.h>

int main()
{   
    float litros, consumoAtual, consumoGeral = 0, consumoGasolina = 0;
    int kilometragem, totalKm = 0;

    while(1)
    {
        printf("\nInforme quantos litros abasteceu (-1 para terminar): ");
        scanf("%f", &litros);
        if (litros == -1)
            break;

        printf("Informe quantos km dirigiu: ");
        scanf("%i", &kilometragem);

        consumoAtual = kilometragem / litros;

        printf("O consumo atual e de %f km/l", consumoAtual);

        consumoGasolina += litros;
        totalKm += kilometragem;
    }
    
    consumoGeral = totalKm / consumoGasolina;
    
    printf("\nO consumo geral foi de %f km/l", consumoGeral);

    return 0;
}