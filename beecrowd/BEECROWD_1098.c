#include <stdio.h>

int main() {
    // Loop externo controla o 'i'.
    // Usamos um contador inteiro 'k' de 0 a 20, passo 2, para evitar erros de precisão.
    for (int k = 0; k <= 20; k += 2) {
        
        // Calculamos o valor real de i
        float i = k / 10.0;
        
        // Loop interno controla o 'j'. São sempre 3 passos (1, 2, 3) somados a 'i'.
        for (int l = 1; l <= 3; l++) {
            float j = l + i;

            // Lógica de formatação:
            // Se 'k' for divisível por 10 (0, 10, 20), significa que 'i' é inteiro (0, 1, 2).
            // Caso contrário, é decimal.
            if (k % 10 == 0) {
                printf("I=%.0f J=%.0f\n", i, j);
            } else {
                printf("I=%.1f J=%.1f\n", i, j);
            }
        }
    }

    return 0;
}