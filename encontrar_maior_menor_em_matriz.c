#include <stdio.h>
#define LINHAS 2
#define COLUNAS 3

int main()
{
    int matriz[LINHAS][COLUNAS], maior, menor;

    for(int i = 0; i < LINHAS; i++)
    {
        for(int j = 0; j < COLUNAS; j++)
        {
            printf("Digite o elemento da linha %i e coluna %i: \n", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");

    for(int i = 0; i < LINHAS; i++)
    {
        for(int j = 0; j < COLUNAS; j++)
        {
            printf("%i ", matriz[i][j]);
        }

        printf("\n");
    }

    maior = matriz[0][0];
    menor = matriz[0][0];

    for(int i = 0; i < LINHAS; i++)
    {
        for(int j = 0; j < COLUNAS; j++)
        {
            if( matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }

            if( matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }

    printf("\nMaior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}