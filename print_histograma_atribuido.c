#include <stdio.h>

int main()
{   
    int valores[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um numero entre 1 e 30, valor %i: ", i+1);
        scanf("%d", &valores[i]);
    }

    for (int i = 0; i < 5 ; i++)
    {
        for (int j = 0; j < valores[i]; j++)
        {
            printf("*");
        }
        
        printf("\n");
    }

    return 0;
}