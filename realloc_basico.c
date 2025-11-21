/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exemplo_basico() {
    printf("=== EXEMPLO BÁSICO ===\n");
    
    // Aloca espaço para 3 inteiros
    int *array = malloc(3 * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocação inicial!\n");
        return;
    }
    
    // Preenche os 3 primeiros
    for (int i = 0; i < 3; i++) {
        array[i] = i + 1;
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    printf("Endereço original: %p\n", (void*)array);
    
    // REDIMENSIONA para 6 inteiros
    array = realloc(array, 6 * sizeof(int));
    if (array == NULL) {
        printf("Erro no realloc!\n");
        return;
    }
    
    printf("Endereço após realloc: %p\n", (void*)array);
    
    // Os dados antigos são preservados!
    printf("Dados preservados:\n");
    for (int i = 0; i < 3; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    // Preenche os novos espaços
    for (int i = 3; i < 6; i++) {
        array[i] = i + 1;
        printf("array[%d] = %d (novo)\n", i, array[i]);
    }
    
    free(array);
    printf("\n");
}

void exemplo_diminuir() {
    printf("=== DIMINUINDO TAMANHO ===\n");
    
    // Aloca para 10 inteiros
    int *array = malloc(10 * sizeof(int));
    
    for (int i = 0; i < 10; i++) {
        array[i] = i * 2;
    }
    
    printf("Array original (10 elementos):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // DIMINUI para apenas 4 inteiros
    array = realloc(array, 4 * sizeof(int));
    
    printf("Após realloc para 4 elementos:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    free(array);
    printf("\n");
}

void exemplo_casos_especiais() {
    printf("=== CASOS ESPECIAIS ===\n");
    
    int *array = malloc(5 * sizeof(int));
    
    // CASO 1: realloc com tamanho 0 = free
    printf("1. realloc com tamanho 0 (equivale a free):\n");
    array = realloc(array, 0);
    printf("array após realloc(array, 0): %p\n", (void*)array);
    
    // CASO 2: realloc com ponteiro NULL = malloc
    printf("2. realloc com ponteiro NULL (equivale a malloc):\n");
    array = realloc(NULL, 3 * sizeof(int));
    printf("array após realloc(NULL, tamanho): %p\n", (void*)array);
    
    if (array != NULL) {
        free(array);
    }
    printf("\n");
}

void exemplo_array_crescente() {
    printf("=== ARRAY QUE CRESCE DINAMICAMENTE ===\n");
    
    int capacidade = 2;
    int tamanho = 0;
    int *array = malloc(capacidade * sizeof(int));
    
    printf("Capacidade inicial: %d\n", capacidade);
    
    // Simula adição de 10 elementos
    for (int i = 1; i <= 10; i++) {
        // Se não tem mais espaço, dobra a capacidade
        if (tamanho >= capacidade) {
            capacidade *= 2;
            printf("Redimensionando de %d para %d elementos\n", capacidade/2, capacidade);
            
            array = realloc(array, capacidade * sizeof(int));
            if (array == NULL) {
                printf("Erro na realocação!\n");
                return;
            }
        }
        
        // Adiciona o elemento
        array[tamanho] = i * 10;
        tamanho++;
        
        printf("Adicionado %d. Tamanho: %d, Capacidade: %d\n", 
               array[tamanho-1], tamanho, capacidade);
    }
    
    printf("Array final:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    free(array);
    printf("\n");
}

int main() {
    printf("DEMONSTRAÇÃO COMPLETA DE realloc()\n");
    printf("=====================================\n\n");
    
    exemplo_basico();
    exemplo_diminuir();
    exemplo_casos_especiais();
    exemplo_array_crescente();
    
    return 0;
}
    */

    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int quantidade = 5;

        int *array = malloc(5 * sizeof(int));

        if (array == NULL)
        {
        printf("Erro na alocação inicial!\n");
        return 1;
        }

        printf("Endereco do inicio da memoria alocada: %p\n", array);

        for(int i = 0; i < 5; i++)
        {
            array[i] = i * 2;
            printf("[%d]->%d\t", i, array[i]);
        }

        printf("\n");

        array = realloc(array, 10 * sizeof(int)); //aumentar alocacao de memoria para 10
        
        printf("\n");

        for(int i = quantidade ; i < 10; i++)
        {
            array[i] = i * 2;
            printf("[%d]->%d\t", i, array[i]);
        }
        
        array = realloc(array, 5 * sizeof(int)); // realoca memoria para menos, e perde dados.

        printf("\nApos liberar a memoria, fica lixo de memoria nos indices que foram liberados\n");

        printf("\n");
        
        for(int i = 0 ; i < 10; i++)
        {
            printf("[%d]->%d\t", i, array[i]);
        }

        return 0;
    }