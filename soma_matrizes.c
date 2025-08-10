#include <stdio.h>

void printMatriz(int matriz[2][2], int linha, int coluna);
void calcularSomaMatriz(int matriz1[2][2], int matriz2[2][2], int somaMatriz[2][2], int linha, int coluna, int *soma);

int main()
{
    int matriz1[2][2] = 
    {
        {2, 2},{2, 2}    
    };

    int matriz2[2][2] = 
    {
        {3, 3},{3, 3}
    };

    int somaMatriz[2][2];
    int soma = 0;

    printf("Matriz 1:\n");
    printMatriz(matriz1, 2, 2);

    printf("Matriz 2:\n");
    printMatriz(matriz2, 2, 2);

    printf("Soma das matrizes: \n");
    calcularSomaMatriz(matriz1, matriz2, somaMatriz, 2, 2, &soma);

    printf("\nSoma total: %d", soma);

    return 0;
}

void printMatriz(int matriz[2][2], int linha, int coluna)
{
    for (int i = 0; i < linha; i++) 
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", matriz[i][j]);
        } 
        printf("\n");
    }
    printf("\n");
}

void calcularSomaMatriz(int matriz1[2][2], int matriz2[2][2], int somaMatriz[2][2], int linha, int coluna, int *soma)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            somaMatriz[i][j] = matriz1[i][j] + matriz2[i][j];
            printf("%d ", somaMatriz[i][j]);
            *soma += somaMatriz[i][j];
        } 
    printf("\n");
    }
}