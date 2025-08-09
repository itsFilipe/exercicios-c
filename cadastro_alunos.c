#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

int main() {

    int n;

    printf("Digite a quantidade de alunos: \n");
    scanf("%i", &n);

    getchar();

    struct Aluno alunos[n];

    // Entrada de dados
    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;  // remove o \n

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;

        getchar(); // limpa o \n após scanf
    }

    // Saída de dados
    printf("\n====== BOLETIM ======\n");
    for (int i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome : %s\n", alunos[i].nome);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("Média : %.2f\n", alunos[i].media);
    }

    return 0;
}
