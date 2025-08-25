#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaração do ponteiro para o início do array
    int *array_dinamico;
    int tamanho;

    // 1. Obter o tamanho do array do usuário
    printf("Quantos elementos voce quer no array? ");
    scanf("%d", &tamanho);

    // 2. Alocação de memória para o array
    // 'tamanho * sizeof(int)' calcula o total de bytes necessários
    // para armazenar 'tamanho' inteiros.
    array_dinamico = (int *)malloc(tamanho * sizeof(int));

    // Verificação de erro
    if (array_dinamico == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    // 3. Preenchimento e impressão dos valores
    printf("Preenchendo e exibindo os valores do array:\n");
    for (int i = 0; i < tamanho; i++) {
        // Atribuindo um valor simples (índice + 1)
        array_dinamico[i] = i + 1;
        printf("Elemento %d: %d\n", i, array_dinamico[i]);
    }

    // 4. Liberação da memória
    printf("\nLiberando a memoria alocada...\n");
    free(array_dinamico);
    array_dinamico = NULL; // Evitar "ponteiros pendentes"

    return 0;
}