#include <stdio.h>
#include <stdbool.h>

#define MAX 5

// Estrutura de cada Nó no array
typedef struct No {
    int valor;
    struct No* prox; // Ponteiro real para o próximo nó na memória
} No;

// Estrutura da Fila
typedef struct {
    No* frente;     // Aponta para o endereço do primeiro elemento
    No* tras;       // Aponta para o endereço do último elemento
    No dados[MAX];  // Espaço de memória pré-alocado (estático)
    int tamanho;    // Controle de ocupação
} FilaCircular;

// Inicializa a estrutura e define as conexões circulares fixas
void inicializar(FilaCircular* f) {
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;

    // Configura os ponteiros 'prox' para formar o anel no array
    for (int i = 0; i < MAX; i++) {
        f->dados[i].valor = 0;
        if (i < MAX - 1) {
            f->dados[i].prox = &f->dados[i + 1]; // Aponta para o vizinho
        } else {
            f->dados[i].prox = &f->dados[0];     // O último aponta para o primeiro
        }
    }
}

bool estaCheia(FilaCircular* f) {
    return f->tamanho == MAX;
}

bool estaVazia(FilaCircular* f) {
    return f->tamanho == 0;
}

// Inserção: Move o ponteiro 'tras' para o próximo endereço do anel
void enfileirar(FilaCircular* f, int v) {
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }

    if (estaVazia(f)) {
        f->frente = &f->dados[0];
        f->tras = &f->dados[0];
    } else {
        // Move o 'tras' para o endereço guardado no campo 'prox' do nó atual
        f->tras = f->tras->prox;
    }

    f->tras->valor = v;
    f->tamanho++;
}

// Remoção: Simplesmente move o ponteiro 'frente' para o próximo endereço
int desenfileirar(FilaCircular* f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }

    int v = f->frente->valor;
    
    if (f->frente == f->tras) { // Era o último elemento
        f->frente = NULL;
        f->tras = NULL;
    } else {
        f->frente = f->frente->prox; // Avança para o próximo endereço
    }

    f->tamanho--;
    return v;
}

void exibir(FilaCircular* f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    No* temp = f->frente;
    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        printf("[%d] ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    FilaCircular minhaFila;
    inicializar(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    exibir(&minhaFila);

    printf("Removido: %d\n", desenfileirar(&minhaFila));
    exibir(&minhaFila);

    enfileirar(&minhaFila, 40);
    enfileirar(&minhaFila, 50);
    enfileirar(&minhaFila, 60); // Deve ocupar a posição circular no array
    exibir(&minhaFila);

    return 0;
}
