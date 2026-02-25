#include <stdio.h>

int main() {
    int n, x, y, temp;
    // Removemos 'soma' daqui de cima.

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);

        // Declaração e inicialização da soma para ESTE caso de teste
        int soma = 0;

        // Lógica de Troca (Swap):
        // Se X for maior que Y, trocamos os dois.
        // Assim, X será sempre o menor e Y sempre o maior.
        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }

        // Agora só precisamos de um loop, pois sabemos que X < Y (ou são iguais)
        // Começamos em x + 1 para excluir o próprio x
        for (int j = x + 1; j < y; j++) {
            if (j % 2 != 0) {
                soma += j;
            }
        }

        printf("%d\n", soma);
    }

    return 0;
}