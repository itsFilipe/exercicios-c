#include <stdio.h>
#include <stdlib.h>

int main(){

    float metro, pes, polegada, tempoMetro, tempoJarda;

    printf("Digite a quantidade de metros: \n");
    scanf("%f", &metro);

    printf("Digite o tempo(em segundos) da corrida: \n");
    scanf("%f", &tempoMetro);

    //calculos
    polegada = metro * 39.37;
    pes = polegada / 12;

    tempoJarda = (tempoMetro * 91.44) / 100;

    printf("A quantidade em polegada e: %.2f\n", polegada);
    printf("A quantidade em pes e: %.2f\n", pes);
    printf("A velocidade para fazer 100 jardas e: %.2f segundos", tempoJarda);

}