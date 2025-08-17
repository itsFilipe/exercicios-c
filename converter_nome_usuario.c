#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nome[50];
    char sobrenome[50];
    char userName[50];

    printf("Digite seu nome:\n");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite seu sobrenome:\n");
    fgets(sobrenome, sizeof(sobrenome), stdin);

    nome[strcspn(nome, "\n")] = '\0';
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    userName[0] = tolower(nome[0]);
    userName[1] = '\0';

    strcat(userName, sobrenome);

    for(int i = 0; userName[i] != '\0'; i++) {
        userName[i] = tolower(userName[i]);
    }

    printf("Nome do usuario convertido: %s\n", userName);

    return 0;
}