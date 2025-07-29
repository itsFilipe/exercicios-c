#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(){

    char nomeProduto[20];
    float precoAtual, precoMesAnterior, diferAlgeb, porcentagem, taxapercento;

    printf("Digite o nome do produto: \n");
    gets(nomeProduto);

    printf("Digite o preco atual: \n");
    scanf("%f", &precoAtual);

    printf("Digite o preco do mes anterior: \n");
    scanf("%f", &precoMesAnterior);

    diferAlgeb = precoAtual - precoMesAnterior;
    porcentagem = precoAtual / precoMesAnterior;
    taxapercento = porcentagem * 100;

    printf("Nome do produto: %2.s\n", nomeProduto);
    printf("Preco atual: %2.f\n", precoAtual);
    printf("Preco mes anterior: %2.f\n", precoMesAnterior);

    if(porcentagem > 1)
        printf("O preco do produto aumentou %2.f reais, taxa percentual: %.0f ", diferAlgeb, taxapercento);
    else
        printf("O preco do produto perdeu %2.f reais, taxa percentual: %0.f ", diferAlgeb, taxapercento);

    getch();
    return 0;

}