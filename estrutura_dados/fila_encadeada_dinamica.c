#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FIFO, First in, First out, primeiro a entrar, primeiro a sair

typedef struct no {
    char pessoa[20];
    struct no* proximo;
} no ;

typedef struct {
    no* primeiro;
    no* ultimo;
} fila ; 

void inicia_fila(fila* f);
void enfileirar(fila* f, char* nome); 
void desenfileirar(fila* f);
void listar_fila(fila* f);

int main(){
    fila fila_banco;
    inicia_fila(&fila_banco);

    printf("\nSeja bem vindo a fila do Banco.\n\n");

    enfileirar(&fila_banco, "Ana Livia");
    enfileirar(&fila_banco, "Thiago");
    enfileirar(&fila_banco, "Bianka");

    listar_fila(&fila_banco);

    desenfileirar(&fila_banco);
    desenfileirar(&fila_banco);

    listar_fila(&fila_banco);

    return 0;
}

void inicia_fila(fila* f){
    f->primeiro = NULL;
    f->ultimo   = NULL;
}

void enfileirar(fila* f, char* nome){ 
    no* novo_elemento = (no*) malloc(sizeof(no));     

    strcpy(novo_elemento->pessoa, nome);
    novo_elemento->proximo = NULL;
   
    if(f->primeiro == NULL){ //vazia
        f->primeiro = novo_elemento;
        f->ultimo   = novo_elemento;
    } else {                //ja tem
        f->ultimo->proximo = novo_elemento;
        f->ultimo = novo_elemento; 
    }

    printf("%s entrou na fila.\n", nome);
} 

void desenfileirar(fila* f){
    if(f->primeiro == NULL){ 
        printf("A fila esta vazia.\n");
        return;
    }

    no* temp = f->primeiro; 
    printf("%s foi atendido(a).\n", temp->pessoa);
    f->primeiro = f->primeiro->proximo; 

    if(f->primeiro == NULL) { 
        f->ultimo = NULL;
    }

    free(temp); 
}

void listar_fila(fila* f) {
    if (f == NULL || f->primeiro == NULL) {
        printf("Fila esta vazia.\n");
        return;
    }

    no* atual = f->primeiro;

    int cont = 0;
    while (atual != NULL) { 
        cont++;
        atual = atual->proximo;
    }

    atual = f->primeiro;

    printf("\n");
    if(cont > 1){
        printf("No momento %d pessoas estao no aguardo.\n", cont);
    } else {
        printf("No momento %d pessoa esta no aguardo.\n", cont);
    }
    
    while (atual != NULL) {
        printf("--> ");
        printf("%s ", atual->pessoa);
        atual = atual->proximo;
    }
    printf("\n\n");
}



