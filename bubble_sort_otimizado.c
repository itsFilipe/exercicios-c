#include <stdio.h>
#include <stdbool.h> // para usar 'bool'

int main () {

    int num[10] = {10, 9, 8, 7, 5, 4, 3, 2, 1, 0};
    int n = 10;
    int hold, contador = 0;
    // Use bool ou int (1 para true, 0 para false)
    bool houve_troca = false; 

    printf("Vetor desordenado:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n\n");

    // A estrutura correta do Bubble Sort otimizado usa um loop while ou for externo
    // e a flag booleana.
    for (int i = 0; i < n - 1; i++) {
        houve_troca = false; // Redefinido para false no início de CADA passagem externa

        for(int j = 0; j < n - i - 1; j++) { // n - i - 1 para otimização de tamanho
            if(num[j] > num[j + 1]) {
                // Realiza a troca
                hold = num[j + 1];
                num[j + 1] = num[j];
                num[j] = hold;
                
                houve_troca = true; // Marca que uma troca ocorreu nesta passagem
                contador++; // Conta a operação de troca
            }
        }

        // Se nenhuma troca ocorreu nesta passagem, o vetor está ordenado
        if (houve_troca == false) {
            break; 
        }
    }
    
    printf("Qtd operacoes (trocas): %d", contador);
    printf("\n\n");

    printf("Vetor ordenado:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}