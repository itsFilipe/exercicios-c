#include <stdio.h>

int main() {
    int quantidade, valor, menor;

    printf("Quantos numeros voce vai digitar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor);
    menor = valor;

    for (int i = 1; i < quantidade; i++) {
        printf("Digite o proximo valor: ");
        scanf("%d", &valor);
        if (valor < menor) {
            menor = valor;
        }
    }

    printf("Menor valor: %d\n", menor);

    return 0;
}
