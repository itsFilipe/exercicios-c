#include <stdio.h>

int main(){

    int valor = 0, soma = 0, contador = 0;
    float media = 0.0;

    printf("Inicio sistema de soma de valores para calcular media\n");
    printf("Caso queira parar, digite 9999\n");

    do
    {
        printf("Digite um numero: ");
        scanf("%i", &valor);

        if(valor == 9999)
        {
            printf("Loop encerrado\n");
            break;
        }

        soma += valor;

        if(valor != 9999)
        {
            contador++;
        }

    } while (1);

    if( contador > 0 )
    {
        media = (float)soma/contador;
        printf("A media e: %2.f", media);
    }
    else
    {
        printf("Nenhum valor foi informado\n");
    }

    return 0;
}