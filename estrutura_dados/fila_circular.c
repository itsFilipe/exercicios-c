#include <stdlib.h>
#include <stdio.h>

struct fila
{
    int capacidade;
    int *dados;
    int primeiro;
    int ultimo;
    int nItens;
};

//FIFO: First In, First Out 

void criarFila(struct fila *f, int cap);
void enfileirar(struct fila *f, int num);
void desenfileirar(struct fila *f);
void mostrarFila(struct fila *f);

int main(){
	int op;
	struct fila minhaFila;

	printf("Digite a capacidade da fila: ");
	scanf("%d", &minhaFila.capacidade);
	criarFila(&minhaFila, minhaFila.capacidade);

	printf("Fila criada com capacidade de %d\n", minhaFila.capacidade);

	while(op != 4)
	{
		printf("1 - Enfileirar\n");
		printf("2 - Desenfileirar\n");
		printf("3 - Mostrar fila\n");
		printf("4 - Sair\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1: //enfileirar
			printf("Digite um numero para enfileirar: ");
			int num;
			scanf("%d", &num);
			enfileirar(&minhaFila, num);
			break;

		case 2: //desenfileirar
			printf("Desenfileirando...\n");
			desenfileirar(&minhaFila);
			break;

		case 3: //mostrar fila
			mostrarFila(&minhaFila);
			break;
		
		case 4: //sair	
			printf("Saindo...\n");
			break;
		
		default:
			printf("Opcao invalida\n");
			break;
		}
	}

	free(minhaFila.dados);
	printf("Memoria liberada para a fila foi liberada\n");

    return 0;
}

void criarFila(struct fila *f, int cap){
    f->capacidade = cap;
    f->dados = (int*) malloc (f->capacidade * sizeof(int));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;

    printf("Fila iniciada\n");
}

void enfileirar(struct fila *f, int num){
    if(f->capacidade == f->nItens)
    {
        printf("Fila esta cheia\n");
        return;
    }
        
    //f->ultimo++;
    f->ultimo = (f->ultimo + 1) % f->capacidade;
	/* ou
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;
	*/

    f->dados[f->ultimo] = num;

    f->nItens++;
    
    printf("Numero %d foi inserido no final da fila, indice %d\n", num, f->ultimo);
}

void desenfileirar(struct fila *f){
    if(f->nItens == 0)
    {
        printf("Fila esta vazia\n");
        return;
    }

    int numAux = f->dados[f->primeiro];
    f->dados[f->primeiro] = 0;
    //f->primeiro++;
    f->primeiro = (f->primeiro + 1) % f->capacidade;
	/* ou
		if(f->primeiro == f->capacidade)
		f->primeiro = 0;
	*/

    f->nItens--;

    printf("Numero %d saiu da fila, indice se tornou %d\n", numAux, f->primeiro);
}

void mostrarFila(struct fila *f){
	int cont, i;

	printf("\nFila: ");

	for ( cont=0, i = f->primeiro; cont < f->nItens; cont++){
		printf("%d ",f->dados[i++]);

		if (i == f->capacidade)
			i=0;
	}
	printf("\n\n");
}