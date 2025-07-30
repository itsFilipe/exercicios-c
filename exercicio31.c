/* jogo de adivinhar numero entre 1 a 100 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL)); /*seed muda a cada execução*/

    int numeroSorteado, numeroEscolhido, contador = 0;

    numeroSorteado = rand() % 100 + 1;

    printf("Numero escolhido, tente acertar!\n");
    
    do
    {
        printf("Escolha um numero: ");
        scanf("%d", &numeroEscolhido);

        if (numeroEscolhido > numeroSorteado)
        {
            printf("Muito alto\n");
        }
        else if(numeroEscolhido == numeroSorteado)
        {
            printf("Parabens, voce acertou!\n");
        }
        else
        {
            printf("Muito baixo\n");
        }

        contador++;
        
    } while (numeroEscolhido != numeroSorteado);

    printf("Numero de tentativas %d", contador);
    
    return 0;
}