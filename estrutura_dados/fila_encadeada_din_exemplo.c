#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do carro
typedef struct {
    char modelo[50];
    int ano;
    char placa[10];
} Carro;

// Nó da pilha
typedef struct No {
    Carro carro;
    struct No* prox;
} No;

// Topo da pilha
No* topo = NULL;

// Função para remover \n do fgets
void removerEnter(char* str) {
    str[strcspn(str, "\n")] = '\0';
}

// PUSH
void push() {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    char buffer[50];

    printf("Modelo: ");
    fgets(novo->carro.modelo, 50, stdin);
    removerEnter(novo->carro.modelo);

    printf("Ano: ");
    fgets(buffer, 50, stdin);
    novo->carro.ano = atoi(buffer); // converte string para int

    printf("Placa: ");
    fgets(novo->carro.placa, 10, stdin);
    removerEnter(novo->carro.placa);

    // lógica da pilha
    novo->prox = topo;
    topo = novo;

    printf("Carro cadastrado!\n");
}

// POP
void pop() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    No* temp = topo;
    topo = topo->prox;

    printf("\nRemovido:\n");
    printf("Modelo: %s\n", temp->carro.modelo);
    printf("Ano: %d\n", temp->carro.ano);
    printf("Placa: %s\n", temp->carro.placa);

    free(temp);
}

// LISTAR
void listar() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    No* atual = topo;

    printf("\n--- Carros ---\n");
    while (atual != NULL) {
        printf("Modelo: %s\n", atual->carro.modelo);
        printf("Ano: %d\n", atual->carro.ano);
        printf("Placa: %s\n", atual->carro.placa);
        printf("----------------\n");

        atual = atual->prox;
    }
}

// MENU
int main() {
    char opcaoStr[10];
    int opcao;

    do {
        printf("\n1 - Cadastrar\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        fgets(opcaoStr, 10, stdin);
        opcao = atoi(opcaoStr);

        switch (opcao) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                listar();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}