#include <stdlib.h>
#include <stdio.h>

int main(){

    float franco_franceses, dolares_canadenses, coroas_suecas;

    printf("Qtd dolares canadenses: \n");
    scanf("%f", &dolares_canadenses);

    coroas_suecas = dolares_canadenses * 0.242;
    franco_franceses = dolares_canadenses / 0.216;

    printf("Quantidade coroas_suecas: %f\n", coroas_suecas);
    printf("Quantidade franco_franceses: %f\n", franco_franceses);
}