#include <stdio.h>
#include <string.h>

int main()
{
    char nomeCompleto[50];
    int tamanhoString;

    printf("Digite seu nome: \n");
    fgets(nomeCompleto, 50, stdin);
    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    tamanhoString = strlen(nomeCompleto);

    printf("Nome: %s\n", nomeCompleto);
    printf("Tamanho String: %d", tamanhoString);

    return 0;
}