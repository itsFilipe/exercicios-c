#include <stdio.h>
#include <string.h>

int main()
{
    char nomeCompleto[15];
    char nomeCompletoCopia[15];

    printf("Digite seu nome: \n");
    fgets(nomeCompleto, 15, stdin);

    strcpy(nomeCompletoCopia, nomeCompleto);

    printf("\nString original: %s\n", nomeCompleto);
    printf("String copia: %s\n", nomeCompletoCopia);

    return 0;
}