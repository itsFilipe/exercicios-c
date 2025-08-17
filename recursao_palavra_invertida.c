#include <stdio.h>

void reverse(const char * const stringPonteiro);

int main(void)
{
    char frase[80]; 

    printf("Digite uma linha de texto:\n");
    fgets(frase, 80, stdin);

    printf("\nA linha impressa na ordem inversa e:\n");
    reverse(frase);

    return 0;
}

void reverse(const char * const stringPonteiro)
{
    if( stringPonteiro[0] == '\0')
    {
        return;
    }
    else
    {
        reverse(&stringPonteiro[1]);
        putchar(stringPonteiro[0]);
    }
}