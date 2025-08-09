#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct alunos
{
    char nome[50];
    float altura;
    int idade;
};

int main()
{
    struct alunos Menina;
    struct alunos Menino;

    printf("Nome: ");
    fgets(Menina.nome, sizeof(Menina.nome), stdin);
    Menina.nome[strcspn(Menina.nome, "\n")] = 0;  // remove o \n

    printf("Altura: ");
    scanf("%f", &Menina.altura);

    printf("Idade: ");
    scanf("%i", &Menina.idade);

    getchar(); // limpa o \n após scanf

    printf("Nome: ");
    fgets(Menino.nome, sizeof(Menino.nome), stdin);
    Menino.nome[strcspn(Menino.nome, "\n")] = 0;  // remove o \n

    printf("Altura: ");
    scanf("%f", &Menino.altura);

    printf("Idade: ");
    scanf("%i", &Menino.idade);

    printf("Nome: %s\n", Menina.nome);
    printf("Altura: %f\n", Menina.altura);
    printf("Idade: %i\n\n", Menina.idade);

    printf("Nome: %s\n", Menino.nome);
    printf("Altura: %f\n", Menino.altura);
    printf("Idade: %i\n", Menino.idade);

    return 0;
}