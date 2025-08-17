#include <stdio.h>
#include <string.h>

int main()
{
    char primeiroNome[50], segundoNome[50];

    fgets(primeiroNome, 50, stdin);
    fgets(segundoNome, 50, stdin);

    primeiroNome[strcspn(primeiroNome, "\n")] = '\0';
    segundoNome[strcspn(segundoNome, "\n")] = '\0';
    strcat(primeiroNome, segundoNome);

    for(int i = 0 ; primeiroNome[i] != '\0'; i++)
    {
        printf("%c", primeiroNome[i]);
    }

    return 0;
}