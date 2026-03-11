#include <stdio.h>
#include <stdlib.h>

/*
    Lista encadeada simples
    Cada nó aponta para o próximo
*/

typedef struct no {
    int n;                 // dado armazenado no nó
    struct no* proximo;    // ponteiro para o próximo nó
} no;

/* protótipos das funções */
void inicia_lista(no** l);
void inserir(no** l, int valor);
void mostrar(no* l);

int main(){

    no* lista;             // ponteiro para o primeiro nó da lista

    inicia_lista(&lista);  // inicializa lista vazia

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);

    mostrar(lista);

    return 0;
}

/* inicializa a lista */
void inicia_lista(no** l){
    *l = NULL;             // lista começa vazia
}

/* inserir elemento no final da lista */
void inserir(no** l, int valor){

    // cria novo nó na memória
    no* novo = (no*) malloc(sizeof(no));

    novo->n = valor;       // guarda o valor
    novo->proximo = NULL;  // novo nó será o último

    // caso 1: lista vazia
    if(*l == NULL){
        *l = novo;
        return;
    }

    // caso 2: lista já possui elementos
    no* aux = *l;

    // percorre até o último nó
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    // conecta o último nó ao novo
    aux->proximo = novo;
}

/* imprime lista */
void mostrar(no* l){

    no* aux = l;

    while(aux != NULL){
        printf("%d -> ", aux->n);
        aux = aux->proximo;
    }

    printf("NULL\n");
}