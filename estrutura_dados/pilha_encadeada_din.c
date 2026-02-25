#include <stdio.h>
#include <stdlib.h>

struct pessoa {
    int senha;
    struct pessoa* prox;
};

typedef struct pessoa Pessoa; //isso é apenas um apelido para o struct pessoa, para evitar de escrever struct toda hora

Pessoa* topo = NULL;

void push(int senha);
void pop();
void listar(); 

int main() {
    // Inserindo elementos na pilha
    push(1); // Entra primeiro, vai ficar na base
    push(2); // Fica no meio
    push(3); // Entra por último, fica no TOPO

    // Mostra a pilha
    listar();

    // Remove o elemento do TOPO (O último que entrou: 3)
    pop();

    // Mostra a pilha novamente para ver o resultado
    listar();

    return 0;
}

void push(int senha){
    Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));

    novo->senha = senha;

    //agora o antigo topo é o proximo
    novo->prox = topo;

    //e o topo, é o novo

    topo = novo;

    printf("Pessoa com senha %d colocada no TOPO da pilha.\n", senha);
}


void pop(){
    /*
        O pop é bem simples, primeiro confere se está vazio,
        utiliza variavel aux p guardar o topo,
        apos isso o topo vira o proximo
        e tem que liberar a maemoria do aux
    */


    if(topo == NULL){
        printf("Pilha vazia!\n");
    }

    Pessoa* aux;

    aux = topo;

    topo = topo->prox;

    printf("Senha %d foi retirada\n", aux->senha);

    free(aux);
}

void listar() {
    Pessoa *aux = topo;
    printf("\n--- Status da Pilha (Do TOPO para a BASE) ---\n");
    
    // Percorre do topo até chegar no fim (NULL)
    while (aux != NULL) {
        printf("[Senha: %d]\n", aux->senha);
        if (aux->prox != NULL) {
            printf("    |\n");
            printf("    V\n");
        }
        aux = aux->prox;
    }
    printf("--- Fim (Base da Pilha) ---\n\n");
}

//Como você faria uma pilha dinâmica com limite máximo?