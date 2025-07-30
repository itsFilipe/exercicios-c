//Lança um dado de 6 lados n vezes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7
#define TIMES 6000

int main()
{
    int face;  /* valor aleatório de 1 - 6 do dado */
    int roll; /* contador de lancamentos de 1-6000 */
    int frequencia[ SIZE ] = { 0 }; /* limpa contadores */

    srand( time( NULL ) ); /* seed de random numbers */

    /* rola dado TIMES vezes */

    for (roll = 1; roll <= TIMES; roll++)
    {
        face = 1 + rand() % 6;
        ++frequencia[ face ];
    }
    
    printf( "%s%17s\n", "Face", "Frequencia" );

    for (face = 1; face < SIZE; face++)
    {
        printf( "%4d%17d\n", face, frequencia[ face ]);
    }
    
    return 0;
}

