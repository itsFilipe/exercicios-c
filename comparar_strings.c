#include <stdio.h>
#include <string.h>

int main()
{
    char senha[6] = "12345";
    char login[6];

    printf("Digite sua senha, maximo 5 numeros: \n");

    fgets(login, 6, stdin);
    login[strcspn(login, "\n")] = '\0';

    if( strcmp(senha, login) == 0 )
    {
        printf("Senha correta!\n");
    }
    else
    {
        printf("Senha incorreta!\n");
    }

    return 0;
}