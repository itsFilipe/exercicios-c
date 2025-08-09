#include <stdio.h>

int main()
{
    printf("N\t10*N\t100*N\t1000*N\n");

    for (int i = 1; i < 11; i++)
    {
        printf("%i\t%i\t%i\t%i", i, i * 10, i * 100, i * 1000);
        printf("\n");
    }
    
    return 0;
}