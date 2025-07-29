#include <stdio.h>

int main(){

    int valor = 0, soma = 0, contador = 0;
    float media;

    while(1)
    {
        printf("Digite um numero: ");
        scanf("%i", &valor);
        if(valor == 9999){
            printf("Loop encerrado");
            break;
        }
        soma += valor;
        contador++;
    }

    media = (float)soma/contador;

    printf("A media e: %f", media);
    
    return 0;

}