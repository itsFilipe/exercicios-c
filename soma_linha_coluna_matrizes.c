#include <stdio.h>

void printMatriz(int matriz[2][2], int linha, int coluna);
void somaLinha(int matriz[2][2], int matrizLinha[2], int linha, int coluna);
void somaColuna(int matriz[2][2], int matrizColuna[2], int linha, int coluna);
void printResultados(int matrizLinha[2], int matrizColuna[2], int tamanho);

int main()
{
    int matriz[2][2] = 
    {
        {1, 2},{3, 4}    
    };

    int matrizLinha[2] = {0}, matrizColuna[2] = {0};

    printMatriz(matriz, 2, 2);
    somaLinha(matriz, matrizLinha, 2, 2);
    somaColuna(matriz, matrizColuna, 2, 2);
    printResultados(matrizLinha, matrizColuna, 2);

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

void somaLinha(int matriz[2][2], int matrizLinha[2], int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matrizLinha[i] += matriz[i][j];
        }
    }
}

void somaColuna(int matriz[2][2], int matrizColuna[2], int linha, int coluna)
{
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            matrizColuna[i] += matriz[j][i];
        }
    }
}

void printResultados(int matrizLinha[2], int matrizColuna[2], int tamanho)
{
     for (int i = 0; i < tamanho; i++)
    {
        printf("Soma linha %2.d: %d\n", i + 1, matrizLinha[i]);
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("Soma coluna %d: %d\n", i + 1, matrizColuna[i]);
    }
}