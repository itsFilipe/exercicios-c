#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100

 typedef struct
    {
        char titulo[127];
        int ano;
    } Livro;

void add_livro(Livro *b);
void print_livro(Livro b);

int main()
{
    Livro biblioteca[MAX_LIVROS];
    int sentinela, contador = 0;

    while (contador < MAX_LIVROS)
    {
        add_livro(&biblioteca[contador]);
        
        printf("Deseja continuar? Digite 1 para sair ou outro numero para continuar\n");
        scanf("%d", &sentinela);
        getchar(); //tira o enter do buffer

        contador++;

        if(sentinela == 1)
        {
            break;
        };
    };

    if (contador == MAX_LIVROS)
    {
        printf("Limite de cadastro atingido!\n");
    } 
    else
    {
        printf("Programa finalizado pelo usuario...\n");
    }

    for (int i = 0; i < contador; i++)
    {
        printf("Livro %d:\n", i+1);
        print_livro(biblioteca[i]);
        printf("\n");
    }
    
    printf("Foram lidos %d livros\n", contador);

    return 0;
}

void add_livro(Livro *b)
{
    char buffer[50]; // para ler o ano como string

    printf("Digite o titulo do livro: \n");
    fgets(b->titulo, sizeof(b->titulo), stdin);
    b->titulo[strcspn(b->titulo, "\n")] = '\0';  // remove o \n do final

    printf("Digite o ano do livro: \n");
    fgets(buffer, sizeof(buffer), stdin);
    b->ano = (int)strtol(buffer, NULL, 10);  // converte string -> int

    printf("Livro adicionado com sucesso!\n");
}

void print_livro(Livro b)
{   
    printf("-----------------------------\n");
    printf("Nome: %s\n", b.titulo);
    printf("Ano: %d\n", b.ano);
    printf("-----------------------------\n");
}