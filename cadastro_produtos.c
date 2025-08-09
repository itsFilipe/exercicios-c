#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

struct Produto
    {
        char nome[50];
        float preco;
        int quantidade;
    };
    
int main()
{
    int n;
    printf("Quantos produtos deseja cadastrar? (max %d): ", MAX_PRODUTOS);
    scanf("%d", &n);
    getchar(); // limpa \n

    struct Produto produtos[MAX_PRODUTOS];

    //entrada de dados

    for(int i=0; i<n; i++)
    {
        printf("\n--- Produto %i ---\n", i + 1);

        printf("Nome: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = 0;  // remove o \n

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%i", &produtos[i].quantidade);

        getchar(); // limpa o \n após scanf
    }

    //saida de dados

    printf("\n--- Relatorio de estoque ---\n");

    for(int i=0; i<n; i++)
    {
        printf("Produto: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %i\n", produtos[i].quantidade);
        printf("Valor total em estoque: R$ %.2f\n\n", produtos[i].quantidade * produtos[i].preco);
    }

    return 0;
}