#include <stdio.h>

int main()
{
    int Crescimento = 0, populacao = 100;
    int ano2x = -1;

    printf("Ano\tPopulacao\tCrescimento\n");

    for (int ano = 1; ano <= 75; ano++)
    {
        printf("%i\t%i\t%10.i\n", ano, populacao, Crescimento);
        Crescimento = (populacao * 1.1) - populacao;
        populacao += Crescimento;

        if (populacao >= 200 && ano2x == -1)
        {
            ano2x = ano;
        }   
    }
    
    printf("A populacao dobrara em %i anos", ano2x);

    return 0;
}