#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int pilha[TAM];
int topo = -1; //define pilha vazia 

void push(int senha);
void pop();
void listar();

int main() {

    push(1);
    push(2);
    push(3);

    listar();

    pop();

    listar();

    return 0;
}

void push(int senha){

    if(topo == TAM - 1){
        printf("Pilha cheia!\n");
        return;
    }

    topo++;
    pilha[topo] = senha;

    printf("Pessoa com senha %d colocada no TOPO.\n", senha);
}

void pop(){

    if(topo == -1){
        printf("Pilha vazia!\n");
        return;
    }

    printf("Senha %d foi retirada\n", pilha[topo]);

    topo--;
}

void listar(){

    if(topo == -1){
        printf("Pilha vazia!\n");
        return;
    }

    printf("\n--- Status da Pilha ---\n");

    for(int i = topo; i >= 0; i--){
        printf("[Senha: %d]\n", pilha[i]);
        if(i != 0){
            printf("    |\n");
            printf("    V\n");
        }
    }

    printf("--- Base da Pilha ---\n\n");
}