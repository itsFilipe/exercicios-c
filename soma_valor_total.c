#include <stdio.h>

int main(){

    int n, valor, valorTotal = 0;

    printf("Digite um numero: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Digite o %i valor: ", i+1);
        scanf("%i", &valor);
        valorTotal += valor;
    }
    
    printf("Valor total: %i", valorTotal);

    return 0;

}