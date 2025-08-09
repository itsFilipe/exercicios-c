#include <stdio.h>
#include <string.h>

int main() {
    float salario_base = 6000, comissao = 0;
    float abono = 0, soma = 0, salario_total = 0;
    int sentinela, quantidade_vendida;
    char nome[50];

    printf("Digite o nome do vendedor: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;  // remove o \n do final

    printf("Vendeu? SIM (1) | NAO (2): ");
    scanf("%i", &sentinela);

    if (sentinela == 1) {
        printf("Quantos carros? ");
        scanf("%d", &quantidade_vendida);

        comissao = quantidade_vendida * 500;
        float valores[quantidade_vendida];

        for (int i = 0; i < quantidade_vendida; i++) {
            printf("Digite o valor do carro %d: ", i + 1);
            scanf("%f", &valores[i]);
            soma += valores[i];
        }

        abono = 0.05 * soma;
        salario_total = salario_base + comissao + abono;

        // Relatório
        printf("\n--- Relatório do Vendedor ---\n");
        printf("Nome: %s\n", nome);
        printf("Carros vendidos: %d\n", quantidade_vendida);
        printf("Total de vendas: R$ %.2f\n", soma);
        printf("Salário total: R$ %.2f\n", salario_total);

    } else {
        printf("Ok. Nenhuma venda registrada.\n");
    }

    return 0;
}
